/*
 * LED.h
 *
 *  Created on: Jul 12, 2021
 *      Author: Ahmed Adel
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "DIO.h"

void LED_Init(uint8_t port, uint8_t pin);
void LED_Toggle(uint8_t port, uint8_t pin);

#endif /* HAL_LED_LED_H_ */
