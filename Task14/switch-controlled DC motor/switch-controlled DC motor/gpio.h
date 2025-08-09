#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>

#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0

void GPIO_InitPin(volatile uint8_t *ddr, uint8_t pin, uint8_t direction);
void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, uint8_t value);
uint8_t GPIO_ReadPin(volatile uint8_t *pin_reg, uint8_t pin);

#endif
