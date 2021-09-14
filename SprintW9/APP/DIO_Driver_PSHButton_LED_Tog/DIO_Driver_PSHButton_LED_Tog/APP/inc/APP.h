/*
 * APP.h
 *
 *  Created on: Jul 12, 2021
 *      Author: zoldeyck
 */

#ifndef APP_APP_H_
#define APP_APP_H_

void APP_init(DIO_PORT_ID_t button_port, DIO_PIN_ID_t button_pin,
		DIO_PORT_ID_t led_port, DIO_PIN_ID_t led_pin);
void APP_start();

#endif /* APP_APP_H_ */
