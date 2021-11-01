#ifndef MATRIX_H
#define MATRIX_H

#include"CMSIS/stm32l475xx.h"
#include<stdint.h>
#include<string.h>

typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

void matrix_init();

void RST(int i);
void SB(int i);
void LAT(int i);
void SDA(int i);
void SCK(int i);

void ROW0(int i);
void ROW1(int i);
void ROW2(int i);
void ROW3(int i);
void ROW4(int i);
void ROW5(int i);
void ROW6(int i);
void ROW7(int i);

void pulse_SCK();
void pulse_LAT();
void activate_rows();
void desactivate_rows();
void activate_row(int row);

void send_byte(uint8_t val, int bank);
void mat_set_row(int row,const rgb_color *val);
void init_bank0();
void test_pixels();
void show();

#endif
