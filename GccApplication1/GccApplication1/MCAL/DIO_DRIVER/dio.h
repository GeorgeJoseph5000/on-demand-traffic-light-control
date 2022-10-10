#ifndef DIO_H_
#define DIO_H_

// UTILS
#include "../../common_macros.h"
#include "../../registers.h"
#include "../../std_types.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif