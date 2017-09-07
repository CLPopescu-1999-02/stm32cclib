This is C++11 based library and HAL for STM32

It include:

1) CMake build system for simplifier create, build and upload to target
2) Linker script to separate and simplified your code.
3) Vector table for Cortex-M3,4 for simplified create interrupt handers.
4) Startup code for Cortex-M3,4 cpu with initialization of data & bss sections.
5) Setup C++ static objects
6) Template library and types for stm32 mcus.
7) Prototype of startup and run code for stm32 mcus.
8) Low level template style defines and helpers to commonize work with hardware.
    1) RCC
    2) GPIO
    3) PWR
    4) LCD
    5) TIM
    6) RTC
    7) EXTI
    8) ADC
    9) DMA
    10) USART
    11) Core structures & interrupts
    12) Device structures & interrups
9) High lelev template style and helpers to simplified operations with hardware.
    1) Interrupts
    2) Systick
    3) GPIO
    4) EXTI
    5) USART
10) stm32l152c-discovery hex lcd bsp to simplified operation with hardware modules
11) stm32l152c-disco, stm32f3disco, stm32f4-black examples proto
