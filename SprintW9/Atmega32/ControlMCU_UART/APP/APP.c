/*
 * APP.c
 *
 *  Created on: Jul 25, 2021
 *      Author: zoldeyck
 */
#include "../Infrastructure/LIB/STD_TYPES.h"
#include "../Infrastructure/LIB/Bit Operations.h"
#include "../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../MCAL/DIO/DIO_DRIVER.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/LED/LED.h"
#include "APP.h"
uint8_t chararr[255]="ahmed";
uint8_t *words[4]= {(uint8_t*)"START",(uint8_t*)"STOP",(uint8_t*)"WAIT",(uint8_t*)"AT"};
void APP_Init()
{
	UART_Init(UARTChannel_1);
	led_init(LEDS_PORT, RED_LED_PIN);
	led_init(LEDS_PORT, YELLOW_LED_PIN);
	led_init(LEDS_PORT, GREEN_LED_PIN);
	LED_Off(LEDS_PORT,GREEN_LED_PIN);
	LED_Off(LEDS_PORT,YELLOW_LED_PIN);
	LED_Off(LEDS_PORT,RED_LED_PIN);
}
void APP_Start()
{
	uint8_t state;
	while(UART_ReceiveString(UARTChannel_1, chararr)!= OperationSuccess);
	state = String_CMP(chararr,words);
	switch(state)
	{
	case 0:
		LED_On(LEDS_PORT,GREEN_LED_PIN);
		LED_Off(LEDS_PORT,YELLOW_LED_PIN);
		LED_Off(LEDS_PORT,RED_LED_PIN);
		while(UART_TransmitString(UARTChannel_1, (uint8_t*)"Green LED is on")!=OperationSuccess);
		break;
	case 1:
		LED_Off(LEDS_PORT,GREEN_LED_PIN);
		LED_Off(LEDS_PORT,YELLOW_LED_PIN);
		LED_On(LEDS_PORT,RED_LED_PIN);
		while(UART_TransmitString(UARTChannel_1, (uint8_t*)"Red LED is on")!=OperationSuccess);
		break;
	case 2:
		LED_Off(LEDS_PORT,GREEN_LED_PIN);
		LED_On(LEDS_PORT,YELLOW_LED_PIN);
		LED_Off(LEDS_PORT,RED_LED_PIN);
		while(UART_TransmitString(UARTChannel_1, (uint8_t*)"Yellow LED is on")!=OperationSuccess);
		break;
	case 3:
		LED_Off(LEDS_PORT,GREEN_LED_PIN);
		LED_Off(LEDS_PORT,YELLOW_LED_PIN);
		LED_Off(LEDS_PORT,RED_LED_PIN);
		while(UART_TransmitString(UARTChannel_1, (uint8_t*)"OK")!=OperationSuccess);
		break;
	default:
		break;
	}
}
uint8_t String_CMP(ptr_uint8_t arrayofcharacters, ptr_uint8_t *arrayofwords)//String compare
{
	for(uint8_t Iterator = 0; Iterator <= 3; Iterator++) {
			for(uint8_t Iterator1 = 0; Iterator1 <= 255; Iterator1++)
			{
				if(arrayofcharacters[Iterator1]==arrayofwords[Iterator][Iterator1])
				{
//					if(Iterator==0)
//						while(UART_TransmitString(UARTChannel_1, (uint8_t*)"iterating")!=OperationSuccess);
					if(arrayofcharacters[Iterator1]=='\0'&&arrayofwords[Iterator][Iterator1]=='\0')
						return Iterator;

					else
						continue;
				}
				else
				{
					if(arrayofcharacters[Iterator1]=='\0'||arrayofwords[Iterator][Iterator1]=='\0')
						break;
					break;
				}
			}
	}

}
