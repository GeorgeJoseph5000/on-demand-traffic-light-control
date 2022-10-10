#include "timer.h"

#define FREQUENCY 1000000



void TIMER_delay(int milliseconds){
	TCCR0 = 0x00;
	TCNT0 = 0x00;
	
	// prescaler 1024
	float no_of_overflows, time_initial_value;
	float ms_fl = (float) milliseconds/1000;
	float t_tick = 1024.0/FREQUENCY;
	float t_max_delay = pow(2,8)*t_tick;
	
	if(milliseconds < t_max_delay){
		time_initial_value = ceil((t_max_delay-ms_fl)/t_tick);
		no_of_overflows = 1;
	}else if(milliseconds == t_max_delay){
		time_initial_value = 0;
		no_of_overflows = 1;
	}else{
		no_of_overflows = ceil((ms_fl)/t_max_delay);
		time_initial_value = ceil(pow(2,8) - ((ms_fl)/t_tick)/no_of_overflows);	
	}
	
	
	TCNT0 = (uint8_t) time_initial_value;
	
	// set prescaler to 1024 cs00 cs02
	SET_BIT(TCCR0, 2);
	SET_BIT(TCCR0, 0);
	unsigned int noOfCountOverflows = 0;
	while(noOfCountOverflows < (int) no_of_overflows){	
		while(BIT_IS_SET(TIFR, 0) == 0);
		SET_BIT(TIFR, 0);
		noOfCountOverflows++;
	}
	TIFR = 0x00;
	TCCR0 = 0x00;
	TCNT0 = 0x00;
	
	
}