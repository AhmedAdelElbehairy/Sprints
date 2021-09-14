/*
 * LED.h
 *
 *  Created on: Jul 12, 2021
 *      Author: zoldeyck
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

void led_init(DIO_PORT_ID_t port, DIO_PIN_ID_t pin);
void led_togling(DIO_PORT_ID_t port, DIO_PIN_ID_t pin);

#endif /* HAL_LED_LED_H_ */
