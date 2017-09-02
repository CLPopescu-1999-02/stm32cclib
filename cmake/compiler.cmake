include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TARGET_TRIPLET "armv7a-hardfloat-linux-gnueabi")
set(TOOLCHAIN_PREFIX "/usr")

set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_PREFIX}/bin)
set(TOOLCHAIN_INC_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/include)
set(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/lib)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)

set(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-g++)
set(CROSS_PREFIX ${TARGET_TRIPLET}-)

set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/stm32_flash.ld)
set(COMMON_FLAGS "-g -mlittle-endian -mthumb -nostdlib -DTHUMB -fno-common -mno-thumb-interwork")
set(WARN_FLAGS "-Wall -Wextra")
set(OPTIMIZE_FLAGS "-ffreestanding -fomit-frame-pointer")

set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} ${WARN_FLAGS} ${OPTIMIZE_FLAGS} ${CPU_FLAGS} -std=c++11 -fno-rtti -fno-exceptions" CACHE INTERNAL "cxx compiler flags")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-T ${LINKER_SCRIPT} -nostartfiles")

# utilities
set(OBJCOPY ${CROSS_PREFIX}objcopy)
set(OBJDUMP ${CROSS_PREFIX}objdump)
set(SIZE ${CROSS_PREFIX}size)

set(ST_UTILS_PATH /home/nis/old_frame/stm32/stlink)
set(ST_FLASH ${ST_UTILS_PATH}/st-flash)

function (SETUP_TARGET_PROPERTIES TARGET)
    set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${TARGET}.map"
    )
    set(BIN_FILE ${TARGET}.bin)

    add_custom_command(TARGET ${TARGET}.elf POST_BUILD
        COMMAND ${OBJCOPY} -Obinary $<TARGET_FILE:${TARGET}.elf> ${BIN_FILE}
        COMMENT "BUILDING ${BIN_FILE}"
        COMMAND ${OBJDUMP} -DS $<TARGET_FILE:${TARGET}.elf> > ${TARGET}.elf.dis
        COMMENT "CREATING ${TARGET}.elf.dis"
        COMMAND ${SIZE} $<TARGET_FILE:${TARGET}.elf>
    )

    add_custom_target(write DEPENDS ${CMAKE_BINARY_DIR}/${TARGET}.bin COMMAND ${ST_FLASH} write ${CMAKE_BINARY_DIR}/${TARGET}.bin 0x8000000)
endfunction()
