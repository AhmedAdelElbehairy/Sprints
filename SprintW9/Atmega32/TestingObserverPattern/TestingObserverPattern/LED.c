/*
 * LED.c
 *
 * Created: 9/2/2021 3:33:55 PM
 *  Author: vetmo
 */ 

#include "LED.h"
void LED_Constructor(STR_LED_t* me, uint8_t LED_Initial_State, void(*LED_accept)(struct STR_Datum_t*))
{
	DIO_PinInit (me->PORT, me->PIN, PIN_OUTPUT);
	DIO_SetPinVal(me->PORT, me->PIN, LED_Initial_State);
	me->LED_accept = LED_accept;
}
void LED_SetVal(STR_LED_t* me, uint8_t LED_Value)
{
	DIO_SetPinVal(me->PORT, me->PIN, LED_Value);
}