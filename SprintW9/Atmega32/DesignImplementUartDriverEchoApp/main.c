/*
 * main.c
 *
 *  Created on: Jul 15, 2021
 *      Author: Ahmed
 */
#define F_CPU 8000000UL
#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "MCAL/DIO/DIO_DRIVER.h"
#include "MCAL/UART/UART.h"
#include "APP/APP.h"
int main() {
	APP_Init();
	uint8_t chararr[255]="ahmed";
	while (1) {
		APP_Start(chararr);
	}
}
