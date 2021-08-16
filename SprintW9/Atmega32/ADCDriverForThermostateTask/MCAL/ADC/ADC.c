/*
 * ADC.c
 *
 *  Created on: Jul 28, 2021
 *      Author: zoldeyck
 */
#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "../../MCAL/DIO/DIO_DRIVER.h"
#include "ADC.h"

void static (*ADC_Conversion_Complete_callback)(void) = NULL;

uint8_t ADC_Init(uint8_t ADC_Number)
{
	uint8_t ErrRetVal = OperationStarted;
	/*Set the data adjustment*/
	MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_ConversionValueLeftAdjust_MSK,
			ADC_ReadingAdjustment<<ADC_ConversionValueLeftAdjust_BIT);
	/*Setting the voltage reference*/
	ADC_SetVref();
	/*Prescalar from configuration files*/
	ADC_SetPrescalar();
//	//for debug.
//	DIO_SetPortVal(PORTB,ADC_MultiplixerSelectionReg);
	/*setting the trigger source*/
	ADC_SetTrigerringSource();
	/*clearing interrupt flag*/
	SET_BIT(ADC_ControlAndStatusReg,ADC_InterruptFlag_BIT);
	/*enable ADC module*/
	SET_BIT(ADC_ControlAndStatusReg,ADC_Enable_BIT);
	return ErrRetVal;
}
uint8_t ADC_StartConversion(uint8_t ADC_Number)
{
	uint8_t ErrRetVal = OperationStarted;
	/*channel selection*/
	ADC_ChannelSelect();
	/*Set start conversion bit*/
	SET_BIT(ADC_ControlAndStatusReg,ADC_StartConversion_BIT);
	if(READ_BIT(ADC_ControlAndStatusReg,ADC_Enable_BIT))
	{
//		SET_BIT(ADC_ControlAndStatusReg,ADC_InterruptFlag_BIT);
		ErrRetVal= OperationSuccess;
	}
	else
	{
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}
uint8_t ADC_GetConversionResult(uint16_t* Result)
{
	uint8_t ErrRetVal = OperationStarted;
	if (READ_BIT(ADC_ControlAndStatusReg,ADC_StartConversion_BIT)==0)
	{

		if (ADC_ReadingAdjustment == ADC_LeftAdjusted)
		{
			*Result = (ADC_DataReg >> 6);
		} else
		{
			*Result = ADC_DataReg;
		}
		SET_BIT(ADC_ControlAndStatusReg,ADC_InterruptFlag_BIT);//Try
		ErrRetVal = OperationSuccess;
		SET_BIT(ADC_ControlAndStatusReg,ADC_InterruptFlag_BIT);
	}
	else
	{
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}

uint8_t ADC_ChannelSelect()/*in ADC Start Conversion*/
{
	uint8_t ErrRetVal = OperationStarted;
	switch(ADC_SelectedChannel)
	{
	case ADC_SingleEnded_Channel_0:
	case ADC_Differential_Positive_ADC_0_Negative_ADC_0_Gain_10:
	case ADC_Differential_Positive_ADC_0_Negative_ADC_0_Gain_200:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
				ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_1:
	case ADC_Differential_Positive_ADC_1_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_2:
	case ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_10:
	case ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_200:
	case ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_3:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_4:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_5:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_6:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_SingleEnded_Channel_7:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_1_Negative_ADC_0_Gain_10:
	case ADC_Differential_Positive_ADC_1_Negative_ADC_0_Gain_200:
	case ADC_Differential_Positive_ADC_0_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_10:
	case ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_200:
	case ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_2_Negative_ADC_1_Gain_1:
	case ADC_Differential_Positive_ADC_1_Negative_ADC_2_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_3_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_4_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_5_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_6_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_7_Negative_ADC_1_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_4_Negative_ADC_2_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	case ADC_Differential_Positive_ADC_5_Negative_ADC_2_Gain_1:
		MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_MUX_SelectionBits_MSK,
						ADC_SelectedChannel);
		ErrRetVal=OperationSuccess;
		break;
	default:
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}
uint8_t ADC_SetVref()/*in initialization*/
{
	uint8_t ErrRetVal = OperationStarted;
	MODIFY_REG(ADC_MultiplixerSelectionReg, ADC_VoltageReference_MSK,
			ADC_VoltageRef<<ADC_VoltageReferenceStarting_BIT);
	ErrRetVal=OperationSuccess;
	return ErrRetVal;
}
uint8_t ADC_SetPrescalar()/*in initialization*/
{
	uint8_t ErrRetVal = OperationStarted;
	MODIFY_REG(ADC_ControlAndStatusReg,ADC_Prescalar_MSK,ADC_Prescalar);
	ErrRetVal = OperationSuccess;
	return ErrRetVal;
}
uint8_t ADC_SetTrigerringSource()/*in initialization*/
{
	uint8_t ErrRetVal = OperationStarted;
	if(ADC_AutoTrigger==ADC_Enable)
	{
		SET_BIT(ADC_ControlAndStatusReg, ADC_AutoTriggerEnable_BIT);
		MODIFY_REG(ADC_SpecialFunctionIOReg, ADC_AutoTriggerSourceSelect_MSK,
				ADC_AutoTrigger_Source<<ADC_AutoTriggerStarting_BIT);
		ErrRetVal=OperationSuccess;
	}
	else
	{
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}

uint8_t ADC_EnableInterrupt()
{
	uint8_t ErrRetVal = OperationStarted;
	/*Enable Global Interrupt*/
	SET_BIT(STATUS_REG, 7);
	SET_BIT(ADC_ControlAndStatusReg, ADC_InterruptEnable_BIT);
	return ErrRetVal;
}
uint8_t ADC_DisableInterrupt()
{
	uint8_t ErrRetVal = OperationStarted;
	CLEAR_BIT(ADC_ControlAndStatusReg,ADC_InterruptEnable_BIT);
	return ErrRetVal;
}
uint8_t ADC_SetCallback(uint8_t ADC_Number, void (*callBack)(void))
{
	uint8_t ErrRetVal = OperationStarted;
	if(callBack!=NULL)
		ADC_Conversion_Complete_callback=callBack;
	return ErrRetVal;
}
void __vector_16(void)
{
	if(ADC_Conversion_Complete_callback!=NULL)
		ADC_Conversion_Complete_callback();
}
