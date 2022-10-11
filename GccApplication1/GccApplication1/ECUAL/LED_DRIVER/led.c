#include "led.h"

EN_DIO_Error_t LED_init(uint8_t pinNumber, uint8_t portNumber){
	return DIO_init(pinNumber, portNumber, OUT);
}

EN_DIO_Error_t LED_on(uint8_t pinNumber, uint8_t portNumber){
	return DIO_write(pinNumber, portNumber, HIGH);
}

EN_DIO_Error_t LED_off(uint8_t pinNumber, uint8_t portNumber){
	return DIO_write(pinNumber, portNumber, LOW);
}

EN_DIO_Error_t LED_toggle(uint8_t pinNumber, uint8_t portNumber){
	return DIO_toggle(pinNumber, portNumber);
}

