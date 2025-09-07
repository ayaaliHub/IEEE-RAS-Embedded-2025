/*
 * Task16.c
 *
 * Created: 9/7/2025 4:33:56 PM
 * Author : ayaal
 */ 

#include "gpio.h"
#include "lcd.h"
#include "sevenseg.h"
#include "EXTI0.h"
#include "EXTI1.h"
#include "stdtypes.h"

volatile uint8_t counter = 1;

void toggleLED(void) {
	gpio_toggle(&PORTD, PIN0);   // LED on PD0
}

void resetCounter(void) {
	counter = 1;
}

int main(void) {
	/* Init LED */
	gpio_pin_mode(&DDRD, PIN0, OUTPUT);

	/* Init LCD */
	LCD_Init();
	LCD_Clear();

	/* Init Seven Segment */
	sevenseg_init();

	/* Init Interrupts */
	EXTI0_init(FALLING_EDGE);
	EXTI0_setCallback(toggleLED);
	EXTI0_enable();

	EXTI1_init(FALLING_EDGE1);
	EXTI1_setCallback(resetCounter);
	EXTI1_enable();

	sei(); 

	while (1) {
		/* Display on Seven Segment */
		sevenseg_show(counter);

		/* Display on LCD */
		LCD_Clear();
		LCD_WriteString("Counter: ");
		LCD_WriteInteger(counter);

		_delay_ms(1000);

		counter++;
		if (counter > 9) counter = 1;
	}
}
