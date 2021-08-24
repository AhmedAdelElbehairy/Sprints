/*
 * ADC_CONFIG.h
 *
 *  Created on: Jul 28, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
#define ADC_Channel_1												1
#define ADC_Enable													1
#define ADC_Disable 												0
#define ADC_AutoTrigger												ADC_Disable
/*single ended channel selection*/
#define ADC_SingleEnded_Channel_0 									0
#define ADC_SingleEnded_Channel_1 									1
#define ADC_SingleEnded_Channel_2 									2
#define ADC_SingleEnded_Channel_3 									3
#define ADC_SingleEnded_Channel_4 									4
#define ADC_SingleEnded_Channel_5 									5
#define ADC_SingleEnded_Channel_6 									6
#define ADC_SingleEnded_Channel_7 									7
/*differential Input channel Selection*/
#define ADC_Differential_Positive_ADC_0_Negative_ADC_0_Gain_10		8
#define ADC_Differential_Positive_ADC_1_Negative_ADC_0_Gain_10		9
#define ADC_Differential_Positive_ADC_0_Negative_ADC_0_Gain_200		10
#define ADC_Differential_Positive_ADC_1_Negative_ADC_0_Gain_200		11
#define ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_10		12
#define ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_10		13
#define ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_200		14
#define ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_200		15
#define ADC_Differential_Positive_ADC_0_Negative_ADC_1_Gain_1		16
#define ADC_Differential_Positive_ADC_1_Negative_ADC_1_Gain_1		17
#define ADC_Differential_Positive_ADC_2_Negative_ADC_1_Gain_1		18
#define ADC_Differential_Positive_ADC_3_Negative_ADC_1_Gain_1		19
#define ADC_Differential_Positive_ADC_4_Negative_ADC_1_Gain_1		20
#define ADC_Differential_Positive_ADC_5_Negative_ADC_1_Gain_1		21
#define ADC_Differential_Positive_ADC_6_Negative_ADC_1_Gain_1		22
#define ADC_Differential_Positive_ADC_7_Negative_ADC_1_Gain_1		23
#define ADC_Differential_Positive_ADC_0_Negative_ADC_2_Gain_1		24
#define ADC_Differential_Positive_ADC_1_Negative_ADC_2_Gain_1		25
#define ADC_Differential_Positive_ADC_2_Negative_ADC_2_Gain_1		26
#define ADC_Differential_Positive_ADC_3_Negative_ADC_2_Gain_1		27
#define ADC_Differential_Positive_ADC_4_Negative_ADC_2_Gain_1		28
#define ADC_Differential_Positive_ADC_5_Negative_ADC_2_Gain_1		29
#define ADC_SelectedChannel											ADC_SingleEnded_Channel_0
/*Voltage reference*/
#define ADC_ArefPin 												0
#define ADC_AvccPin													1
#define ADC_InternalVoltageRef  									3
#define ADC_VoltageRef												ADC_AvccPin
/*ADC Left Adjust bit*/
#define ADC_LeftAdjusted					 						1
#define ADC_RightAdjusted 											0
#define ADC_ReadingAdjustment 										ADC_LeftAdjusted
/*ADC AutoTrigger Source*/
#define ADC_Trig_FreeRunning										0
#define ADC_Trig_AnalogComparator									1
#define ADC_Trig_EXTI_0												2
#define ADC_Trig_Tim0_CompareMatch									3
#define ADC_Trig_Tim0_OverFlow										4
#define ADC_Trig_Tim1_CompareMatchB									5
#define ADC_Trig_Tim1_OverFlow										6
#define ADC_Trig_Tim1_CaptureEvent									7
#define ADC_AutoTrigger_Source										ADC_Trig_FreeRunning
/*ADC Prescalar*/
#define ADC_DefaultPrescalar_DivideBy_2								0
#define ADC_FCPU_DivideBy_2											1
#define ADC_FCPU_DivideBy_4											2
#define ADC_FCPU_DivideBy_8											3
#define ADC_FCPU_DivideBy_16										4
#define ADC_FCPU_DivideBy_32										5
#define ADC_FCPU_DivideBy_64										6
#define ADC_FCPU_DivideBy_128										7
#define ADC_Prescalar												ADC_FCPU_DivideBy_64
/*Bits And Masks for ADC MUX Selection Register*/
#define ADC_MUX_SelectionBits_MSK			 						0x8F
#define ADC_MUX_SelectionBitsStarting_BIT							0
#define ADC_VoltageReference_MSK			 						0xC0
#define ADC_VoltageReferenceStarting_BIT							6
#define ADC_ConversionValueLeftAdjust_BIT	 						5
#define ADC_ConversionValueLeftAdjust_MSK							32
/*Bits And Masks for ADC Control And Status Register*/
#define ADC_Prescalar_MSK 											0x07
#define ADC_InterruptEnable_BIT 									3
#define ADC_InterruptEnable_MSK 									8
#define ADC_InterruptFlag_BIT 										4
#define ADC_InterruptFlag_MSK 										16
#define ADC_AutoTriggerEnable_BIT 									5
#define ADC_AutoTriggerEnable_MSK 									32
#define ADC_StartConversion_BIT 									6
#define ADC_StartConversion_MSK 									64
#define ADC_Enable_BIT 												7
#define ADC_Enable_MSK 												128
/*Bits And Masks for Special Function SFIOR Register*/
#define ADC_AutoTriggerSourceSelect_MSK 							0xE0
#define ADC_AutoTriggerStarting_BIT		 							5
/*Error Codes*/
#define OperationSuccess 											0
#define OperationFail 												1
#define OperationStarted 											255

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
