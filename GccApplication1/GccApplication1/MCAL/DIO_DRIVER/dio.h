#ifndef DIO_H_
#define DIO_H_

// UTILS
#include "../../common_macros.h"
#include "../../registers.h"
#include "../../std_types.h"

typedef enum EN_DIO_Error_t
{
	OK, WRONG_PORT, WRONG_PIN, WRONG_DIRECTION, WRONG_VALUE
}EN_DIO_Error_t;



#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

EN_DIO_Error_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

EN_DIO_Error_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

EN_DIO_Error_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

EN_DIO_Error_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif