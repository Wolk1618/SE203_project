#include "timer.h"

#include "./CMSIS/stm32l475xx.h"

int on = 0;
uint8_t trame[192];
int compteur_ligne = 0;
extern int attente;

void timer_init(int max_us) {
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;
	TIM2->SR = 0;
	TIM2->CNT = 0;
	TIM2->CR1 &= ~TIM_CR1_DIR;
	TIM2->PSC = 80;
	TIM2->ARR = max_us;
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler() {
	TIM2->SR &= ~TIM_SR_UIF;
	attente = 0;
	/*rgb_color color[8];
	for(int i=0; i<8; i++) {
		color[i].r = trame[(24*compteur_ligne) + (3*i)];
		color[i].g = trame[(24*compteur_ligne) + (3*i) + 1];
		color[i].b = trame[(24*compteur_ligne) + (3*i) + 2];
	}
	mat_set_row(compteur_ligne, color);
	if(compteur_ligne == 7) {
		compteur_ligne = 0;
	} else {
		compteur_ligne++;
	}*/
	/*if(on) {
		GPIOB->BSRR = GPIO_BSRR_BR14;
		on = 0;
	} else {
		GPIOB->BSRR = GPIO_BSRR_BS14;
		on = 1;
	}*/
}

void trame_init() {
	for(int i=0; i<192; i++) {
		trame[i] = 200;
	}
}
