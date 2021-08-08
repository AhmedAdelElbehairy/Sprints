/*
 * APP.h
 *
 *  Created on: Jul 25, 2021
 *      Author: zoldeyck
 */

#ifndef APP_APP_H_
#define APP_APP_H_

void APP_Init();
void APP_Start();
uint8_t String_CMP(ptr_uint8_t arrayofcharacters, ptr_uint8_t *arrayofwords);
#define LEDS_PORT PORTA
#define RED_LED_PIN PIN2
#define YELLOW_LED_PIN PIN1
#define GREEN_LED_PIN PIN0

#endif /* APP_APP_H_ */
