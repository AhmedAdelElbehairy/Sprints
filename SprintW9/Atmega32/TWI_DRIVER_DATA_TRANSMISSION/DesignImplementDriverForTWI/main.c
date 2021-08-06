/*
 * main.c
 *
 *  Created on: Jul 15, 2021
 *      Author: Ahmed
 */
#define F_CPU 8000000UL
#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "MCAL/UART/UART.h"
#include "MCAL/TWI/TWI.h"
#include "APP/APP.h"

int main()
{
	APP_Init();
	while (1) {
		APP_Start();
	}
	return 0;
}
