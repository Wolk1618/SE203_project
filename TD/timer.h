#ifndef TIMER_H
#define TIMER_H

#include "matrix.h"
#include "./CMSIS/stm32l475xx.h"

extern uint8_t trame[192];

void timer_init(int max_us);
void trame_init();

#endif
