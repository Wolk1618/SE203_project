PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)gcc

CFLAGS = -g -O1 -ffreestanding
TARGET_ARCH = -mthumb -mcpu=cortex-m4
ASFLAGS = -g
TARGET_MACH = $(TARGET_ARCH)

LDFLAGS = -nostdlib -T ld_rams.lds
LDLIBS = 

EXE  = exec.elf
OBJS = test.o init.o crt0.o


.PHONY : connect clean all

all : $(EXE)

connect : 
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

$(EXE) : $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@


clean :
	rm -f $(OBJS)
	rm -f $(EXE)
