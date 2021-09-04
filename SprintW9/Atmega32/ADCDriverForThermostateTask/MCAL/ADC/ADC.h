/*
 * ADC.h
 *
 *  Created on: Jul 28, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "ADC_PRIV.h"
#include "ADC_CONFIG.h"
uint8_t ADC_Init(uint8_t ADC_Number);
uint8_t ADC_StartConversion(uint8_t ADC_Number);
uint8_t ADC_ChannelSelect();
uint8_t ADC_SetVref();
uint8_t ADC_SetPrescalar();
uint8_t ADC_GetConversionResult(uint16_t* Result);
uint8_t ADC_EnableInterrupt();
uint8_t ADC_DisableInterrupt();
uint8_t ADC_SetTrigerringSource();
uint8_t ADC_SetCallback(uint8_t ADC_Number, void (*callBack)(void));
void __vector_16(void)__attribute__((signal,used));//ADC_Conversion_complete


#endif /* MCAL_ADC_ADC_H_ */
