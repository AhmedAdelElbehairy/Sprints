/*
 * LED.c
 *
 *  Created on: Jul 12, 2021
 *      Author: Ahmed
 */
#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "../../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../../MCAL/DIO/DIO_DRIVER.h"
#include "LED.h"


void led_init(DIO_PORT_ID_t port, DIO_PIN_ID_t pin)
{
	DIO_PinInit(port, pin, PIN_OUTPUT);
}
void led_togling(DIO_PORT_ID_t port, DIO_PIN_ID_t pin)
{
	DIO_TogPinVal(port, pin);
}

