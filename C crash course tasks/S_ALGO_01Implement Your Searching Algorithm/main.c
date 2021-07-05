#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "config.h"
#include "typedefs.h"
#include "BubbleSort.h"
#include "BinarySearch.h"

int main()
{
    //edit config files to run the unit tests
    #if Unit_Testing
        UnitTestBubbleSort();
        UnitTestBinarySearch();
    #else
        uint32_t arr[254]={0};
        uint8_t i=0;
        for(;i<254;i++)
        {
            printf("to continue entering elements of your array press C and to terminate press any other key\n");
            uint8_t a = getch();
            if(a=='c')
            {
                printf("enter element of index %d\n",i);
                uint32_t num;
                scanf("%d",&num);
                arr[i]=num;
            }
            else{break;}
        }
        printf("enter the value of element that you are searching for: ");
        uint32_t num;
        scanf("%d",&num);
        system("cls");
        uint8_t x=binarySearch(arr,i,num);
        printf("index of element you searching for is %d\n",x);
    #endif // Unit_Testing
    return 0;
}
