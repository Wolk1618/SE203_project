#include "led.h"
#include "clocks.h"

#define ATTENTE 10000000

int fibo(int n);

int main() {
	clocks_init();
	led_init();
	while(1) {
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



