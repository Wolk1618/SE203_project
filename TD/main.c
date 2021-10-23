#include <stdint.h>

#include "led.h"
#include "clocks.h"
#include "uart.h"

#define ATTENTE 10000000

int fibo(int n);

int main() {
	clocks_init();
	led_init();
	uart_init();
	while(1) {
		/*led_g_on();
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led_g_off();
		led(LED_YELLOW);
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led(LED_BLUE);
		for (int i=0; i< ATTENTE; i++)
			asm volatile("nop");
		led(LED_OFF);*/
		uint8_t *c = (uint8_t *) "r";
		uart_putchar(*c);
	}
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



