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
	DIO_SetPinDirection(port, pin, PIN_OUTPUT);
}
void led_togling(DIO_PORT_ID_t port, DIO_PIN_ID_t pin)
{
	DIO_TogglePin(port, pin);
}
void LED_On(DIO_PORT_ID_t port, DIO_PIN_ID_t pin){
DIO_WritePin(port, pin, PIN_HIGH);
}
void LED_Off(DIO_PORT_ID_t port, DIO_PIN_ID_t pin){
	DIO_WritePin(port, pin, PIN_LOW);
}
