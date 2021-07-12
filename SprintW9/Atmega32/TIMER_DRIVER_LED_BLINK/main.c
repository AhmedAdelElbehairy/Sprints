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
void led_toggle();

int main()
{
	DIO_PortInit(PORTC,PORT_OUTPUT);
	DIO_PinInit(PORTA, PIN0, PIN_OUTPUT);
	TIM_Init(TIMER0, _SYSCLK, Normal, CO_TOGGLE_MODE, 0, 255);
	TIM_SetTimerOVFAction(TIMER0,&led_toggle);
	TIM_Interrupt_Enable(TIMER0, TIM0OVF);



//	DIO_SetPortVal(PORTC, DDRB_Register);
	while(1)
	{
		TIM_SetTimerOVFAction(TIMER0,led_toggle);
	}
//	DIO_SetPortVal(PORTB, 15);

//	while(1);
//	DIO_PortInit(PORTB, PORT_OUTPUT);
//	MODIFY_REG(PORTB_Register,x,x);


	return 0;
}
void led_toggle()
{
	DIO_TogPinVal(PORTA,PIN0);
}
