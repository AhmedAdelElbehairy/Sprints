/*
 * EEPROM.c
 *
 *  Created on: Aug 5, 2021
 *      Author: zoldeyck
 */
#include "../../Infrastructure/LIB/STD_TYPES.h"
#include "../../Infrastructure/LIB/Bit Operations.h"
#include "../../MCAL/TWI/TWI.h"
#include "../../MCAL/UART/UART.h"
#include "EEPROM_CONFIG.h"


uint8_t EEPROM_Init()
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = TWI_Init(TWI_Channel_1);
	return ErrRetVal;
}
uint8_t EEPROM_ReadByte(uint8_t* Character, uint16_t ByteAddress)
{
	uint8_t ErrRetVal = OperationStarted;
	/*Send Start Condition*/
	while(TWI_SendStartCondition(TWI_Channel_1)!=OperationSuccess);
	/*Check status for start condition fired correctly*/
	if(TWI_GetStatus()==TW_START)
	{
	/*Send Slave Address with Write Bit*/
		switch(EEPROM_SIZE)
		{
		case EEPROM_SIZE_1K:
		case EEPROM_SIZE_2K:
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|EEPROM_A0<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		case EEPROM_SIZE_4K://A0 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		case EEPROM_SIZE_8K://A0,A1 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|READ_BIT(ByteAddress,10)<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		case EEPROM_SIZE_16K://A0,A1,A2 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|READ_BIT(ByteAddress,11)<<3|READ_BIT(ByteAddress,10)<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		default:
			ErrRetVal=OperationFail;
		}
		if(TWI_GetStatus() == TW_MT_SLA_ACK)
		{
			/*Sending the byte Address*/
			while(TWI_WriteData(TWI_Channel_1,0b00000000|ByteAddress)!=OperationSuccess);
			if (TWI_GetStatus() == TW_MT_DATA_ACK)
			{
				/*Send Repeated Start*/
				while(TWI_SendStartCondition(TWI_Channel_1)!=OperationSuccess);
				if(TWI_GetStatus() == TW_REP_START)
				{
					/*send slave address with read bit*/
					switch(EEPROM_SIZE)
					{
					case EEPROM_SIZE_1K:
					case EEPROM_SIZE_2K:
						while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|EEPROM_A0<<1|EEPROM_READ)!=OperationSuccess);
						break;
					case EEPROM_SIZE_4K://A0 are from Byte Address
						while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_READ)!=OperationSuccess);
						break;
					case EEPROM_SIZE_8K://A0,A1 are from Byte Address
						while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|READ_BIT(ByteAddress,10)<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_READ)!=OperationSuccess);
						break;
					case EEPROM_SIZE_16K://A0,A1,A2 are from Byte Address
						while(TWI_WriteData(TWI_Channel_1,0b10100000|READ_BIT(ByteAddress,11)<<3|READ_BIT(ByteAddress,10)<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_READ)!=OperationSuccess);
						break;
					default:
						ErrRetVal=OperationFail;
					}
					if(TWI_GetStatus() == TW_MR_SLA_ACK)
					{
						while(TWI_ReadDataWithNACK(TWI_Channel_1,Character)!=OperationSuccess);
						if(TWI_GetStatus() == TW_MR_DATA_NACK)
						{
							while (TWI_SendStopCondition(TWI_Channel_1)!= OperationSuccess);
							ErrRetVal = OperationSuccess;//may be we should first check if value of ErrRetVal != OperationFail
						}
						else
						{
							ErrRetVal = OperationFail;
						}
					}
					else
					{
						ErrRetVal = OperationFail;
					}
				}
				else
				{
					ErrRetVal = OperationFail;
				}
			}
			else
			{
				ErrRetVal = OperationFail;
			}
		}
		else
		{
			ErrRetVal = OperationFail;
		}
	}
	else
	{
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
uint8_t EEPROM_WriteByte(uint8_t Character, uint16_t ByteAddress)
{
	uint8_t ErrRetVal = OperationStarted;
	/*Send Start Condition*/
	while(TWI_SendStartCondition(TWI_Channel_1)!=OperationSuccess);
	/*Check status for start condition fired correctly*/
	if(TWI_GetStatus()==TW_START)
	{
		/*Send Slave Address with Write Bit*/
		switch(EEPROM_SIZE)
		{
		case EEPROM_SIZE_1K:
		case EEPROM_SIZE_2K:
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|EEPROM_A0<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		case EEPROM_SIZE_4K://A0 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|EEPROM_A1<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		case EEPROM_SIZE_8K://A0,A1 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|EEPROM_A2<<3|READ_BIT(ByteAddress,9)<<2|READ_BIT(ByteAddress,8)<<1|EEPROM_WRITE<<0)!=OperationSuccess);
			break;
		case EEPROM_SIZE_16K://A0,A1,A2 are from Byte Address
			while(TWI_WriteData(TWI_Channel_1,0b10100000|READ_BIT(ByteAddress,11)<<3|READ_BIT(ByteAddress,10)<<2|READ_BIT(ByteAddress,9)<<1|EEPROM_WRITE)!=OperationSuccess);
			break;
		default:
			ErrRetVal=OperationFail;
		}
		if(TWI_GetStatus() == TW_MT_SLA_ACK)
		{
			/*Sending the byte Address*/
			while(TWI_WriteData(TWI_Channel_1,0b00000000|ByteAddress)!=OperationSuccess);
			if (TWI_GetStatus() == TW_MT_DATA_ACK)
			{
				/*sending the data Byte*/
				while(TWI_WriteData(TWI_Channel_1,Character)!=OperationSuccess);
				if (TWI_GetStatus() == TW_MT_DATA_ACK)
				{
					while (TWI_SendStopCondition(TWI_Channel_1)!= OperationSuccess);
					ErrRetVal = OperationSuccess;
				}
				else
				{
					ErrRetVal=OperationFail;
				}
			}
			else
			{
				ErrRetVal=OperationFail;
			}
		}
		else
		{
			ErrRetVal=OperationFail;
		}
	}
	else
	{
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
