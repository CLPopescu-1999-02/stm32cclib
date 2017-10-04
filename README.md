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
    8.1) stm32f4xx family
        8.1.1) stm32f405,407,415,417 full support (exclude usb hs)
9) Middle lelev template style and helpers to simplified operations with hardware.
    9.1) Interrupts
    9.2) Systick
    9.3) GPIO
    9.4) EXTI
    9.5) USART
10) BSP to simplified operation with hardware modules
    10.1) stm32l152c-discovery 6 position hex digit lcd
    10.2) ssd1306 graphic 128x64 oled
11) Examples proto
    11.1) stm32l152c-disco - demo for full use internal blocks of stm32l152c
    11.2) stm32f3disco - blinking leds, usart rx/tx demo
    11.3) stm32f4-black - blinking leds, usart rx/tx demo, ssd1306 oled demo
