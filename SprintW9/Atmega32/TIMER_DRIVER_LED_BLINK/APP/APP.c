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
#include "../Mcal/TIM/TIMER_DRIVER_typedefs.h"
#include "../Mcal/TIM/TIMER_DRIVER.h"
#include"APP.h"

DIO_PORT_ID_t static LED_PORT;
DIO_PIN_ID_t static LED_PIN;
TIM_SELECT_t TIMER;
void APP_init(TIM_SELECT_t timer, DIO_PORT_ID_t led_port, DIO_PIN_ID_t led_pin)
{
	led_init(led_port, led_pin);
	LED_PORT=led_port;	LED_PIN=led_pin;
	TIMER=timer;

}

void APP_start(uint32_t delay)
{
	TIM_Delay_MS(TIMER, delay);
	led_togling(LED_PORT, LED_PIN);
}
