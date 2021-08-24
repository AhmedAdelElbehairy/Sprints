/*
 * Master_APP.c
 *
 *  Created on: Jul 26, 2021
 *      Author: zoldeyck
 */
#include "../Infrastructure/LIB/STD_TYPES.h"
#include "../Infrastructure/LIB/Bit Operations.h"
#include "../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../MCAL/DIO/DIO_DRIVER.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/SPI/SPI.h"
#include "APP_2.h"

uint8_t character = 0;
uint8_t dummy = 0;
void APP2_Init() {
	switch (SPI_Mode) {
	case Master:
		UART_Init(UARTChannel_1);
		SPI_Init(SPIChannel_1);
		break;
	case Slave:
		SPI_Init(SPIChannel_1);
		DIO_PortInit(PORTD,PORT_OUTPUT);
		DIO_SetPortVal(PORTD, PORT_LOW);
		break;
	}
}
void APP2_Start() {
	switch (SPI_Mode) {
	case Master:
		while (UART_ReceiveChar(UARTChannel_1, &character) != OperationSuccess);
		SPI_TransmitChar(SPIChannel_1, character, SlaveID_1);
		while(SPI_ReceiveChar(SPIChannel_1, &dummy, SlaveID_1) != OperationSuccess) ;
		break;
	case Slave:
		while (SPI_TransmitChar(SPIChannel_1, dummy, SlaveID_1) != OperationSuccess);
		while (SPI_ReceiveChar(SPIChannel_1, &character, SlaveID_1)	!= OperationSuccess);
		DIO_SetPortVal(PORTD, character);
		break;
	}
}
