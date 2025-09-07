/*
 * adc.h
 *
 * Created: 9/7/2025 9:13:25 PM
 *  Author: ayaal
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "stdtypes.h"

void ADC_Init(void);
uint16_t ADC_Read(uint8_t channel);

#endif /* ADC_H_ */

