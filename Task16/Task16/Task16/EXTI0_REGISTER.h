#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

#include "register.h"

/* MCU Control Register */
#define MCUCR   (*(volatile uint8_t*)0x55)
/* MCU Control and Status Register */
#define MCUCSR  (*(volatile uint8_t*)0x54)
/* General Interrupt Control Register */
#define GICR    (*(volatile uint8_t*)0x5B)
/* General Interrupt Flag Register */
#define GIFR    (*(volatile uint8_t*)0x5A)

#define ISC00   0
#define ISC01   1
#define INT0    6

#endif 
