#include "button.h"


void BUTTON_init(uint8_t pinNumber, uint8_t portNumber){
	DIO_init(pinNumber, portNumber, IN);
}
void BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	DIO_read(pinNumber, portNumber, value);
}