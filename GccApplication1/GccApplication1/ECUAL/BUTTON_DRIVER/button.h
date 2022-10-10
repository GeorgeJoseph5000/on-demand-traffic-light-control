#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_DRIVER/dio.h"

void BUTTON_init(uint8_t pinNumber, uint8_t portNumber);
void BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif