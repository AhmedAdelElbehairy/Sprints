/*
 * LED.h
 *
 * Created: 9/2/2021 3:34:06 PM
 *  Author: vetmo
 */ 


#ifndef LED_H_
#define LED_H_


#include "STD_TYPES.h"
#include "Bit_Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
#include "OBSERVER.h"

typedef struct STR_LED_t{
	uint8_t LED_State;
	uint8_t PORT;
	uint8_t PIN;
	void(*LED_accept)(struct STR_Datum_t*);
} STR_LED_t;

void LED_Constructor(STR_LED_t* me, uint8_t LED_Initial_State, void(*LED_accept)(struct STR_Datum_t*));
void LED_SetVal(STR_LED_t* me, uint8_t LED_Value);
#endif /* LED_H_ */