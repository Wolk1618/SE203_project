#ifndef LED_H
#define LED_H

typedef enum{
	LED_OFF,
	LED_YELLOW,
	LED_BLUE
} state_led;


void init_clock_led();
void led_init();
void led_g_on();
void led_g_off();
void init_led_output();
void led_y_on();
void led_b_on();
void led_by_off();
void led(state_led state);

#endif
