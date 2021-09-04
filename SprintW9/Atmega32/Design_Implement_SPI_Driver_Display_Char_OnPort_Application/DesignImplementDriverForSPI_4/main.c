/*
 * main.c
 *
 *  Created on: Jul 17, 2021
 *      Author: zoldeyck
 */
#define F_CPU 8000000UL
#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "MCAL/DIO/DIO_DRIVER.h"
#include "MCAL/UART/UART.h"
#include "MCAL/SPI/SPI.h"
#include "APP/APP_2.h"
int main() {
	APP2_Init();
	while (1)
	{
		APP2_Start();
	}
	return 0;
}
