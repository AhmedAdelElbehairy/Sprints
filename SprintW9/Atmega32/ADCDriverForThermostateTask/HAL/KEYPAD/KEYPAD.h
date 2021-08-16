/*
 * KEYPAD.h
 *
 *  Created on: Jul 26, 2021
 *      Author: zoldeyck
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#define Column_Port

//#define KPAD_PORT PORTB
#define KPAD_ROW_PORT PORTB
#define KPAD_COLUMN_PORT PORTB

#define KPAD_ROW0 PIN0
#define KPAD_ROW1 PIN1
#define KPAD_ROW2 PIN2
#define KPAD_ROW3 PIN3

#define KPAD_COLUMN0 PIN4
#define KPAD_COLUMN1 PIN5
#define KPAD_COLUMN2 PIN6
#define KPAD_COLUMN3 PIN7
/******macros******/
#define KPAD_SW1 0
#define KPAD_SW2 1
#define KPAD_SW3 2
#define KPAD_SW4 3
#define KPAD_SW5 4
#define KPAD_SW6 5
#define KPAD_SW7 6
#define KPAD_SW8 7
#define KPAD_SW9 8
#define KPAD_SW10 9
#define KPAD_SW11 10
#define KPAD_SW12 11
#define KPAD_SW13 12
#define KPAD_SW14 13
#define KPAD_SW15 14
#define KPAD_SW16 15
/*macro that will be returned in
 *case no key is pressed on keypad*/
#define KPAD_NO_KPRESSED 0xff

/******functions******/
void KPAD_vidInit(void);
uint8_t KPAD_GetKey(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
