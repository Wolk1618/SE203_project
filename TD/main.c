#include <stdint.h>

#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "button.h"
#include "timer.h"

#define ATTENTE 10000000

int fibo(int n);

uint32_t sum = 0;
extern uint8_t _binary_image_raw_start;
uint8_t * image = &_binary_image_raw_start;

int main() {
	clocks_init();
	irq_init();
	button_init();
	led_init();
	uart_init(38400);
	matrix_init();
	trame_init();
	//uart_puts("init finished\n\r");
	//uart_puts("test\n\r");
	test_pixels();
	//uart_puts("debut\n\r");
	timer_init(1000000/(60*8));
	while(1) {
		print_image(trame);
	}

	/*uart_puts("init\n\r");
	uart_puts("attente du programme\n\r");
	for(int i=0; i < 200; i++) {
		sum += uart_getchar();
	}
	uart_puts("somme finie\n\r");*/
	/*while(1) {
		led_g_on();
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led_g_off();
		led(LED_YELLOW);
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led(LED_BLUE);
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led(LED_OFF);

		char *s = "";
		uart_gets(s, 5);
		uart_putchar(' ');
		uart_puts(s);
	}*/
	return 0;
}

int fibo(int n) {
	if(n==0) {
		return 1;
	} else if(n==1) {
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}
