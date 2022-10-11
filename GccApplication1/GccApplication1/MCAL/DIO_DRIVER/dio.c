#include "dio.h"

EN_DIO_Error_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	switch (portNumber){
		case 'A':
			if(direction == IN){
				CLEAR_BIT(DDRA, pinNumber);
				return OK;
			}else if(direction == OUT){
				SET_BIT(DDRA, pinNumber);
				return OK;
			}else{
				return WRONG_DIRECTION;
			}
		break;
		case 'B':
			if(direction == IN){
				CLEAR_BIT(DDRB, pinNumber);
				return OK;
			}else if(direction == OUT){
				SET_BIT(DDRB, pinNumber);
				return OK;
			}else{
				return WRONG_DIRECTION;
			}
		break;
		case 'C':
			if(direction == IN){
				CLEAR_BIT(DDRC, pinNumber);
				return OK;
			}else if(direction == OUT){
				SET_BIT(DDRC, pinNumber);
				return OK;
			}else{
				return WRONG_DIRECTION;
			}
		break;
		case 'D':
			if(direction == IN){
				CLEAR_BIT(DDRD, pinNumber);
				return OK;
			}else if(direction == OUT){
				SET_BIT(DDRD, pinNumber);
				return OK;
			}else{
				return WRONG_DIRECTION;
			}
		break;
		default:
			return WRONG_PORT;
		break;
	}
}

EN_DIO_Error_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	switch (portNumber){
		case 'A':
			if(value == LOW){
				CLEAR_BIT(PORTA, pinNumber);
				return OK;
			}else if(value == HIGH){
				SET_BIT(PORTA, pinNumber);
				return OK;
			}else{
				return WRONG_VALUE;
			}
		break;
		case 'B':
			if(value == LOW){
				CLEAR_BIT(PORTB, pinNumber);
				return OK;
			}else if(value == HIGH){
				SET_BIT(PORTB, pinNumber);
				return OK;
			}else{
				return WRONG_VALUE;
			}
		break;
		case 'C':
			if(value == LOW){
				CLEAR_BIT(PORTC, pinNumber);
				return OK;
			}else if(value == HIGH){
				SET_BIT(PORTC, pinNumber);
				return OK;
			}else{
				return WRONG_VALUE;
			}
		break;
		case 'D':
			if(value == LOW){
				CLEAR_BIT(PORTD, pinNumber);
				return OK;
			}else if(value == HIGH){
				SET_BIT(PORTD, pinNumber);
				return OK;
			}else{
				return WRONG_VALUE;
			}
		break;
		default:
			return WRONG_PORT;
		break;
	}
}

EN_DIO_Error_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	switch(portNumber){
		case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
			return OK;
		break;
		case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
			return OK;
		break;
		case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
			return OK;
		break;
		case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
			return OK;
		break;
		default:
			return WRONG_PORT;
		break;
	}
}

EN_DIO_Error_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value = (PINA&(1<<pinNumber))>>pinNumber;
		return OK;
		break;
		case PORT_B:
		*value = (PINB&(1<<pinNumber))>>pinNumber;
		return OK;
		break;
		case PORT_C:
		*value = (PINC&(1<<pinNumber))>>pinNumber;
		return OK;
		break;
		case PORT_D:
		*value = (PIND&(1<<pinNumber))>>pinNumber;
		return OK;
		break;
		default:
		return WRONG_PORT;
		break;
	}
}
