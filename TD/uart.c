#include <stdint.h>

#include "./CMSIS/stm32l475xx.h"
#include "uart.h"

void uart_init() {
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6_Msk) | (7 << GPIO_AFRL_AFSEL6_Pos);
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7_Msk) | (7 << GPIO_AFRL_AFSEL7_Pos);
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->CCIPR &= ~RCC_CCIPR_USART1SEL_Msk;
	RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
	USART1->CR1 &= ~USART_CR1_UE;
	USART1->BRR = 694;
	//USART clock must tick every 694 tick of principal clock (80.000.000 / 115.200 = 694.444) and according to the doc, clock rate has 3% resilience so 694 is allowed
	USART1->CR1 &= ~USART_CR1_OVER8_Msk;
	USART1->CR1 &= ~USART_CR1_M_Msk;
	USART1->CR1 &= ~USART_CR1_PCE_Msk;
	USART1->CR2 &= ~USART_CR2_STOP_Msk;
	USART1->CR1 |= USART_CR1_UE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_TE;
}

void uart_putchar(uint8_t c) {
	while((USART1->ISR & USART_ISR_TXE_Msk)  == 0) { //find good test
	}
	USART1->TDR = c;
}	
