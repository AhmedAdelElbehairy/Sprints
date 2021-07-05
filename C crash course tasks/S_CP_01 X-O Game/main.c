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
    while(1)
    {
        system("cls");
        int x =0;
        start();
        printf("if you want to play again press 1 or press 2 to terminate\n");
        x=getch()-48;
        if(x==1)
        {
            continue;
        }
        else if(x==2)
        {
            break;
        }
        else
        {
            printf("wrong entry program will terminate");
            break;
        }

    }

    printf("\npress enter to terminate");
    getch();
    system("cls");
    #endif // Unit_Testing
    return 0;
}
