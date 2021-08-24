/*
 * main.c
 *
 *  Created on: Jul 15, 2021
 *      Author: Ahmed
 */
#define F_CPU 8000000UL
#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "Infrastructure/LIB/STRING.h"
#include "MCAL/DIO/DIO_DRIVER.h"
#include "MCAL/UART/UART.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/PushButton/PushButton.h"
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "APP/APP.h"
int main()
{
	APP_Init();
//	LCD_Init();
//	KPAD_vidInit();
//	PSHBTTN_Init(PORTA, PIN1, PULLED_UP);
//	DIO_SetPinDirection(PORTD, PIN2, PIN_OUTPUT);//motor initialization
//	ADC_Init(ADC_Channel_1);
//	UART_Init(UARTChannel_1);
//	uint8_t SetTempPSHBTTN = 1;
//	uint8_t SettedTemp = 0;
//	uint8_t ActualTemp = 0;
//	uint8_t PressedKpadKey = 255;
//	uint16_t reading = 0;
//	uint16_t AnalogReading = 0;
//	uint8_t Setvalue[4] = {'\0','\0','\0','\0'};
//	uint8_t* ptr = Setvalue;
//	uint8_t iterator = 0;
	while (1)
	{
		APP_Start();
//		LCD_SendCommand(0xC0);
//		LCD_SendString((uint8_t*)"SetTemp.: ");
//		SetTempPSHBTTN = PSHBTTN_Status(PORTA, PIN1);
//		if(!SetTempPSHBTTN)
//		{
//			//get keypad pressed keys
//			LCD_SendCommand(0xCB);
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCommand(0xCB);
//			do
//			{
//				PressedKpadKey = KPAD_GetKey();
//				if(PressedKpadKey!=KPAD_NO_KPRESSED)
//				{
//					//assign the number to the Array
//					if(PressedKpadKey!='=')
//					{
//						*ptr = PressedKpadKey;
//						LCD_SendCharacter(*ptr);
//						ptr++;
//						iterator++;
//					}
//				}
//			}
//			while(PressedKpadKey != '=' && iterator<3);
//			//change it to number
//			ptr = Setvalue;
//			iterator = 0;
//			STR_String2Number(Setvalue, (uint16_t*)&SettedTemp);
//			Setvalue[0] = '\0';
//			Setvalue[1] = '\0';
//			Setvalue[2] = '\0';
//			Setvalue[3] = '\0';
//
//		}
//		else
//		{
//			LCD_SendCommand(0x80);
//			LCD_SendString((uint8_t*)"Temp. is: ");
//			//start conversion
//			ADC_StartConversion(ADC_Channel_1);
//			//get the reading
//			while(ADC_GetConversionResult(&reading)!=OperationSuccess);
//			//convert reading to the actual temperature
//				//get analog read according to Vref and divide it by 10
//			AnalogReading = (reading/1024.0)*5000;
//			ActualTemp = AnalogReading/10;
//			//update part of LCD concerned with Actual Temperature first line
//			LCD_SendCommand(0x8B);
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCharacter(' ');
//			LCD_SendCommand(0x8B);
//			LCD_SendNumber(ActualTemp);
//			//compare actual reading with settedTemp
//			//decide to run the motor or not
//			if(ActualTemp >= SettedTemp)
//			{
//				//run the motor
//				DIO_WritePin(PORTD,PIN2,PIN_HIGH);
//			}
//			else
//			{
//				//stop the motor
//				DIO_WritePin(PORTD,PIN2,PIN_LOW);
//			}
//
//		}

//		ADC_StartConversion(ADC_Channel_1);
//		while(ADC_GetConversionResult(&reading)!=OperationSuccess);
//		LCD_SendCommand(0x80);
//		LCD_SendString((uint8_t*)"Temp. is: ");
//		LCD_SendCommand(0x8B);
//		LCD_SendNumber(reading);

	}
	return 0;
}
