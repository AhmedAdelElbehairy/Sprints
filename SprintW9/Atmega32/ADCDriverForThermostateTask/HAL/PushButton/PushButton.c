/*
 * PushButton.c
 *
 *  Created on: Jul 11, 2021
 *      Author: zoldeyck
 */
#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "../../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../../MCAL/DIO/DIO_DRIVER.h"
#include "PushButton.h"

PSHBTTN_ERROR_RETVAL_t PSHBTTN_Init(DIO_PORT_ID_t port, DIO_PIN_ID_t pin,
		PSHBTTN_PULLUP_Status_t status){
	PSHBTTN_ERROR_RETVAL_t retVal = EXIT_SUCCESFUL;
	DIO_SetPinDirection(port, pin, PIN_INPUT);
	if (!status)
		PSHBTTN_EnablePullUp(port, pin);
	return retVal;
}
PSHBTTN_ERROR_RETVAL_t PSHBTTN_EnablePullUp(DIO_PORT_ID_t port,
		DIO_PIN_ID_t pin){
	PSHBTTN_ERROR_RETVAL_t retVal = EXIT_SUCCESFUL;
	DIO_EnablePinPullup(port,pin);
	return retVal;
}
Byte PSHBTTN_Status (DIO_PORT_ID_t port, DIO_PIN_ID_t pin){
	Byte retVal = EXIT_FAILURE;
	DIO_ReadPin(port, pin,&retVal);
	if (retVal == 0){
			for(volatile uint16_t i=0; i<1000; i++)
			{
				for(volatile uint8_t j=0; j<16; j++)
				{
					for(volatile uint8_t k=0; k<20; k++);}}//dummy delay for 20ms
			DIO_ReadPin(port, pin,&retVal);
		}
	return retVal;
}
