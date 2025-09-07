/*
 * Task17.c
 *
 * Created: 9/7/2025 9:12:27 PM
 * Author : ayaal
 */ 

#include "gpio.h"
#include "lcd.h"
#include "adc.h"
#include "stdtypes.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	uint16_t adcValue = 0;
	uint8_t ledCount = 0;
	uint8_t percentage = 0;

	/* Init */
	LCD_Init();
	LCD_Clear();
	ADC_Init();

	// Configure LEDs as output
	DDRC = 0xFF;

	while (1) {
		adcValue = ADC_Read(0);  // Read from channel 0 (PA0)
		percentage = (adcValue * 100) / 1023;
		ledCount = (percentage * 8) / 100; // Map 0-100% -> 0-8 LEDs

		// Control LEDs
		PORTC = (1 << ledCount) - 1;  // e.g. 4 LEDs ON => 00001111

		// Display on LCD
		LCD_Clear();
		LCD_WriteString("ADC: ");
		LCD_WriteInteger(adcValue);

		LCD_GoTo(1,0);
		LCD_WriteString("Percent: ");
		LCD_WriteInteger(percentage);
		LCD_WriteString("%");

		_delay_ms(200);
	}
}
