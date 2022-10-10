#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/dio.h"

void LED_init(uint8_t pinNumber, uint8_t portNumber);
void LED_on(uint8_t pinNumber, uint8_t portNumber);
void LED_off(uint8_t pinNumber, uint8_t portNumber);
void LED_toggle(uint8_t pinNumber, uint8_t portNumber);


#endif