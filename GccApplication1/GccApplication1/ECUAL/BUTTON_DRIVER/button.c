#include "button.h"


EN_DIO_Error_t BUTTON_init(uint8_t pinNumber, uint8_t portNumber){
	return DIO_init(pinNumber, portNumber, IN);
}
EN_DIO_Error_t BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	return DIO_read(pinNumber, portNumber, value);
}