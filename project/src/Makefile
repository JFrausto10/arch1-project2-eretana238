# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mcpu=msp430 --traditional-format -mP

all: play.elf 

#additional rules for files
play.elf: ${COMMON_OBJECTS} main.o stateMachines.o led.o wdInterruptHandler.o switches.o stateMachines.o p1_interrupt_handler.o buzzer.o soundEngine.o set_leds.o update_state.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: play.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h switches.h buzzer.h main.c

led.o: led.c led.h switches.h

wdInterruptHandler.o: stateMachines.h

p1_interrupt_handler.o: switches.h

stateMachines.o: led.h stateMachines.h 

switches.o: switches.h switches.c

buzzer.o: buzzer.h

soundEngine.o: soundEngine.h
