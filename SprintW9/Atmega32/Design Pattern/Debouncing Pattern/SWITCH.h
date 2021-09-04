#ifndef SWITCH_H_
#define SWITCH_H_
#include "STD_TYPES.h"
#include "Bit_Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
#include "DEBOUNCER.h"
typedef struct STR_Switch_t{
STR_Debouncer_t Debounce;
uint8_t SwitchState;
uint8_t PORT;
uint8_t PIN;
} STR_Switch_t;
void SWITCH_GetState(STR_Switch_t* me, uint8_t* State);
void SWITCH_Constructor(STR_Switch_t* me, uint8_t PORT, uint8_t PIN, uint8_t PULLEDUP);
void SWITCH_Main(STR_Switch_t* me);
#endif /*SWITCH_H_*/