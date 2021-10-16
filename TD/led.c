#include <stdint.h>
#include "led.h"

#define BASE_CLOCK 0x40021000
#define BASE_GPIOB 0x48000400
#define BASE_GPIOC 0x48000800
#define REG_CLOCK (*((volatile uint32_t *) (BASE_CLOCK + 0x4C)))
#define REG_OUTPUTB (*((volatile uint32_t *) (BASE_GPIOB + 0x00)))
#define REG_OPENB (*((volatile uint32_t *) (BASE_GPIOB + 0x18)))
#define REG_OUTPUTC (*((volatile uint32_t *) (BASE_GPIOC + 0x00)))
#define REG_OPENC (*((volatile uint32_t *) (BASE_GPIOC + 0x18)))

#define LED_OFF 0
#define LED_YELLOW 1
#define LED_BLUE 2


void led_init() {
	init_clock_led();
	init_led_output();
}

void led(int state) {
	switch(state) {
		case LED_OFF :
			REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18));
			break;
		case LED_YELLOW :
			REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
			REG_OPENC = (1 << 9);
			break;
		case LED_BLUE :
			REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
			REG_OPENC = (1 << 25);
			break;
	}
}


void led_g_on() {	
	REG_OPENB = (1 << 14);
}

void led_g_off() {
	REG_OPENB = (1 << 30);
}

void led_y_on() {
	REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
	REG_OPENC = (1 << 9);
}

void led_b_on() {
	REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
	REG_OPENC = (1 << 25);
}

void led_by_off() {
	REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18));
}

void init_clock_led() {
	REG_CLOCK = REG_CLOCK | (1 << 1);
	REG_CLOCK = REG_CLOCK | (1 << 2);

}

void init_led_output() {
	REG_OUTPUTB = (REG_OUTPUTB & ~(3 << 28)) | (1 << 28);
	REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
}

