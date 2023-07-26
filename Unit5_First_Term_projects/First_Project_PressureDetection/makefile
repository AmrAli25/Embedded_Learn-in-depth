#@Editor: Amr Ali Ahmed

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
AS=$(wildcard *.s) 
ASOBJ=$(AS:.s=.o)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
project_name=pressure_detection


all: $(project_name).bin
	@echo "=========Build is Done========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld  $(LIBS) $(OBJ) $(ASOBJ)  -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean:
	rm *.bin *.elf *.Map
clean_all:
	rm *.o *.elf *.bin *.elf.asm *.map