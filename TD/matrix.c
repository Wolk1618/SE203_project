#include <stddef.h>
#include <stdint.h>

#include "matrix.h"
#include "./CMSIS/stm32l475xx.h"

#define TMS 20000


void matrix_init() {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2_Msk) | (1 << GPIO_MODER_MODE2_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3_Msk) | (1 << GPIO_MODER_MODE3_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4_Msk) | (1 << GPIO_MODER_MODE4_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5_Msk) | (1 << GPIO_MODER_MODE5_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6_Msk) | (1 << GPIO_MODER_MODE6_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7_Msk) | (1 << GPIO_MODER_MODE7_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15_Msk) | (1 << GPIO_MODER_MODE15_Pos);
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0_Msk) | (1 << GPIO_MODER_MODE0_Pos);
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1_Msk) | (1 << GPIO_MODER_MODE1_Pos);
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2_Msk) | (1 << GPIO_MODER_MODE2_Pos);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3_Msk) | (1 << GPIO_MODER_MODE3_Pos);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4_Msk) | (1 << GPIO_MODER_MODE4_Pos);
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5_Msk) | (1 << GPIO_MODER_MODE5_Pos);

	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED2;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED3;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED4;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED6;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED7;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED15;
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED0;
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED1;
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED2;
	GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED3;
	GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED4;
	GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED5;

	GPIOC->BSRR = GPIO_BSRR_BR3;
	GPIOC->BSRR = GPIO_BSRR_BS4;
	GPIOC->BSRR = GPIO_BSRR_BS5;
	GPIOB->BSRR = GPIO_BSRR_BR1;
	GPIOA->BSRR = GPIO_BSRR_BR4;
	GPIOB->BSRR = GPIO_BSRR_BR2;
	GPIOA->BSRR = GPIO_BSRR_BR15;
	GPIOA->BSRR = GPIO_BSRR_BR2;
	GPIOA->BSRR = GPIO_BSRR_BR7;
	GPIOA->BSRR = GPIO_BSRR_BR6;
	GPIOA->BSRR = GPIO_BSRR_BR5;
	GPIOB->BSRR = GPIO_BSRR_BR0;
	GPIOA->BSRR = GPIO_BSRR_BR3;

	for(int i=0; i<100*TMS; i++) {
		asm volatile("nop");
	}

	GPIOC->BSRR = GPIO_BSRR_BS3;
	init_bank0();
}

void pulse_SCK() {
	SCK(0);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
	SCK(1);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
	SCK(0);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
}

void pulse_LAT() {
	LAT(1);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
	LAT(0);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
	LAT(1);
	for(int i=0; i<1; i++) {
		asm volatile("nop");
	}
}

void deactivate_rows() {
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);	
	ROW7(0);
}

void activate_row(int row) {
	switch(row) {
		case 0 :
			ROW0(1);
			break;
		case 1 :
			ROW1(1);
			break;
		case 2 :
			ROW2(1);
			break;
		case 3 :
			ROW3(1);
			break;
		case 4 :
			ROW4(1);
			break;
		case 5 :
			ROW5(1);
			break;
		case 6 :
			ROW6(1);
			break;
		case 7 :
			ROW7(1);
			break;
	}
}

void send_byte(uint8_t val, int bank) {
	if(bank == 1) {
		SB(1);
	} else {
		SB(0);
	}
	for(int i = 7; i>=0; i--) {
		SDA((val >> i) & 1);
		asm volatile("nop");
		pulse_SCK();
	}
}

void mat_set_row(int row, const rgb_color *val) {
	deactivate_rows();
	for(int i=7; i>=0; i--) {
		send_byte((val[i]).b,1);
		send_byte((val[i]).g,1);
		send_byte((val[i]).r,1);
	}
	activate_row(row);
	pulse_LAT();
}

void init_bank0() {
	for(int i=0; i<18; i++) {
		send_byte(0xFF, 0);
	}
	pulse_LAT();
}

void test_pixels() {
	rgb_color color[8];
	deactivate_rows();
	for(int i=0; i<8; i++) {
		color[i].r = 255-(32*i);
		color[i].g = 0;
		color[i].b = 0;
	}
	for(int i=0; i<8; i++) {
		mat_set_row(i,color);
		for(int i=0; i<100 * TMS; i++) {
			asm volatile("nop");
		}
	}
	deactivate_rows();
	for(int i=0; i<8; i++) {
		color[i].r = 0;
		color[i].g = 255-(32*i);
		color[i].b = 0;
	}
	for(int i=0; i<8; i++) {
		mat_set_row(i,color);
		for(int i=0; i<100 * TMS; i++) {
			asm volatile("nop");
		}
	}
	deactivate_rows();
	for(int i=0; i<8; i++) {
		color[i].r = 0;
		color[i].g = 0;
		color[i].b = 255-(32*i);
	}
	for(int i=0; i<8; i++) {
		mat_set_row(i,color);
		for(int i=0; i<100 * TMS; i++) {
			asm volatile("nop");
		}
	}
}

void RST(int x) {
	if(x==0) {
		GPIOC->BSRR = GPIO_BSRR_BR3;
	} else {
		GPIOC->BSRR = GPIO_BSRR_BS3;
	}
}

void SB(int x) {
	if(x==0) {
		GPIOC->BSRR = GPIO_BSRR_BR5;
	} else {
		GPIOC->BSRR = GPIO_BSRR_BS5;
	}
}

void LAT(int x) {
	if(x==0) {
		GPIOC->BSRR = GPIO_BSRR_BR4;
	} else {
		GPIOC->BSRR = GPIO_BSRR_BS4;
	}
}

void SCK(int x) {
	if(x==0) {
		GPIOB->BSRR = GPIO_BSRR_BR1;
	} else {
		GPIOB->BSRR = GPIO_BSRR_BS1;
	}
}

void SDA(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR4;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS4;
	}
}

void ROW0(int x) {
	if(x==0) {
		GPIOB->BSRR = GPIO_BSRR_BR2;
	} else {
		GPIOB->BSRR = GPIO_BSRR_BS2;
	}
}

void ROW1(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR15;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS15;
	}
}

void ROW2(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR2;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS2;
	}
}

void ROW3(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR7;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS7;
	}
}

void ROW4(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR6;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS6;
	}
}

void ROW5(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR5;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS5;
	}
}

void ROW6(int x) {
	if(x==0) {
		GPIOB->BSRR = GPIO_BSRR_BR0;
	} else {
		GPIOB->BSRR = GPIO_BSRR_BS0;
	}
}

void ROW7(int x) {
	if(x==0) {
		GPIOA->BSRR = GPIO_BSRR_BR3;
	} else {
		GPIOA->BSRR = GPIO_BSRR_BS3;
	}
}
