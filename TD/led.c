#include <stdint.h>
#include "led.h"
#include "./CMSIS/stm32l475xx.h"

#define BASE_CLOCK 0x40021000
#define BASE_GPIOB 0x48000400
#define BASE_GPIOC 0x48000800
#define REG_CLOCK (*((volatile uint32_t *) (BASE_CLOCK + 0x4C)))
#define REG_OUTPUTB (*((volatile uint32_t *) (BASE_GPIOB + 0x00)))
#define REG_OPENB (*((volatile uint32_t *) (BASE_GPIOB + 0x18)))
#define REG_OUTPUTC (*((volatile uint32_t *) (BASE_GPIOC + 0x00)))
#define REG_OPENC (*((volatile uint32_t *) (BASE_GPIOC + 0x18)))



void led_init() {
	init_clock_led();
	init_led_output();
}

void led(state_led state) {
	switch(state) {
		case LED_OFF :
			//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18));
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk);
			break;
		case LED_YELLOW :
			//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
			//REG_OPENC = (1 << 9);
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | (1 << GPIO_MODER_MODE9_Pos);
			GPIOC->BSRR = GPIO_BSRR_BS9;
			break;
		case LED_BLUE :
			//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
			//REG_OPENC = (1 << 25);
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | (1 << GPIO_MODER_MODE9_Pos);
			GPIOC->BSRR = GPIO_BSRR_BR9;
			break;
	}
}


void led_g_on() {	
	//REG_OPENB = (1 << 14);
	GPIOB->BSRR = GPIO_BSRR_BS14;
}

void led_g_off() {
	//REG_OPENB = (1 << 30);
	GPIOB->BSRR = GPIO_BSRR_BR14;
}

void led_y_on() {
	//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | (1 << GPIO_MODER_MODE9_Pos);
	//REG_OPENC = (1 << 9);
	GPIOC->BSRR = GPIO_BSRR_BS9;
}

void led_b_on() {
	//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | (1 << GPIO_MODER_MODE9_Pos);
	//REG_OPENC = (1 << 25);
	GPIOC->BSRR = GPIO_BSRR_BR9;
}

void led_by_off() {
	//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18));
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk);
}

void init_clock_led() {
	//REG_CLOCK = REG_CLOCK | (1 << 1);
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk;
	//REG_CLOCK = REG_CLOCK | (1 << 2);
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN_Msk;

}

void init_led_output() {
	//REG_OUTPUTB = (REG_OUTPUTB & ~(3 << 28)) | (1 << 28);
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE14_Msk) | (1 << GPIO_MODER_MODE14_Pos);
	//REG_OUTPUTC = (REG_OUTPUTC & ~(3 << 18)) | (1 << 18);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | (1 << GPIO_MODER_MODE9_Pos);
}

