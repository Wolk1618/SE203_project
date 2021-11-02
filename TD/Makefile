PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)gcc

CFLAGS = -g -O2 -ffreestanding -Wall -Wextra -Werror
#CFLAGS = -g -O2 -ffreestanding -mfloat-abi=hard -Wall -Wextra -Werror
TARGET_ARCH = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 
ASFLAGS = -g
TARGET_MACH = $(TARGET_ARCH)

LDFLAGS = -nostdlib -T ld_rams.lds
LDLIBS = 

EXE  = exec.elf
OBJS = main.o led.o init.o crt0.o memfunc.o clocks.o uart.o matrix.o image.o
RM_OBJS = main.o led.o init.o crt0.o memfunc.o uart.o matrix.o
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
	rm -f $(RM_OBJS)
	rm -f $(EXE)
