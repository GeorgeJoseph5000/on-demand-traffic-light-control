#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_DRIVER/dio.h"

EN_DIO_Error_t BUTTON_init(uint8_t pinNumber, uint8_t portNumber);
EN_DIO_Error_t BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif