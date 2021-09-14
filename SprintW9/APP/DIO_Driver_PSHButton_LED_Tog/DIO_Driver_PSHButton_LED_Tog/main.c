#include "APP.h"

int main(void)
{

	APP_init(PORT_A,PIN1,PORT_A, PIN0);
    while (1)
    {
    	APP_start();

    }
}
