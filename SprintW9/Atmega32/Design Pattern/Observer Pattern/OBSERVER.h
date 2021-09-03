#ifndef OBSERVER_PATTERN_H_
#define OBSERVER_PATTERN_H_

#include "STD_TYPES.h"
#include "Bit_Operations.h"

/*Max Numbers of subscribers to the notifier*/
#define MAX_SUBSCRIBERS 5
/*using structure to enable extendability*/
typedef struct STR_Datum_t{
	/*Shared Data*/
	uint8_t Old_State;
	uint8_t New_State;
}STR_Datum_t;

/*Notifier's structure (Class)*/
typedef struct STR_Notifier_t{
	/*Inherits structure of shared Data*/
	STR_Datum_t ObservableData;
	/*array of pointers to functions that are used to access the shared data*/
	void (*acceptHandler[MAX_SUBSCRIBERS])(STR_Datum_t* Data);
	/*variable that holds position of last element in the array of pointers to functions*/
	uint8_t LastSubscriberPosition;
}STR_Notifier_t;

void ObserverConstructor(STR_Notifier_t* me);
void Subscribe(STR_Notifier_t* me, void (*accept)(STR_Datum_t* ));
void Un_Subscribe(STR_Notifier_t* me, void (*accept)(STR_Datum_t* ));
void Notify(STR_Notifier_t* me);
/*void NotifierMainFunction(void);*/

#endif