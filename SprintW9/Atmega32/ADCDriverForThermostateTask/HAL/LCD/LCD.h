/*
 * LCD.h
 *
 *  Created on: Jul 31, 2021
 *      Author: zoldeyck
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#define LCD_CLR           		     0x01
#define LCD_HOME          		     0x02          /* return cursor to first position on first line*/
#define LCD_INCREMENTENTRYMODE     	 0x06
#define LCD_SHIFTINCREMENTENTRYMODE  0x07
#define LCD_DECREMENTENTRYMODE  	 0x04
#define LCD_SHIFTDECREMENTENTRYMODE  0x05
#define LCD_DISPOFF       			 0x08          // turn display off
#define LCD_DISPON_CURSON 			 0x0E          // display on, cursor on, don't blink character
#define LCD_DISPON_CURSOFF 			 0x0C          // display on, cursor off, don't blink character
#define LCD_DISPON_CURSBLINK		 0x0F          //display on , cursor blinking
#define LCD_FUNCSET_1     			 0x30          // 8-bit data, 1-line display, 5 x 7 font
#define LCD_FUNCSET_2     			 0x34          // 8-bit data, 1-line display, 5 x 10 font
#define LCD_FUNCSET_3   			 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_FUNCSET_4     			 0x20          // 4-bit data, 1-line display, 5 x 7 font
#define LCD_FUNCSET_5     			 0x24          // 4-bit data, 1-line display, 5 x 10 font
#define LCD_FUNCSET_6   			 0x28          // 4-bit data, 2-line display, 5 x 7 font
#define LCD_Init_CMD_1				 0x33
#define LCD_Init_CMD_2				 0x32
#define LCD_CURS_Position0			 0x80

#define LCD_PORT PORTC
#define LCD_RS PIN6
#define LCD_RW PIN5
#define LCD_EN PIN4
#define LCD_D7 PIN3
#define LCD_D6 PIN2
#define LCD_D5 PIN1
#define LCD_D4 PIN0
#define LCD_D7_MSK 1<<LCD_D7
#define LCD_D6_MSK 1<<LCD_D6
#define LCD_D5_MSK 1<<LCD_D5
#define LCD_D4_MSK 1<<LCD_D4

#define OperationSuccess 											0
#define OperationFail 												1
#define OperationRunning											2
#define OperationStarted 											255

void LCD_SendCharacter(uint8_t Character);
void LCD_SendCommand(uint8_t CMD);
void LCD_Init();
void LCD_SendString(uint8_t* String);
void LCD_NumberToString(uint16_t Number, uint8_t* String);
void LCD_StringReverse(uint8_t* String);
void LCD_SendNumber(uint16_t Number);
uint8_t LCD_ReadBusyFlag();

#endif /* HAL_LCD_LCD_H_ */
