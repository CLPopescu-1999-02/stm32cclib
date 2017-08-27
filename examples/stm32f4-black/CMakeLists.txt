project (stm32f4-black CXX)
cmake_minimum_required(VERSION 3.5.0)

add_definitions(-DSTM32F4XX)

set(DEVICE stm32f4xx)
set(BOARD stm32f4-black)

# library base directory
set(STM32CXXLIB_DIR ../..)

include(${STM32CXXLIB_DIR}/cmake/compiler.cmake)

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

SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME})
