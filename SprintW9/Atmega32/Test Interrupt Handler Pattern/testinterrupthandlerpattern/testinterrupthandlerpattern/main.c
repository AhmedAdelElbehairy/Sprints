/*
 * testinterrupthandlerpattern.c
 *
 * Created: 8/22/2021 9:39:36 PM
 * Author : vetmo
 */ 
#define F_CPU 8000000UL
#define NULL_PTR (void*)0
#include "STD_TYPES.h"
#include "Bit_Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
#include "InterruptVectorTable.h"
#include "InterruptHandler.h"
#define MCUCR  *((volatile uint8_t*)0x55)
#define MCUCSR   *((volatile uint8_t*)0x54)
#define GICR   *((volatile uint8_t*)0x5B)
#define STATUS_REG	*((volatile uint8_t*)0x5F)//SREG
uint8_t counter = 0;
void task1()
{
	if(counter<=5)
	{
		counter++;
		DIO_TogPinVal(PORTA,PIN0);
	}
	else
	{
		DIO_TogPinVal(PORTA,PIN1);
	}
	
}
int main(void)
{
	/*initialize pin for switch*/
	DIO_PinInit(PORTD,PIN2,PIN_INPUT);
	DIO_PinEnablePullUp(PORTD,PIN2);
	/*initialize pin for LED*/
	DIO_PinInit(PORTA,PIN0,PIN_OUTPUT);
	DIO_PinInit(PORTA,PIN1,PIN_OUTPUT);
	/*enable global interrupt*/
	STATUS_REG |= 0x80;
    /* Replace with your application code */
	MCUCR &= 0xFC;/*clearing*/
	MCUCR |= 0x02;/*setting fall edge as trigerring edge*/
	GICR  |= 0x40;/*enable external interrupt*/
	Install(1,task1);
    while (1) 
    {
    }
}

