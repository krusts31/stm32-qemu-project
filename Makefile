MCU = atmega168
F_CPU = 16000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=$(F_CPU)

all: main.hex

main.o: main.c
	$(CC) $(CFLAGS) -o $@ -c $<

main.elf: main.o
	$(CC) -mmcu=$(MCU) -o $@ $<

main.hex: main.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

clean:
	rm -f main.o main.elf main.hex

.PHONY: all clean
