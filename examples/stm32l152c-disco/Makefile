## - full automatic environment to build binary

# Platform prefix for cross build utils
CROSS_PREFIX = armv7a-hardfloat-linux-gnueabi-

# Compilators and utils
# basic features to build system
CC = $(CROSS_PREFIX)gcc
CXX = $(CROSS_PREFIX)g++
LD = $(CROSS_PREFIX)gcc
OBJCOPY = $(CROSS_PREFIX)objcopy
OBJDUMP = $(CROSS_PREFIX)objdump
# optional: user frendly needed
SIZE = $(CROSS_PREFIX)size
#ST-Utils for flash and erase devices
ST_UTILS_PATH = /home/nis/old_frame/stm32/stlink/
ST_FLASH = $(ST_UTILS_PATH)st-flash
# LIBRARY discen
STM32CXXLIB_DIR=../../
DEVICE=stm32l1xx

# user defined sources
CXXSRCS = \
	$(STM32CXXLIB_DIR)src/bsp/st_hex_lcd.cc \
	$(STM32CXXLIB_DIR)src/core/isr_base.cc \
	$(STM32CXXLIB_DIR)src/device/$(DEVICE)/isr_extend.cc \
	$(STM32CXXLIB_DIR)src/reset.cc \
	src/runner.cc

OBJS=$(CXXSRCS:.cc=.o)

# Platform
# because I use stm32l152c-discovery board now
# I think this need classify change for differnt chips and boards
PLATFORM = stm32l152c-discovery

# Options for compile source for C and C++ compiler
# basic options for mcu compile
CFLAGS = -g -mlittle-endian -mthumb -nostdlib -DTHUMB -fno-common -mno-thumb-interwork
# warning options for compile correct code
CFLAGS += -Wall -Wextra
# optimize options - I think this need to check in real applications
CFLAGS += -ffreestanding -fomit-frame-pointer
# controller specific options - for future project this link with PLATFORM option
CFLAGS += -mcpu=cortex-m3 -DSTM32l1XX

# Options for include header files
CFLAGS += -Iinclude
CFLAGS += -I$(STM32CXXLIB_DIR)include
# Options for include core header files
CFLAGS += -I$(STM32CXXLIB_DIR)include/core/
# Options for include device header files
CFLAGS += -I$(STM32CXXLIB_DIR)include/device/$(DEVICE)

# Options for compile source for C++ compiler
CXXFLAGS = $(CFLAGS)
# Use current worked version of C++ - C++11
CXXFLAGS += -std=c++11
# In current implementation we can't use rtti and exceptions
CXXFLAGS += -fno-rtti -fno-exceptions

# Linker flags
LDFLAGS = $(CFLAGS)
# Path to search objects and libraries
LDFLAGS += -L.
# Linker script and disable start files - for future project this link with PLATFORM option
LDFLAGS += -Wl,-T,stm32l152c_flash.ld -nostartfiles

# main project file
all: firmware.bin

# Making binary firmware file and user readed debug files
firmware.bin: firmware.elf
	$(OBJCOPY) -O binary $^ $@
	$(SIZE) $^
	$(OBJDUMP) -DS $^ > $^.dis

# Making elf
firmware.elf: $(OBJS)
	$(LD) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Making object
%.o: $.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

# Cleaning project
clean:
	rm -f firmware.elf firmware.bin $(OBJS)

# Write project to target device with st-utils
write:
	$(ST_FLASH) write firmware.bin 0x8000000
	$(ST_FLASH) reset
