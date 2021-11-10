#include "button.h"

#include "./CMSIS/stm32l475xx.h"

int on_button = 0;

void button_init(void) {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE13_Msk);
	//SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] & ~SYSCFG_EXTICR4_EXTI13_Msk) | (2 << SYSCFG_EXTICR4_EXTI13_Pos);
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
	EXTI->IMR1 |= EXTI_IMR1_IM13;
	EXTI->EMR1 |= EXTI_EMR1_EM13;
	EXTI->RTSR1 &= ~EXTI_RTSR1_RT13;
	EXTI->FTSR1 |= EXTI_FTSR1_FT13;
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler() {
	EXTI->PR1 |= EXTI_PR1_PIF13;
	if(on_button) {
		GPIOB->BSRR = GPIO_BSRR_BR14;
		on_button = 0;
	} else {
		GPIOB->BSRR = GPIO_BSRR_BS14;
		on_button = 1;
	}
}
