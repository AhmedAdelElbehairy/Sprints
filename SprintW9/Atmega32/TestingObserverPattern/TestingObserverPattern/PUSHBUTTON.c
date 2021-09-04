/*
 * PUSHBUTTON.c
 *
 * Created: 9/2/2021 2:24:07 PM
 *  Author: vetmo
 */ 
#include "PUSHBUTTON.h"

void SWITCH_GetState(STR_PSHBUTTON_t* me, uint8_t* State)
{
	if((me!=NULL_PTR) && (State!=NULL_PTR))
	{
		me->SwitchState = DIO_GetPinVal (me->PORT, me->PIN);
		*State = me->SwitchState;
	}
	
}


void SWITCH_Constructor(STR_PSHBUTTON_t* me, uint8_t PULLEDUP)
{
	DIO_PinInit (me->PORT, me->PIN, PIN_INPUT);
	if(PULLEDUP)
		DIO_PinEnablePullUp (me->PORT, me->PIN);
	me->SwitchState = DIO_GetPinVal (me->PORT, me->PIN);
	me->PSHBUTTON_Notifier.ObservableData.New_State = me->SwitchState;
	me->PSHBUTTON_Notifier.ObservableData.Old_State = me->SwitchState;
}


void SWITCH_Main(STR_PSHBUTTON_t* me)
{
	uint8_t x;
	SWITCH_GetState(me,&x);
	me->PSHBUTTON_Notifier.ObservableData.New_State = x;
	Notify(&(me->PSHBUTTON_Notifier));
}