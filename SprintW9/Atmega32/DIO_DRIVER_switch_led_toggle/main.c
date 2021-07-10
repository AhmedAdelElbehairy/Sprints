#include "Infrastructure/LIB/STD_TYPES.h"
#include "Infrastructure/LIB/Bit Operations.h"
#include "Mcal/DIO/DIO_DRIVER_TypeDef.h"
#include "Mcal/DIO/DIO_DRIVER_Priv.h"
#include "Mcal/DIO/DIO_DRIVER.h"

int main(void)
{
    /* Replace with your application code */
	//test
DIO_PinInit(PORTC, PIN0, PIN_OUTPUT);
DIO_PinInit(PORTA,PIN1,PIN_INPUT);
DIO_PinEnablePullUp(PORTA,PIN1);
    while (1)
    {
    	//test
    	if((DIO_GetPinVal(PORTA,PIN1))==0)
    	{
    		//wait for the de-bouncing
    		while((DIO_GetPinVal(PORTA,PIN1))!=1);
    		DIO_TogPinVal(PORTC, PIN0);
    	}
    }
}
