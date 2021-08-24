#include "DEBOUNCER.h"
extern volatile STR_Debouncer_t debounce;
void DebouncingFunction(STR_Debouncer_t* me, uint32_t ConfigurableWindow, uint8_t swstate)
{
	static uint8_t flag = 0;
	uint8_t DebouncingDeviceState = 0;
	static uint8_t State = 255;
	static uint32_t WindowCurrentCount = 0;
	if(me != NULL_PTR)
	{
		if (flag == 0)
		{
			/*Initialize the structure*/
			me->ConfigurableWindow = ConfigurableWindow;
			me->OldState = swstate;
			flag = 1;
		}
		else
		{
			/*Finite state machine starts*/
			switch (State)
			{
				case 255:
					if(me->OldState == 1)
					{
						State = 1;
					}
					else
					{
						State = 0;	
					}
					break;
				case 0:
					WindowCurrentCount ++;
					if(swstate == 1)
					{
						if(WindowCurrentCount == me->ConfigurableWindow)
						{
							me->OldState = DebouncingDeviceState;
							WindowCurrentCount = 0;
							State = 1;
						}
					}
					else
					{
						WindowCurrentCount = 0;
					}
					break;
				case 1:
					WindowCurrentCount ++;
					if(swstate == 0)
					{
						if(WindowCurrentCount == me->ConfigurableWindow)
						{
							me->OldState = swstate;
							WindowCurrentCount = 0;
							State = 0;
						}
					}
					else
					{
						WindowCurrentCount = 0;
					}
					break;
				default:
					break;
			}
		}
		
	}
	else
	{
		/*function fail*/
	}
}