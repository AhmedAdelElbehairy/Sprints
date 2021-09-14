#ifndef __DIO_DRIVER_H__
	#define __DIO_DRIVER_H__
	
	#include "MC_REGISTERS.h"
	#include "LIB.h"
	
	#define PIN0		(uint8_t)(0)
	#define PIN1		(uint8_t)(1)
	#define PIN2		(uint8_t)(2)
	#define PIN3		(uint8_t)(3)
	#define PIN4		(uint8_t)(4)
	#define PIN5		(uint8_t)(5)
	#define PIN6		(uint8_t)(6)
	#define PIN7		(uint8_t)(7)
	
	#define PORT_A		(uint8_t)(1)
	#define PORT_B		(uint8_t)(2)
	#define PORT_C		(uint8_t)(3)
	#define PORT_D		(uint8_t)(4)
	
	#define PIN_INPUT	(uint8_t)(0)
	#define PIN_OUTPUT	(uint8_t)(1)
	
	#define PIN_LOW		(uint8_t)(0) 
	#define PIN_HIGH	(uint8_t)(1)
	
	#define PORT_INPUT	(uint8_t)(0x00)
	#define PORT_OUTPUT	(uint8_t)(0xFF)
	
	#define PORT_LOW	(uint8_t)(0x00)
	#define PORT_HIGH	(uint8_t)(0xFF)
		
	
	uint8_t DIO_PortInit (uint8_t port, uint8_t direction);
	uint8_t DIO_PinInit (uint8_t port, uint8_t pin, uint8_t direction);
	uint8_t DIO_PinEnablePullUp (uint8_t port, uint8_t pin);
	uint8_t DIO_SetPortVal (uint8_t port, uint8_t value);
	uint8_t DIO_SetPinVal (uint8_t port, uint8_t pin, uint8_t value);
	uint8_t DIO_GetPortVal(uint8_t DIO_port, uint8_t* PortVal);
	uint8_t DIO_GetPinVal(uint8_t DIO_port, uint8_t DIO_pin, uint8_t *PinVal);
	uint8_t DIO_TogPortVal (uint8_t DIO_port , uint8_t value);
	uint8_t DIO_TogPinVal (uint8_t DIO_port, uint8_t DIO_pin);
	
#endif
