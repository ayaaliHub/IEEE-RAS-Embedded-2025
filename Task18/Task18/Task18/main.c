/*
 * Task18.c
 *
 * Created: 9/7/2025 10:28:30 PM
 * Author : ayaal
 */ 

#include "lcd.h"
#include "adc.h"
#include "timer0.h"
#include "ultrasonic.h"
#include "stdtypes.h"
#include <avr/wdt.h>

int main(void) {
	uint16_t adcVal, distance;
	uint8_t duty;

	LCD_Init();
	LCD_Clear();
	ADC_Init();
	TIMER0_initPWM();
	Ultrasonic_init();

	// Enable watchdog: timeout ~2s
	wdt_enable(WDTO_2S);

	while (1) {
		// Potentiometer ? LED brightness
		adcVal = ADC_Read(0);
		duty = adcVal / 4; // Map 0-1023 ? 0-255
		TIMER0_setDuty(duty);

		// Ultrasonic distance
		distance = Ultrasonic_getDistance();

		// Display
		LCD_Clear();
		LCD_WriteString("Dist: ");
		LCD_WriteInteger(distance);
		LCD_WriteString(" cm");

		LCD_GoTo(1,0);
		LCD_WriteString("ADC: ");
		LCD_WriteInteger(adcVal);

		_delay_ms(300);

		// Reset watchdog
		wdt_reset();
	}
}
