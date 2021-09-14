/*
 * LED.c
 *
 *  Created on: Jul 12, 2021
 *      Author: Ahmed Adel
 */

#include "LED.h"

void LED_Init(uint8_t port, uint8_t pin)
{
	DIO_PinInit(port, pin, PIN_OUTPUT);
}
void LED_Toggle(uint8_t port, uint8_t pin)
{
	DIO_TogPinVal(port, pin);
}

