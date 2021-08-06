/*
 * APP.c
 *
 *  Created on: Aug 6, 2021
 *      Author: zoldeyck
 */
#include "../Infrastructure/LIB/STD_TYPES.h"
#include "../Infrastructure/LIB/Bit Operations.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/TWI/TWI.h"
#include "APP.h"

uint8_t character = 0;
uint8_t slaveaddress = 0x56;

void APP_Init()
{
	UART_Init(UARTChannel_1);
	TWI_Init(TWI_Channel_1);
}
void APP_Start()
{
	/*Displaying A message to the user telling him to enter a charater*/
	while (UART_TransmitString(UARTChannel_1, (uint8_t*) "Please enter the character:")	!= OperationSuccess);
	/*Receiving the character entered by the user*/
	while (UART_ReceiveChar(UARTChannel_1, &character) != OperationSuccess);
	/*start from a new line*/
	while (UART_TransmitChar(UARTChannel_1, '\r') != OperationSuccess);
	/*using TWI Start the character transmission to the Slave MCU*/
	while (TWI_SendStartCondition(TWI_Channel_1) != OperationSuccess);
	/*Checking the status of start condition is fired correctly*/
	if (TWI_GetStatus() == TW_START)
	{
		/*Sending Slave address with write bit*/
		while (TWI_WriteData(TWI_Channel_1, (slaveaddress << 1) & 0xFE) != OperationSuccess);
		/*checking status for slave address sent and acknowledge received*/
		if (TWI_GetStatus() == TW_MT_SLA_ACK)
		{
			/*Sending the data bits of the character*/
			while (TWI_WriteData(TWI_Channel_1, character) != OperationSuccess);
			/*Checking the Status For Data sent and acknowledge received*/
			if (TWI_GetStatus() == TW_MT_DATA_ACK)
			{
				/*Terminating the transmission by sending stop condition*/
				while (TWI_SendStopCondition(TWI_Channel_1) != OperationSuccess);
			}
			else
			{
				/*Terminating the transmission by sending stop condition*/
				while (TWI_SendStopCondition(TWI_Channel_1) != OperationSuccess);
			}
		}
		else
		{
			/*Terminating the transmission by sending stop condition*/
			while (TWI_SendStopCondition(TWI_Channel_1) != OperationSuccess);
		}
	}
	else
	{
		/*Terminating the transmission by sending stop condition*/
		while (TWI_SendStopCondition(TWI_Channel_1) != OperationSuccess);
	}
}
