
#include "MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "MCAL/DIO/DIO_DRIVER.h"
#include "HAL/PushButton/PushButton_TypeDef.h"
#include "HAL/PushButton/PushButton.h"
#include "HAL/LED/LED.h"
#include "APP/APP.h"

int main(void)
{

	APP_init(PORTA,PIN1,PORTA, PIN0);
    while (1)
    {
    	APP_start();

    }
}
