#include "led.h"

int fibo(int n);

int main(int argc, char * argv[]) {
	led_init();
	while(1) {
		led_g_on();
		for (int i=0; i< 100000; i++)
			asm volatile("nop");
		led_g_off();
		led(1);
		for (int i=0; i< 100000; i++)
			asm volatile("nop");
		led(2);
		for (int i=0; i< 100000; i++)
			asm volatile("nop");
		led(0);
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



