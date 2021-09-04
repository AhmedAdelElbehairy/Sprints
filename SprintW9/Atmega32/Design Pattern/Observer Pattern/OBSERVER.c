#include "OBSERVER.h"


/*the constructor method*/
void ObserverConstructor(STR_Notifier_t* me){
	/**/
	/*initialize the shared data by zero*/
	(me->ObservableData).Old_State = 0;
	/*initialize array of pointer to function by NULL value*/
	me->acceptHandler[MAX_SUBSCRIBERS]=NULL_PTR;
	/*initialize the value holding the last allocated populated position in the array of pointer to functions*/
	me->LastSubscriberPosition = 0;	
}


/*subscribe method to pass a function pointer to the notifier*/
void Subscribe (STR_Notifier_t* me, void(*accept)(STR_Datum_t*))
{
	/*check if the passed pointer to function isn't holding the Null Value*/
	if(accept!=NULL_PTR)
	{
		/*assigning the pointer to function to the last position int the array*/
		me->acceptHandler[me->LastSubscriberPosition]= accept;
		/*increment the variable that is holding the index of the last unpopulated position*/
		(me->LastSubscriberPosition)++;	
	}
}


/*un-subscribe method to undo your subscribtion*/
void Un_Subscribe (STR_Notifier_t* me, void(*accept)(STR_Datum_t*))
{
	/*initializing variables of for loops iterators*/
	uint8_t iterator = 0;
	uint8_t iterator2 = 0;
	/*check if the passed pointers aren't holding the NULL value*/
	if(me != NULL_PTR && accept != NULL_PTR)
	{
		/*start the for loop responsible for finding the pointer to function required to be unsubscribed*/
		for(;iterator<MAX_SUBSCRIBERS;iterator++)
		{
			/*check if the pointer to function required to be unsubscribed is found in or not*/
			if(me->acceptHandler[iterator]==accept)
			{
				/*start the for loop to fragment the array after deleting an element from it*/
				for(iterator2 = iterator; iterator2 <MAX_SUBSCRIBERS; iterator2++)
				{
					/*shifting elements of the array after removing the element that required to be un subscribed*/
					me->acceptHandler[iterator2] = me->acceptHandler[iterator2+1];
				}
				/*break so as not to continue searching after this point*/
				break;
			}
		}
		/*decrement the variable that is holding the index of the last unpopulated position*/
		(me->LastSubscriberPosition)--;
	}
}


/*loops through array of ptr to functions and call them when any change in the datum is detected*/
void Notify(STR_Notifier_t* me)
{
	/*Initialize the iterator variable of the for loop that iterates through the array of pointers to function*/
	uint8_t iterator = 0;
	if((me->ObservableData).Old_State != (me->ObservableData).New_State)
	{
		/*update the old data*/
		me->ObservableData.Old_State = me->ObservableData.New_State;
		/*the for loop that loops through the array of pointer to function*/
		for (;iterator<=MAX_SUBSCRIBERS;iterator++)
		{
			/*Invocking the functions that are pointed to by the ptr to function*/
			me->acceptHandler[iterator](&(me->ObservableData));
		}
	}
}
