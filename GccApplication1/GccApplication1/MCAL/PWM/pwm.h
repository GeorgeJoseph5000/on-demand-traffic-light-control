#ifndef PWM_H_
#define PWM_H_
#include "../../MCAL/DIO_DRIVER/dio.h"

void PWM_init();
void PWM_set_value(uint8_t duty);

#endif