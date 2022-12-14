#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "./CMSIS/stm32l475xx.h"

#define TMS 20000

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} rgb_color;

extern volatile int attente;

void matrix_init();
void RST(int x);
void SB(int x);
void LAT(int x);
void SCK(int x);
void SDA(int x);
void ROW0(int x);
void ROW1(int x);
void ROW2(int x);
void ROW3(int x);
void ROW4(int x);
void ROW5(int x);
void ROW6(int x);
void ROW7(int x);
void pulse_SCK();
void pulse_LAT();
void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);
void init_bank0();
void test_pixels();
void print_image();

#endif
