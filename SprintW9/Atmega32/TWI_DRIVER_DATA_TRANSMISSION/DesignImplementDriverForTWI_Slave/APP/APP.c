/*
 * APP.c
 *
 *  Created on: Aug 6, 2021
 *      Author: zoldeyck
 */
#include "../Infrastructure/LIB/STD_TYPES.h"
#include "../Infrastructure/LIB/Bit Operations.h"
#include "../MCAL/DIO/DIO_DRIVER.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/TWI/TWI.h"
#include "APP.h"

uint8_t character = 0;

void APP_Init()
{
	DIO_SetPinDirection(PORTA, PIN0, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN1, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN2, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN3, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN4, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN5, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN6, PIN_OUTPUT);
	DIO_SetPinDirection(PORTA, PIN7, PIN_OUTPUT);
	UART_Init(UARTChannel_1);
	TWI_Init(TWI_Channel_1);
	TWI_EnableACK();
}
void APP_Start()
{
		if(TWI_GetStatus() == TW_SR_SLA_ACK)
		{
			while(TWI_ReadDataWithACK(TWI_Channel_1,&character)!=OperationSuccess);
			if (TWI_GetStatus() == TW_SR_DATA_ACK)
			{
				DIO_WritePin(PORTA, PIN0, READ_BIT(character, 0));
				DIO_WritePin(PORTA, PIN1, READ_BIT(character, 1));
				DIO_WritePin(PORTA, PIN2, READ_BIT(character, 2));
				DIO_WritePin(PORTA, PIN3, READ_BIT(character, 3));
				DIO_WritePin(PORTA, PIN4, READ_BIT(character, 4));
				DIO_WritePin(PORTA, PIN5, READ_BIT(character, 5));
				DIO_WritePin(PORTA, PIN6, READ_BIT(character, 6));
				DIO_WritePin(PORTA, PIN7, READ_BIT(character, 7));
			}
		}


}
