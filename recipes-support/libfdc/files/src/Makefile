
# CC=mips-mti-elf-gcc
# LD=mips-mti-elf-gcc
# OD=mips-mti-elf-objdump
# OC=mips-mti-elf-objcopy
# SZ=mips-mti-elf-size
# AR=mips-mti-elf-ar -cru

CFLAGS = -Wall -O3 -g -nostdlib -EL -msoft-float -c -march=m14kc

CSOURCES= \
	fdc_putchar.c \
	fdc_printf.c
COBJECTS=$(CSOURCES:.c=.o)

.PHONY: all

all: FDC_LIB # MAIN

MAIN :
	$(CC) -O3 -g -nostdlib -msoft-float -EL -Wl,-Ttext=0xa0000000 main.c start.S fdc_lib.a -o main.elf

FDC_LIB :  $(COBJECTS) 
	$(AR) -cru libfdc.a fdc_putchar.o fdc_printf.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f libfdc.a
	rm -f main.elf
	rm -f *.o

