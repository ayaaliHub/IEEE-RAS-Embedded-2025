#ifndef EXTI0_H_
#define EXTI0_H_

#include "EXTI0_REGISTER.h"
#include "stdtypes.h"

typedef enum {
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
} EXTI0_Sense_t;

void EXTI0_init(EXTI0_Sense_t sense);
void EXTI0_enable(void);
void EXTI0_disable(void);
void EXTI0_setCallback(void (*callback)(void));

#endif /* EXTI0_H_ */
