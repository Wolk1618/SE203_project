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
OBJS = main.o led.o init.o crt0.o memfunc.o
DEPS = $(patsubst %.o , %.dep, $(OBJS))


.PHONY : connect clean all

all : $(EXE)

connect : 
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

$(EXE) : $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

.%.dep : %.c
	$(CC) -MM $< -MF $@

clean :
	rm -f $(OBJS)
	rm -f $(EXE)
