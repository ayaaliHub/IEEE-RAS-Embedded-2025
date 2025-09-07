/*
 * ultrasonic.h
 *
 * Created: 9/7/2025 10:39:08 PM
 *  Author: ayaal
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "stdtypes.h"

void Ultrasonic_init(void);
uint16_t Ultrasonic_getDistance(void);

#endif
