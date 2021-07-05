#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ui_driver.h"
#include "ui_framework.h"


int main()
{
    #if Unit_Testing
//    UnitTestingDriver();
    UnitTestingFrameWork();
    #else
    start();
    #endif // Unit_Testing
    return 0;
}
