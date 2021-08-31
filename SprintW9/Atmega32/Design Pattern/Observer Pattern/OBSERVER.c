#include "OBSERVER.h"

void ObserverConstructor(STR_Notifier_t* me){
	(me->ObservableData)->Old_State = 0;
	me->acceptHandler[MAX_SUBSCRIBERS](STR_Datum_t*)={NULL_PTR};
	me->LastSubscriberPosition = 0;	
}
void Subscribe (STR_Notifier_t* me, void(*accept)(STR_Datum_t*))
{
	me->acceptHandler[me->LastSubscriberPosition]= accept;
	(me->LastSubscriberPosition)++;
	
}
void Un_Subscribe (STR_Notifier_t* me, void(*accept)(STR_Datum_t*))
{
	uint8_t iterator = 0;
	uint8_t iterator2 = 0;
	if(me != NULL_PTR && accept != NULL_PTR)
	{
		for(;iterator<MAX_SUBSCRIBERS;iterator++)
		{
			if(me->acceptHandler[iterator]==accept)
			{
				for(iterator2 = iterator; iterator2 <MAX_SUBSCRIBERS; iterator2++)
				{
					me->acceptHandler[iterator2] = me->acceptHandler[iterator2+1];
				}
			}
		}
		(me->LastSubscriberPosition)--;
	}
}
void Notify(STR_Notifier_t* me)
{
	uint8_t iterator = 0;
	for (;iterator<=MAX_SUBSCRIBERS;iterator++)
	{
		//me->acceptHandler[iterator]();
	}
}
//void NotifierMainFunction(void)
//{
	//
//}