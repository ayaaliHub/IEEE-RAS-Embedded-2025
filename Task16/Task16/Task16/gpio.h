/*
 * gpio.h
 *
 * Created: 9/7/2025 4:40:44 PM
 *  Author: ayaal
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "stdtypes.h"

typedef unsigned char uint8_t;
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

static inline void gpio_pin_mode(volatile uint8_t *ddr, uint8_t pin, uint8_t mode) {
	if (mode) SET_BIT(*ddr, pin);
	else      CLR_BIT(*ddr, pin);
}

static inline void gpio_write(volatile uint8_t *port, uint8_t pin, uint8_t val) {
	if (val) SET_BIT(*port, pin);
	else     CLR_BIT(*port, pin);
}

static inline void gpio_toggle(volatile uint8_t *port, uint8_t pin) {
	TOG_BIT(*port, pin);
}

#endif 