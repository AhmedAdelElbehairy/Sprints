/*
 * PushButton.h
 *
 *  Created on: Jul 11, 2021
 *      Author: Ahmed Adel
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_H_

#include "DIO.h"

#define PULLED_UP	(uint8_t)(0)
#define PULLED_DWN	(uint8_t)(1)

uint8_t PSHBTTN_Init (uint8_t port, uint8_t pin, uint8_t status);
uint8_t PSHBTTN_EnablePullUp (uint8_t port, uint8_t pin);
uint8_t PSHBTTN_Status (uint8_t port, uint8_t pin, uint8_t* status);



#endif /* HAL_PUSHBUTTON_PUSHBUTTON_H_ */
