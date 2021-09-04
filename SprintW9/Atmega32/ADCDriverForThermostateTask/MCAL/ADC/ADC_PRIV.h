/*
 * ADC_PRIV.h
 *
 *  Created on: Jul 28, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

/*Registers*/
#define ADC_MultiplixerSelectionReg *((volatile uint8_t *)0x27)
#define ADC_ControlAndStatusReg     *((volatile uint8_t *)0x26)
#define ADC_DataReg_High 			*((volatile uint8_t *)0x25)
#define ADC_DataReg_Low 			*((volatile uint8_t *)0x24)
#define ADC_DataReg					*((volatile uint16_t *)0x24)
#define ADC_SpecialFunctionIOReg	*((volatile uint8_t *)0x50)
#define STATUS_REG		 			*((volatile uint8_t*)0x5F)//SREG
#endif /* MCAL_ADC_ADC_PRIV_H_ */
