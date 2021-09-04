#ifndef DEBOUNCER_H_
#define DEBOUNCER_H_
#include "STD_TYPES.h"
#include "Bit Operations.h"
#include "DIO_DRIVER_TypeDef.h"
#include "DIO_DRIVER.h"
typedef struct STR_Debouncer_t{
uint8_t OldState; /*<=== actual dedouncing device state*/
uint32_t ConfigurableWindow;
}STR_Debouncer_t;
void DebouncingFunction(STR_Debouncer_t* me, uint32_t ConfigurableWindow, uint8_t swstate);
#endif /*DEBOUNCER_H_*/