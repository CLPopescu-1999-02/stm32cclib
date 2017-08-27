project (stm32f4-black CXX)
cmake_minimum_required(VERSION 3.5.0)

add_definitions(-DSTM32F4XX)

set(DEVICE stm32f4xx)
set(BOARD stm32f4-black)

include(CMakeForceCompiler)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

set(CROSS_PREFIX armv7a-hardfloat-linux-gnueabi-)

cmake_force_cxx_compiler(${CROSS_PREFIX}g++ GNU)

set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/stm32f407e_flash.ld)
set(COMMON_FLAGS "-g -mlittle-endian -mthumb -nostdlib -DTHUMB -fno-common -mno-thumb-interwork")
set(WARN_FLAGS "-Wall -Wextra")
set(OPTIMIZE_FLAGS "-ffreestanding -fomit-frame-pointer")
set(CPU_FLAGS "-mcpu=cortex-m4")

set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} ${WARN_FLAGS} ${OPTIMIZE_FLAGS} ${CPU_FLAGS} -std=c++11 -fno-rtti -fno-exceptions")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-T ${LINKER_SCRIPT} -nostartfiles")

# utilities
set(OBJCOPY ${CROSS_PREFIX}objcopy)
set(OBJDUMP ${CROSS_PREFIX}objdump)
set(SIZE ${CROSS_PREFIX}size)

set(ST_UTILS_PATH /home/nis/old_frame/stm32/stlink)
set(ST_FLASH ${ST_UTILS_PATH}/st-flash)

# library base directory
set(STM32CXXLIB_DIR ../..)

file(GLOB_RECURSE EXAMPLE_SOURCES "src/*.cc")
file(GLOB_RECURSE STM32CCLIB
    "${STM32CXXLIB_DIR}/src/core/isr_base.cc"
    "${STM32CXXLIB_DIR}/src/device/${DEVICE}/isr_extend.cc"
    "${STM32CXXLIB_DIR}/src/reset.cc"
)

include_directories(include)
# Options for include platform specific header files
include_directories(${STM32CXXLIB_DIR}/include)
# Options for include core specific header files
include_directories(${STM32CXXLIB_DIR}/include/core/)
# Options for include device specific header files
include_directories(${STM32CXXLIB_DIR}/include/device/${DEVICE})

add_executable(${PROJECT_NAME}.elf ${EXAMPLE_SOURCES} ${STM32CCLIB})

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_NAME}.map"
)
set(BIN_FILE ${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMENT "BUILDING ${BIN_FILE}"
    COMMAND ${OBJDUMP} -DS $<TARGET_FILE:${PROJECT_NAME}.elf> > ${PROJECT_NAME}.elf.dis
    COMMENT "CREATING ${PROJECT_NAME}.elf.dis"
    COMMAND ${SIZE} $<TARGET_FILE:${PROJECT_NAME}.elf>
)

add_custom_target(write DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin COMMAND ${ST_FLASH} write ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin 0x8000000)
