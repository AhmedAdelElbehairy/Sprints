/*
 * main.c
 *
 *  Created on: Jul 9, 2021
 *      Author: zoldeyck
 */
#define F_CPU 8000000UL
#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "Mcal/DIO/DIO_DRIVER_TypeDef.h"
#include "Mcal/DIO/DIO_DRIVER.h"
#include "Mcal/TIM/TIMER_DRIVER_typedefs.h"
#include "Mcal/TIM/TIMER_DRIVER.h"
#include "Mcal/TIM/TIMER_DRIVER_typedefs.h"
#include "Mcal/TIM/TIMER_DRIVER.h"
#include"APP/APP.h"

int main()
{

	APP_init(TIMER0,PORTA,PIN0);

	while(1)
	{
		APP_start(1000);
	}


	return 0;
}
