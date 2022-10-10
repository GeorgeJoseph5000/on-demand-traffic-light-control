#include "application.h"

#define PORT_CAR 'A'
#define PORT_PEDESTRIAN 'B'

#define GREEN 0
#define YELLOW 1
#define RED 2

#define WAITING_TIME 5000
#define YELLOW_BLINKS 5

uint8_t pedestrian_mode = 0;
uint8_t current_car_state = 0;
uint8_t doneOnce = 0;

void setCurrentCarState(uint8_t state){
	current_car_state = state;
}

void nothing(){return;}
void setPedestrianMode(uint8_t mode){pedestrian_mode = mode;}
void setDoneOnce(uint8_t number){doneOnce = number;}


// states for cars
void greenState(){
	LED_on(GREEN, PORT_CAR);
	pedestrian_mode == 1 ? LED_on(RED, PORT_PEDESTRIAN) : setCurrentCarState(GREEN);
	TIMER_delay(WAITING_TIME);
	LED_off(GREEN, PORT_CAR);
	pedestrian_mode == 1 ? LED_off(RED, PORT_PEDESTRIAN) : setCurrentCarState(GREEN);
	doneOnce = 0;
}

void yellowState(){
	uint8_t blinks = 1;
	while(blinks <= (YELLOW_BLINKS*2)){
		LED_toggle(YELLOW, PORT_CAR);
		pedestrian_mode == 1 ? LED_toggle(YELLOW, PORT_PEDESTRIAN) : setCurrentCarState(YELLOW);
		TIMER_delay(WAITING_TIME/YELLOW_BLINKS);
		blinks++;
	}
	LED_off(YELLOW, PORT_CAR);
	pedestrian_mode == 1 ? LED_off(YELLOW, PORT_PEDESTRIAN) : setCurrentCarState(1);
}

void redState(){
	LED_on(RED, PORT_CAR);
	pedestrian_mode == 1 ? LED_on(GREEN, PORT_PEDESTRIAN) : setCurrentCarState(2);
	TIMER_delay(WAITING_TIME);
	LED_off(RED, PORT_CAR);
	pedestrian_mode == 1 ? LED_off(GREEN, PORT_PEDESTRIAN) : setCurrentCarState(2);
	(doneOnce == 1) ? setPedestrianMode(0) : nothing();
}


void app_start(){
	LED_init(GREEN, PORT_CAR);
	LED_init(YELLOW, PORT_CAR);
	LED_init(RED, PORT_CAR);
	
	LED_init(GREEN, PORT_PEDESTRIAN);
	LED_init(YELLOW, PORT_PEDESTRIAN);
	LED_init(RED, PORT_PEDESTRIAN);
	
	BUTTON_init(2, PORT_D);
	
	// Interrupt Setup
	CLEAR_BIT(DDRD, 2);
	sei();
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
	SET_BIT(GICR, 6);
	
	while(1){
		greenState();
		yellowState();
		(pedestrian_mode == 1) ? setDoneOnce(1) : nothing();
		redState();
		yellowState();
		if((pedestrian_mode == 1) && (doneOnce == 0)) {
			redState();
			pedestrian_mode = 0;
			yellowState();
		}
	}
	
}


ISR(INT0_vect){
	if(pedestrian_mode == 0){
		pedestrian_mode = 1;
		uint8_t color = 0;
		switch (current_car_state){
			case RED:
				color = GREEN;
			break;
			case YELLOW:
				color = YELLOW;
			break;
			case GREEN:
				color = RED;
			break;
				
		}
		LED_on(color, PORT_PEDESTRIAN);
	}
}