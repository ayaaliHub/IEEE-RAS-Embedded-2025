#include "traffic_light.h"
#include "gpio.h"
#include "sevenseg.h"
#include <util/delay.h>

#define RED_PIN     PA0
#define YELLOW_PIN  PA1
#define GREEN_PIN   PA2

void TrafficLight_Init(void) {
	GPIO_InitPin(&DDRA, RED_PIN, OUTPUT);
	GPIO_InitPin(&DDRA, YELLOW_PIN, OUTPUT);
	GPIO_InitPin(&DDRA, GREEN_PIN, OUTPUT);
	SevenSeg_Init();
}

static void Countdown_Display(uint8_t seconds, uint8_t led_pin) {
	GPIO_WritePin(&PORTA, led_pin, HIGH);
	for (int s = seconds; s > 0; s--) {
		for (int i = 0; i < 200; i++) {
			SevenSeg_DisplayNumber(s);
			_delay_ms(5);
		}
	}
	GPIO_WritePin(&PORTA, led_pin, LOW);
}

void TrafficLight_Run(void) {
	Countdown_Display(15, RED_PIN);
	Countdown_Display(5,  YELLOW_PIN);
	Countdown_Display(10, GREEN_PIN);
}
