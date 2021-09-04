/*
 * APP.c
 *
 *  Created on: Jul 25, 2021
 *      Author: zoldeyck
 */
#include "../Infrastructure/LIB/STD_TYPES.h"
#include "../Infrastructure/LIB/Bit Operations.h"
#include "../MCAL/UART/UART.h"
#include "APP.h"
void APP_Init()
{
	UART_Init(UARTChannel_1);
}
void APP_Start(ptr_uint8_t chararr)
{
	UART_ReceiveString(UARTChannel_1, chararr);
	UART_TransmitString(UARTChannel_1, chararr);
}
