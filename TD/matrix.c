#include "matrix.h"
#include "./CMSIS/stm32l475xx.h"

void matrix_init() {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2_Msk) | (1 << GPIO_MODER_MODE2_Pos);
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3_Msk) | (1 << GPIO_MODER_MODE3_Pos);
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
	GPIOA->BSRR = 0;
	GPIOB->BSRR = 0;
	GPIOC->BSRR = 0;
	GPIOC->BSRR |= GPIO_BSRR_BS4;
	GPIOC->BSRR |= GPIO_BSRR_BS5;
	for(int i=0; i<100000; i++) {
		asm volatile("nop");
	}
	GPIOC->BSRR |= GPIO_BSRR_BS3;
}

void pulse_SCK() {
	SCK(1);
	for(int i=0; i<10000; i++) { //comment faire 25 ms ?
		asm volatile("nop");
	}
	SCK(0);
	for(int i=0; i<10000; i++) {
		asm volatile("nop");
	}

}

void pulse_LAT() {
	LAT(0);
	for(int i=0; i<10000; i++) {
		asm volatile("nop");
	}
	LAT(1);
	for(int i=0; i<10000; i++) {
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
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);	
	ROW7(0);
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

void RST(int x) {
	if(x==0) {
		GPIOC->BSRR |= GPIO_BSRR_BR3;
	} else {
		GPIOC->BSRR |= GPIO_BSRR_BS3;
	}
}

void SB(int x) {
	if(x==0) {
		GPIOC->BSRR |= GPIO_BSRR_BR5;
	} else {
		GPIOC->BSRR |= GPIO_BSRR_BS5;
	}
}

void LAT(int x) {
	if(x==0) {
		GPIOC->BSRR |= GPIO_BSRR_BR4;
	} else {
		GPIOC->BSRR |= GPIO_BSRR_BS4;
	}
}

void SCK(int x) {
	if(x==0) {
		GPIOB->BSRR |= GPIO_BSRR_BR1;
	} else {
		GPIOB->BSRR |= GPIO_BSRR_BS1;
	}
}

void SDA(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR4;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS4;
	}
}

void ROW0(int x) {
	if(x==0) {
		GPIOB->BSRR |= GPIO_BSRR_BR2;
	} else {
		GPIOB->BSRR |= GPIO_BSRR_BS2;
	}
}

void ROW1(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR15;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS15;
	}
}

void ROW2(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR2;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS2;
	}
}

void ROW3(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR7;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS7;
	}
}

void ROW4(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR6;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS6;
	}
}

void ROW5(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BS5;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS5;
	}
}

void ROW6(int x) {
	if(x==0) {
		GPIOB->BSRR |= GPIO_BSRR_BR0;
	} else {
		GPIOB->BSRR |= GPIO_BSRR_BS0;
	}
}

void ROW7(int x) {
	if(x==0) {
		GPIOA->BSRR |= GPIO_BSRR_BR3;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BS3;
	}
}
