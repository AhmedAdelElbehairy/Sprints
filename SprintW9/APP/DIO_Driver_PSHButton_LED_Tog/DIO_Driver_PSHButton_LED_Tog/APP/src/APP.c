/*
 * APP.c
 *
 *  Created on: Jul 12, 2021
 *      Author: zoldeyck
 */
#include "../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../MCAL/DIO/DIO_DRIVER.h"
#include "../HAL/LED/LED.h"
#include "../HAL/PushButton/PushButton_TypeDef.h"
#include "../HAL/PushButton/PushButton.h"
#include"APP.h"
DIO_PORT_ID_t static BUTTON_PORT;
DIO_PIN_ID_t static BUTTON_PIN;
DIO_PORT_ID_t static LED_PORT;
DIO_PIN_ID_t static LED_PIN;
void APP_init(DIO_PORT_ID_t button_port, DIO_PIN_ID_t button_pin,
		DIO_PORT_ID_t led_port, DIO_PIN_ID_t led_pin)
{
	led_init(led_port, led_pin);
	PSHBTTN_Init(button_port, button_pin, PULLED_UP);
	BUTTON_PORT=button_port;	BUTTON_PIN=button_pin;
	LED_PORT=led_port;	LED_PIN=led_pin;

}

void APP_start()
{
	if(PSHBTTN_Status(BUTTON_PORT, BUTTON_PIN)==0)
	{
		while(PSHBTTN_Status(BUTTON_PORT, BUTTON_PIN)==0);
		led_togling(LED_PORT, LED_PIN);
	}
}
