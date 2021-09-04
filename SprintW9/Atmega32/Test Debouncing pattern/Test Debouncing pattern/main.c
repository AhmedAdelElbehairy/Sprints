/*
 * Test Debouncing pattern.c
 *
 * Created: 8/23/2021 11:12:17 AM
 * Author : vetmo
 */ 

#include "STD_TYPES.h"
#include "Bit Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
#include "DEBOUNCER.h"
#include "SWITCH.h"



int main(void)
{
	extern volatile uint8_t Switch_FinaL_state;
	DIO_PinInit(PORTA,PIN1,PIN_OUTPUT);
	STR_Switch_t me;
	SWITCH_Constructor(&me, PORTA, PIN0, PIN_HIGH);
    while (1) 
    {
		SWITCH_Main(&me);
		if(Switch_FinaL_state)
		{
			DIO_SetPinVal(PORTA,PIN1,PIN_LOW);
		}
		else
		{
			DIO_SetPinVal(PORTA,PIN1,PIN_HIGH);
		}
    }
}

