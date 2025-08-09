#include "gpio.h"

void GPIO_InitPin(volatile uint8_t *ddr, uint8_t pin, uint8_t direction) {
	if (direction == OUTPUT)
	*ddr |= (1 << pin);
	else
	*ddr &= ~(1 << pin);
}

void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, uint8_t value) {
	if (value)
	*port |= (1 << pin);
	else
	*port &= ~(1 << pin);
}

uint8_t GPIO_ReadPin(volatile uint8_t *pin_reg, uint8_t pin) {
	return ((*pin_reg & (1 << pin)) != 0);
}
