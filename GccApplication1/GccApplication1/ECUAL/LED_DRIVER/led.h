#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/dio.h"

EN_DIO_Error_t LED_init(uint8_t pinNumber, uint8_t portNumber);
EN_DIO_Error_t LED_on(uint8_t pinNumber, uint8_t portNumber);
EN_DIO_Error_t LED_off(uint8_t pinNumber, uint8_t portNumber);
EN_DIO_Error_t LED_toggle(uint8_t pinNumber, uint8_t portNumber);


#endif