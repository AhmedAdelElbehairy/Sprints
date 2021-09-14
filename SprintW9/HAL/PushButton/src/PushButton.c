/*
 * PushButton.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Ahmed Adel
 */

#include "PUSHBUTTON.h"

uint8_t PSHBTTN_Init (uint8_t port, uint8_t pin, uint8_t status)
{
	uint8_t retVal = OperationSuccess;
	retVal |= DIO_PinInit(port, pin, PIN_INPUT);
	if (!status)
		retVal |= PSHBTTN_EnablePullUp(port, pin);
	return retVal;
}
uint8_t PSHBTTN_EnablePullUp(uint8_t port, uint8_t pin)
{
	uint8_t retVal = OperationSuccess;
	retVal |= DIO_PinEnablePullUp(port,pin);
	retVal = retVal;
	return retVal;
}
uint8_t PSHBTTN_Status (uint8_t port, uint8_t pin, uint8_t* status)
{
	uint8_t retVal = OperationSuccess;
	uint8_t FunRetVal = 0;
	retVal |= DIO_GetPinVal(port, pin, &FunRetVal);
	if (FunRetVal == 0)
	{
		for(volatile uint16_t i=0; i<1000; i++)
		{
			for(volatile uint8_t j=0; j<16; j++)
			{
				for(volatile uint8_t k=0; k<20; k++);}}//dummy delay for 20ms
		retVal |= DIO_GetPinVal(port, pin, &FunRetVal);
	}
	*status = FunRetVal;
	return retVal;
}
