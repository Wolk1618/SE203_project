#include <stdint.h>
#include <stddef.h>

#include "./CMSIS/stm32l475xx.h"
#include "uart.h"
#include "timer.h"

extern int compteur_trame;

void uart_init(int baudrate) {

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1;
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6_Msk) | (7 << GPIO_AFRL_AFSEL6_Pos);
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7_Msk) | (7 << GPIO_AFRL_AFSEL7_Pos);
	RCC->CCIPR &= ~RCC_CCIPR_USART1SEL_Msk;
	RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;
	USART1->CR1 = 0;
	USART1->CR2 = 0;
	//USART1->CR1 &= ~USART_CR1_UE;
	int rate = (int) (80000000/baudrate);
	USART1->BRR = rate;
	//USART1->CR1 &= ~USART_CR1_OVER8_Msk;
	//USART1->CR1 &= ~USART_CR1_M_Msk;
	//USART1->CR1 &= ~USART_CR1_PCE_Msk;
	//USART1->CR2 &= ~USART_CR2_STOP_Msk;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART1->ISR = 0;
	USART1->CR1 |= USART_CR1_UE;
	NVIC_EnableIRQ(USART1_IRQn);
}

void uart_putchar(uint8_t c) {
	while((USART1->ISR & USART_ISR_TXE_Msk)  == 0) {
	}
	USART1->TDR = c;
}

uint8_t uart_getchar() {
	while((USART1->ISR & USART_ISR_RXNE_Msk) == 0) {
	}
	return USART1->RDR;
}

void uart_puts(const char *s) {
	int i = 0;
	while(s[i] != '\0') {
		uart_putchar(s[i]);
		i++;
	}
}

void uart_gets(char *s, size_t size) {
	for(int i=0; i < (int) size; i++) {
		s[i] = uart_getchar();
	}
	s[(int)size] = '\0';
}

void USART1_IRQHandler() {
	uint8_t byte = 0;
	//uint8_t byte = uart_getchar();
	if((USART1->ISR & USART_ISR_RXNE_Msk) != 0) {
		byte = USART1->RDR;
	}
	//uart_putchar(byte);
	*(trame + compteur_trame) = byte;
	if((compteur_trame == 191) | (byte == 0xFF)) {
		compteur_trame = 0;
	} else {
		compteur_trame++;
	}
}
