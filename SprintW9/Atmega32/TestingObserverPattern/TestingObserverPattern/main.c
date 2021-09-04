/*
 * TestingObserverPattern.c
 *
 * Created: 8/25/2021 11:13:18 AM
 * Author : vetmo
 */ 
#define F_CPU 16000000UL
#include "PUSHBUTTON.h"
#include "LED.h"
uint8_t counter1 = 0;
void Accept_LED(STR_Datum_t* SharedData);
STR_PSHBUTTON_t Observable_PUShBUTTON = {.PORT = PORTA, .PIN = PIN1};
STR_LED_t RED_LED = {.PORT = PORTA, .PIN = PIN0};
uint8_t flag = 0;
int main(void)
{
	if(flag == 0)
	{
		    /* Replace with your application code */
		    SWITCH_Constructor(&Observable_PUShBUTTON, PIN_HIGH);//Enable pulling up
		    LED_Constructor(&RED_LED, PIN_LOW, Accept_LED);
		    /*subscribe the LED to the switch notifier*/
		    Subscribe(&(Observable_PUShBUTTON.PSHBUTTON_Notifier), Accept_LED);//RED_LED.LED_accept
			flag = 1;
	}

    while (1) 
    {
			SWITCH_Main(&Observable_PUShBUTTON);
    }
}

void Accept_LED(STR_Datum_t* SharedData)
{
	static uint8_t counter1 = 0;
	counter1++;
	if(counter1 == 1)
	{
		DIO_TogPinVal(RED_LED.PORT, RED_LED.PIN);
		counter1 = 0;
	}
		
}/*TODO: write the accept functions*/