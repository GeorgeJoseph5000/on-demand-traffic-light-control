#ifndef TEST_H_
#define TEST_H_

#include "../MCAL/TIMER/timer.h"
#include "../MCAL/PWM/pwm.h"
#include "../ECUAL/LED_DRIVER/led.h"
#include "../ECUAL/BUTTON_DRIVER/button.h"

void dio_test();
void led_test();
void timer_test();
void pwm_test();
void button_test();

#endif