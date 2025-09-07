/*
 * ultrasonic.c
 *
 * Created: 9/7/2025 10:37:58 PM
 *  Author: ayaal
 */ 

#include "ultrasonic.h"
#include "gpio.h"
#include "timer1.h"

#define TRIG_PIN PIN0
#define ECHO_PIN PIN1

void Ultrasonic_init(void) {
	gpio_pin_mode(&DDRD, TRIG_PIN, OUTPUT);
	gpio_pin_mode(&DDRD, ECHO_PIN, INPUT);
	TIMER1_initICU();
}

uint16_t Ultrasonic_getDistance(void) {
	// Send Trigger pulse
	gpio_write(&PORTD, TRIG_PIN, HIGH);
	_delay_us(10);
	gpio_write(&PORTD, TRIG_PIN, LOW);

	uint16_t pulse = TIMER1_getPulse();
	// Each tick = 0.5us (with F_CPU=16MHz, prescaler=8)
	// Distance = (pulse * 0.5us * speed of sound) / 2
	uint32_t time_us = pulse / 2; // 1 tick = 0.5us
	uint16_t distance_cm = (time_us * 0.0343) / 2;
	return distance_cm;
}
