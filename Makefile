# ================== Setup thong so ==================
MCU        = atmega328p
F_CPU      = 8000000UL
CC         = avr-gcc
OBJCOPY    = avr-objcopy
SIZE       = avr-size

# ================== Folder ==================
SRC_DIR    = Src
DRV_DIR    = Driver
BUILD_DIR  = Build

# ================== Target ==================
TARGET     = $(BUILD_DIR)/main

# ================== List all file .c trong Src va Driver ==================
SRCS       = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(DRV_DIR)/*.c)
OBJS       = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))
VPATH      = $(SRC_DIR):$(DRV_DIR)

# ================== Compiler Flags ==================
CFLAGS     = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11
CFLAGS    += -I$(SRC_DIR) -I$(DRV_DIR)
CFLAGS    += -ffunction-sections -fdata-sections
LDFLAGS    = -mmcu=$(MCU) -Wl,--gc-sections

# ================== COMMAND ==================
all: 
$(TARGET).hex size

# Link file .elf tu cac .o
$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Bien dich tung file .c thanh .o, dat trong Build 
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Tao thu muc Build neu chua co
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Xuat file .hex tu .elf
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# ================== Hien thi dung luong flash/ram da dung ==================
size: $(TARGET).elf
	$(SIZE) --format=avr --mcu=$(MCU) $<

# ================== Nap chuong trinh qua avrdude ==================
# Chinh lai PROGRAMMER / PORT / BAUD cho dung mach nap ban dang dung
PROGRAMMER = arduino
PORT       = /dev/ttyUSB0
BAUD       = 115200

flash: $(TARGET).hex
	avrdude -c $(PROGRAMMER) -p m328p -P $(PORT) -b $(BAUD) -U flash:w:$<:i

# ================== Don dep ==================
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean flash size