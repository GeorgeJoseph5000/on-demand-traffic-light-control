#include "led.h"

void LED_init(uint8_t pinNumber, uint8_t portNumber){
	DIO_init(pinNumber, portNumber, OUT);
}

void LED_on(uint8_t pinNumber, uint8_t portNumber){
	DIO_write(pinNumber, portNumber, HIGH);
}

void LED_off(uint8_t pinNumber, uint8_t portNumber){
	DIO_write(pinNumber, portNumber, LOW);
}

void LED_toggle(uint8_t pinNumber, uint8_t portNumber){
	DIO_toggle(pinNumber, portNumber);
}

