#include "dio.h"

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	switch (portNumber){
		case 'A':
			if(direction == IN){
				CLEAR_BIT(DDRA, pinNumber);
			}else if(direction == OUT){
				SET_BIT(DDRA, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'B':
			if(direction == IN){
				CLEAR_BIT(DDRB, pinNumber);
			}else if(direction == OUT){
				SET_BIT(DDRB, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'C':
			if(direction == IN){
				CLEAR_BIT(DDRC, pinNumber);
			}else if(direction == OUT){
				SET_BIT(DDRC, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'D':
			if(direction == IN){
				CLEAR_BIT(DDRD, pinNumber);
			}else if(direction == OUT){
				SET_BIT(DDRD, pinNumber);
			}else{
				//error handling
			}
		break;
	}
}

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	switch (portNumber){
		case 'A':
			if(value == LOW){
				CLEAR_BIT(PORTA, pinNumber);
			}else if(value == HIGH){
				SET_BIT(PORTA, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'B':
			if(value == LOW){
				CLEAR_BIT(PORTB, pinNumber);
			}else if(value == HIGH){
				SET_BIT(PORTB, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'C':
			if(value == LOW){
				CLEAR_BIT(PORTC, pinNumber);
			}else if(value == HIGH){
				SET_BIT(PORTC, pinNumber);
			}else{
				// error handling
			}
		break;
		case 'D':
			if(value == LOW){
				CLEAR_BIT(PORTD, pinNumber);
			}else if(value == HIGH){
				SET_BIT(PORTD, pinNumber);
			}else{
				//error handling
			}
		break;
	}
}

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	switch(portNumber){
		case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
		break;
	}
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value = (PINA&(1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value = (PINB&(1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value = (PINC&(1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value = (PIND&(1<<pinNumber))>>pinNumber;
		break;
	}
}
