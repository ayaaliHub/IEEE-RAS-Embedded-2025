#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

#include "traffic_light.h"

int main(void) {
	TrafficLight_Init();
	while (1) {
		TrafficLight_Run();
	}
}


