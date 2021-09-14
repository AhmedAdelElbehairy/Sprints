/*
 * APP.h
 *
 *  Created on: Jul 12, 2021
 *      Author: Ahmed Adel
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "LED.h"
#include "PUSHBUTTON.h"

void APP_init(uint8_t button_port, uint8_t button_pin, uint8_t led_port, uint8_t led_pin);
void APP_start();

#endif /* APP_APP_H_ */
