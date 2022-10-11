#include "test.h"


void dio_test(){
	DIO_init(2, PORT_D, IN);
	DIO_init(0, PORT_A, OUT);
	uint8_t button_value = 0;
	while(1){
		DIO_read(2, PORT_D, &button_value);
		DIO_write(0, PORT_A, button_value);
	}
}

void led_test(){
	LED_init(0, PORT_A);
	LED_on(0, PORT_A);
}

void timer_test(){
	LED_init(0, PORT_A);
	while(1){
		LED_toggle(0, PORT_A);
		TIMER_delay(500);
	}
}

void pwm_test(){
	PWM_init();
	while(1){
		PWM_set_value(50);	
	}
}

void button_test(){
	BUTTON_init(2, PORT_D);
	LED_init(0, PORT_A);
	uint8_t button_value = 0;
	while(1){
		BUTTON_read(2, PORT_D, &button_value);
		button_value == LOW ?  LED_off(0, PORT_A) : LED_on(0, PORT_A);
	}
}