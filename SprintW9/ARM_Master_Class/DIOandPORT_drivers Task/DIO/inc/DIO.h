/*
 * File Name: DIO.h
 *
 */ 

#ifndef __DIO__
#define __DIO__

//FILES INCLUDING
#include "TM4C123GH6PM.h"
#include "CPU.h"

//PORTS NAME
typedef enum
{
	PORT_A = 0,
	PORT_B = 1,
	PORT_C = 2,
	PORT_D = 3,
	PORT_E = 4,
	PORT_F = 5
}DIO_PORT_t;

//PINS
typedef enum 
{
	Channel_A0 = 0,	
	Channel_A1 = 1,
	Channel_A2 = 2,
	Channel_A3 = 3,
	Channel_A4 = 4,
	Channel_A5 = 5,
	Channel_A6 = 6,
	Channel_A7 = 7,
	Channel_B0 = 8,	
	Channel_B1 = 9,
	Channel_B2 = 10,
	Channel_B3 = 11,
	Channel_B4 = 12,
	Channel_B5 = 13,
	Channel_B6 = 14,
	Channel_B7 = 15,
	Channel_C0 = 16,	/*JTAG/SWD SIGNALS writing Changing their functionality may lock the controller*/
	Channel_C1 = 17, /*JTAG/SWD SIGNALS writing Changing their functionality may lock the controller*/
	Channel_C2 = 18, /*JTAG/SWD SIGNALS writing Changing their functionality may lock the controller*/
	Channel_C3 = 19, /*JTAG/SWD SIGNALS writing Changing their functionality may lock the controller*/
	Channel_C4 = 20,
	Channel_C5 = 21,
	Channel_C6 = 22,
	Channel_C7 = 23,
	Channel_D0 = 24,	/*can be used as NMI need CR to be configured*/
	Channel_D1 = 25,
	Channel_D2 = 26,
	Channel_D3 = 27,
	Channel_D4 = 28,
	Channel_D5 = 29,
	Channel_D6 = 30,
	Channel_D7 = 31,
	Channel_E0 = 32,	
	Channel_E1 = 33,
	Channel_E2 = 34,
	Channel_E3 = 35,
	Channel_E4 = 36,
	Channel_E5 = 37,
	Reserved_0 = 38,
	Reserved_1 = 39,
	Channel_F0 = 40,	/*can be used as NMI need CR to be configured*/
	Channel_F1 = 41,
	Channel_F2 = 42,
	Channel_F3 = 43,
	Channel_F4 = 44,
	Reserved_2 = 45,
	Reserved_3 = 46,
	Reserved_4 = 47,
}DIO_CHANNEL_t;

//PIN Directions
typedef enum 
{
	DIO_PIN_LOW = 0,
	DIO_PIN_HIGH = 1
}DIO_CHANNEL_LEVEL_t;

typedef uint8_t DIO_PORT_LEVEL_t;
//Data register for ports

//FUNCTIONS PROTOTYPES
/*Channels prototypes*/
DIO_CHANNEL_LEVEL_t DIO_FlipChannel(DIO_CHANNEL_t);
DIO_CHANNEL_LEVEL_t DIO_ReadChannel(DIO_CHANNEL_t);
void DIO_WriteChannel(DIO_CHANNEL_t, DIO_CHANNEL_LEVEL_t);
/*Port ProtoTypes*/
DIO_PORT_LEVEL_t DIO_ReadPort(DIO_PORT_t);
void DIO_WritePort(DIO_PORT_t, DIO_PORT_LEVEL_t);

#endif
