/*
 * PUSHBUTTON.h
 *
 * Created: 9/2/2021 2:24:30 PM
 *  Author: vetmo
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "STD_TYPES.h"
#include "Bit_Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
#include "OBSERVER.h"

typedef struct STR_PSHBUTTON_t{
	STR_Notifier_t PSHBUTTON_Notifier;
	uint8_t SwitchState;
	uint8_t PORT;
	uint8_t PIN;
} STR_PSHBUTTON_t;

void SWITCH_GetState(STR_PSHBUTTON_t* me, uint8_t* State);
void SWITCH_Constructor(STR_PSHBUTTON_t* me, uint8_t PULLEDUP);
void SWITCH_Main(STR_PSHBUTTON_t* me);

#endif /* PUSHBUTTON_H_ */