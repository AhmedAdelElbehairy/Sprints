/*
 * APP.c
 *
 *  Created on: Jul 12, 2021
 *      Author: Ahmed Adel
 */

#include"APP.h"

uint8_t static BUTTON_PORT;
uint8_t static BUTTON_PIN;
uint8_t static LED_PORT;
uint8_t static LED_PIN;
void APP_init(uint8_t button_port, uint8_t button_pin, uint8_t led_port, uint8_t led_pin)
{
	LED_Init(led_port, led_pin);
	PSHBTTN_Init(button_port, button_pin, PULLED_UP);
	BUTTON_PORT=button_port;	
	BUTTON_PIN=button_pin;
	LED_PORT=led_port;	
	LED_PIN=led_pin;

}

void APP_start()
{
	uint8_t status = 0;
	PSHBTTN_Status (BUTTON_PORT, BUTTON_PIN, &status);
	if(status == 0)
	{
		while(status == 0)
		{
			PSHBTTN_Status (BUTTON_PORT, BUTTON_PIN, &status);
		}
		LED_Toggle(LED_PORT, LED_PIN);
	}
}
