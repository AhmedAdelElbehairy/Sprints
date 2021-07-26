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

uint8_t character[255];

void APP2_Init() {
	switch (SPI_Mode) {
	case Master:
		UART_Init(UARTChannel_1);
		SPI_Init(SPIChannel_1);
		break;
	case Slave:
		UART_Init(UARTChannel_1);
		SPI_Init(SPIChannel_1);
		break;
	}
}

void APP2_Start() {
	switch (SPI_Mode) {
	case Master:
		if (UART_ReceiveString(1, character) == OperationSuccess) {
			while (SPI_TransmitString(SPIChannel_1, character, SlaveID_1)
					!= OperationSuccess)
				;
		}
		break;
	case Slave:
		if (SPI_ReceiveString(SPIChannel_1, character,
				SlaveID_1) == OperationSuccess) {
			while(UART_TransmitString(1, character)!= OperationSuccess);
		}
		break;
	}
}
