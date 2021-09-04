/*
 * EEPROM_CONFIG.h
 *
 *  Created on: Aug 5, 2021
 *      Author: zoldeyck
 */

#ifndef HAL_EEPROM_EEPROM_CONFIG_H_
#define HAL_EEPROM_EEPROM_CONFIG_H_

/*Signals*/
#define EEPROM_LOW 0
#define EEPROM_HIGH 1
#define EEPROM_READ 1
#define EEPROM_WRITE 0
/*EEPROMS Sizes*/
#define EEPROM_SIZE_1K	0
#define EEPROM_SIZE_2K	1
#define EEPROM_SIZE_4K	2
#define EEPROM_SIZE_8K	3
#define EEPROM_SIZE_16K	4
#define EEPROM_SIZE		EEPROM_SIZE_8K
/*Connections of A0,A1,A2*/
#define EEPROM_A0	EEPROM_LOW
#define EEPROM_A1	EEPROM_LOW
#define EEPROM_A2	EEPROM_LOW

uint8_t EEPROM_Init();
uint8_t EEPROM_ReadByte(uint8_t* Character, uint16_t ByteAddress);
uint8_t EEPROM_WriteByte(uint8_t Character, uint16_t ByteAddress);

#endif /* HAL_EEPROM_EEPROM_CONFIG_H_ */
