/*
 * TWI.h
 *
 *  Created on: Aug 3, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_TWI_TWI_H_
#define MCAL_TWI_TWI_H_
/*File includes*/
#include "TWI_PRIV.h"
#include "TWI_CONFIG.h"
/*Functions Prototypes*/
uint8_t TWI_Init(uint8_t TWI_channel);
uint8_t TWI_WriteChar(uint8_t TWI_channel, uint8_t SlaveAdrress, uint8_t internalAdrress, uint8_t Data);
uint8_t TWI_ReadChar(uint8_t TWI_channel, uint8_t SlaveAdrress, uint8_t internalAdrress, ptr_uint8_t Data);

uint8_t TWI_SendStartCondition(uint8_t TWI_channel);
uint8_t TWI_GetStatus();
uint8_t TWI_SendStopCondition(uint8_t TWI_channel);
uint8_t TWI_WriteData(uint8_t TWI_channel, uint8_t Data);
uint8_t TWI_ReadDataWithACK(uint8_t TWI_channel, ptr_uint8_t Data);
uint8_t TWI_ReadDataWithNACK(uint8_t TWI_channel, ptr_uint8_t Data);
void TWI_EnableACK();
#endif /* MCAL_TWI_TWI_H_ */
