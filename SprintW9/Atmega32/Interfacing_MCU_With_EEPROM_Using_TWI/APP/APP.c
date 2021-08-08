/*
 * APP.c
 *
 *  Created on: Aug 6, 2021
 *      Author: zoldeyck
 */
#include "../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../INFRASTRUCTURE/LIB/STRING.h"
#include "../MCAL/TWI/TWI.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/EEPROM/EEPROM_CONFIG.h"
#include "APP.h"
uint8_t writestate = 0;
uint8_t readstate = 0;
uint8_t isnumericstate = 0;
uint8_t UART_char = 0;
uint8_t DataFromEEPROM = 0;
uint8_t UART_string[255];
uint16_t ByteAddress=0;
void APP_Init()
{
	UART_Init(UARTChannel_1);
	EEPROM_Init();
}
void APP_Start()
{
	while(UART_TransmitString(UARTChannel_1,(uint8_t*)"Enter the Command")!=OperationSuccess);
	while (UART_ReceiveString(UARTChannel_1,UART_string)!=OperationSuccess);
	STR_CompareString(UART_string,(uint8_t*)"WRITE", &writestate);
	STR_CompareString(UART_string,(uint8_t*)"READ", &readstate);
	if(writestate)
	{
		while(UART_TransmitString(UARTChannel_1,(uint8_t*)"ENTER THE BYTE ADDRESS")!=OperationSuccess);
		while (UART_ReceiveString(UARTChannel_1,UART_string)!=OperationSuccess);
		STR_StringIsNumeric(UART_string,&isnumericstate);
		if(isnumericstate)
		{
			STR_String2Number(UART_string,&ByteAddress);
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"OK")!=OperationSuccess);
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"ENTER THE CHARACTER TO BE SAVED")!=OperationSuccess);
			while(UART_ReceiveChar(UARTChannel_1,&UART_char)!=OperationSuccess);
			while(UART_TransmitChar(UARTChannel_1,'\r')!=OperationSuccess);
			EEPROM_WriteByte(UART_char,ByteAddress);//ByteAddress,UART_char
		}
		else
		{
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"you entered a non-numeric address")!=OperationSuccess);
		}
	}
	else if(readstate)
	{
		while(UART_TransmitString(UARTChannel_1,(uint8_t*)"ENTER THE BYTE ADDRESS")!=OperationSuccess);
		while (UART_ReceiveString(UARTChannel_1,UART_string)!=OperationSuccess);
		STR_StringIsNumeric(UART_string,&isnumericstate);
		if(isnumericstate)
		{
			STR_String2Number(UART_string,&ByteAddress);
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"OK")!=OperationSuccess);
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"the stored data is:")!=OperationSuccess);
			EEPROM_ReadByte(&DataFromEEPROM,ByteAddress);//ByteAddress
			while(UART_TransmitChar(UARTChannel_1,DataFromEEPROM)!=OperationSuccess);
			while(UART_TransmitChar(UARTChannel_1,'\r')!=OperationSuccess);
		}
		else
		{
			while(UART_TransmitString(UARTChannel_1,(uint8_t*)"you entered a non-numeric address")!=OperationSuccess);
		}
	}
	else
	{
		while(UART_TransmitString(UARTChannel_1,(uint8_t*)"You entered invalid Command")!=OperationSuccess);
	}
}
