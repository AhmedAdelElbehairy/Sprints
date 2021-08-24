#include "SWITCH.h"
volatile uint8_t Switch_FinaL_state = 1;
volatile STR_Debouncer_t debounce;

void SWITCH_GetState(STR_Switch_t* me, uint8_t* State)
{
	if((me!=NULL_PTR) && (State!=NULL_PTR))
	*State = DIO_GetPinVal (me->PORT, me->PIN);
}

void SWITCH_Constructor(STR_Switch_t* me, uint8_t PORT, uint8_t PIN, uint8_t PULLEDUP)
{
	me->PORT = PORT;
	me->PIN = PIN;
	uint8_t x;
	SWITCH_GetState(me,&x);
	DebouncingFunction(&debounce, 10, x);
	me->Debounce = debounce;
	DIO_PinInit (me->PORT, me->PIN, PIN_INPUT);
	if(PULLEDUP)
		DIO_PinEnablePullUp (me->PORT, me->PIN);
	/*me->SwitchState = DIO_GetPinVal (me->PORT, me->PIN);*/
	me->SwitchState = x;	
}
void SWITCH_Main(STR_Switch_t* me)
{
	uint8_t x;
	SWITCH_GetState(me,&x);
	DebouncingFunction(&(me->Debounce), 10000000, x);
	Switch_FinaL_state = me->Debounce.OldState;
}