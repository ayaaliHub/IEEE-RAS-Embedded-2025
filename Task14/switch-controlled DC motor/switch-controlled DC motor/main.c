#include "gpio.h"
#include "motor.h"
#include <util/delay.h>

#define SW_STOP     PD0
#define SW_FORWARD  PD1
#define SW_BACKWARD PD2
#define SW_LEFT     PD3
#define SW_RIGHT    PD4

void Switch_Init(void) {
	GPIO_InitPin(&DDRB, SW_STOP, INPUT);
	GPIO_InitPin(&DDRB, SW_FORWARD, INPUT);
	GPIO_InitPin(&DDRB, SW_BACKWARD, INPUT);
	GPIO_InitPin(&DDRB, SW_LEFT, INPUT);
	GPIO_InitPin(&DDRB, SW_RIGHT, INPUT);
}

int main(void) {
	Switch_Init();
	Motor_Init();

	while (1) {
		if (GPIO_ReadPin(&PINB, SW_STOP)) {
			Motor_Stop();
		}
		else if (GPIO_ReadPin(&PINB, SW_FORWARD)) {
			Motor_Forward();
		}
		else if (GPIO_ReadPin(&PINB, SW_BACKWARD)) {
			Motor_Backward();
		}
		else if (GPIO_ReadPin(&PINB, SW_LEFT)) {
			Motor_Left();
		}
		else if (GPIO_ReadPin(&PINB, SW_RIGHT)) {
			Motor_Right();
		}
	}
}
