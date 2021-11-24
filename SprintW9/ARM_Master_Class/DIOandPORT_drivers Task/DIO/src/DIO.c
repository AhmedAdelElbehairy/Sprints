/*
 * File Name: DIO.c
 * 
 */ 
#include "DIO.h"
static volatile uint32_t *DataRegisters[6] ={
	((volatile uint32_t*)0x400043FCUL),
	((volatile uint32_t*)0x400053FCUL),
	((volatile uint32_t*)0x400063FCUL),
	((volatile uint32_t*)0x400073FCUL),
	((volatile uint32_t*)0x400243FCUL),
	((volatile uint32_t*)0x400253FCUL),
};
/*Channels prototypes*/
DIO_CHANNEL_LEVEL_t DIO_FlipChannel(DIO_CHANNEL_t Channel)
{
	DIO_CHANNEL_LEVEL_t LatestChannelValue = 0;
	TOG_BIT_ATOMIC(*(DataRegisters[Channel/8]), (Channel%8));
	LatestChannelValue = (DIO_CHANNEL_LEVEL_t)READ_BIT_ATOMIC(*(DataRegisters[Channel/8]), (Channel%8));
	return LatestChannelValue;
}
DIO_CHANNEL_LEVEL_t DIO_ReadChannel(DIO_CHANNEL_t Channel)
{
	DIO_CHANNEL_LEVEL_t LatestChannelValue = 0;
	LatestChannelValue = (DIO_CHANNEL_LEVEL_t)READ_BIT_ATOMIC(*(DataRegisters[Channel/8]), (Channel%8));
	return LatestChannelValue;
}
void DIO_WriteChannel(DIO_CHANNEL_t Channel, DIO_CHANNEL_LEVEL_t ChannelLevel)
{
	switch(ChannelLevel)
	{
		case DIO_PIN_LOW:
			CLEAR_BIT_ATOMIC(*(DataRegisters[Channel/8]), (Channel%8));
			break;
		case DIO_PIN_HIGH:
			SET_BIT_ATOMIC(*(DataRegisters[Channel/8]), (Channel%8));
			break;
	}
}
/*Port ProtoTypes*/
DIO_PORT_LEVEL_t DIO_ReadPort(DIO_PORT_t Port)
{
	DIO_PORT_LEVEL_t LatestPortValue = 0;
	LatestPortValue = (DIO_PORT_LEVEL_t)(*(DataRegisters[Port]));
	return LatestPortValue;
}
void DIO_WritePort(DIO_PORT_t Port, DIO_PORT_LEVEL_t PortLevel)
{
	(*(DataRegisters[Port])) = PortLevel;
}
