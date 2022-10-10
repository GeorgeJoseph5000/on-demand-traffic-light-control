#include "pwm.h"

void PWM_init(){
	TCCR0 = 0x00;
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 5);
	SET_BIT(TCCR0, 6);
	//SET_BIT(TCCR0, 3);
	DIO_init(3, PORT_B, OUT);
}

void PWM_set_value(uint8_t duty){
	OCR0 = duty;
}