#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "config.h"
#include "ui_driver.h"
#include "ui_framework.h"


int main()
{
    //edit config file to run the unit tests
    #if Unit_Testing
    UnitTestingDriver();
    UnitTestingFrameWork();
    #else
    start();
    #endif // Unit_Testing
    return 0;
}
