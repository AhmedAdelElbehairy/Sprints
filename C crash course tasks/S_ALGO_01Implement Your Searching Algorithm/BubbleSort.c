#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "typedefs.h"
#include "BubbleSort.h"
void BubbleSort(uint32_t* arr, uint8_t numberOfelements)
{
    for(int i =0; i<numberOfelements; i++)
    {
        for(int k=0; k<numberOfelements-(i+1); k++)
        {
            if(arr[k+1]<arr[k])
            {
                Swap(&(arr[k]),&(arr[k+1]));
            }
            else
            {
                continue;
            }
        }
    }
}
void Swap(uint32_t* A, uint32_t* B)
{
    uint32_t temp;
    temp=*A;
    *A=*B;
    *B=temp;
}
void print(uint32_t* arr, uint8_t numberOfelements)
{
    for (int i = 0; i<numberOfelements; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void UnitTestBubbleSort(void)
{
    printf("start unit testing for functions of BubbleSort:\n");
    printf("1-unit testing of swap() function\n");
    uint32_t test_cases_swapA[5]={0,3,50,6,4};
    uint32_t test_cases_swapB[5]={2,5,20,60,1};
    printf("input:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d  %d  ",test_cases_swapA[i],test_cases_swapB[i]);
    }
    printf("\nexpected output:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d  %d  ",test_cases_swapB[i],test_cases_swapA[i]);
    }
    printf("\nactual output:\n");
    for(int i=0;i<5;i++)
    {
        Swap(&test_cases_swapA[i],&test_cases_swapB[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("%d  %d  ",test_cases_swapA[i],test_cases_swapB[i]);
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    printf("unit testing for functions of BubbleSort:\n");
    printf("2-unit testing of print() function\n");
    uint32_t test_cases_print[5]={2,5,20,60,1};
    printf("input:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",test_cases_print[i]);
    }
    printf("\nexpected output:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",test_cases_print[i]);
    }
    printf("\n");
    printf("\nactual output:\n");
    print(test_cases_print,sizeof(test_cases_print)/sizeof(test_cases_print[0]));
    printf("\npress enter to continue");
    getch();
    system("cls");
    printf("unit testing for functions of BubbleSort:\n");
    printf("3-unit testing of BubbleSort() function\n");
    uint32_t test_cases_BubbleSort[5][5]={{0,3,50,6,4},\
                                          {2,5,20,60,1},\
                                          {5,5,5,5,5,5},\
                                          {22,33,22,55,33},\
                                          {'A','C','E','B','D'}};
    printf("input:\n");
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<5;i++)
        {
            if(k==4)
            {
                printf("%C ",test_cases_BubbleSort[k][i]);
            }
            else
            {
                printf("%d ",test_cases_BubbleSort[k][i]);
            }
        }
        printf("\n");
    }
    printf("\nexpected output:\n");
    printf("0 3 4 6 50 \n");
    printf("1 2 5 20 60 \n");
    printf("5 5 5 5 5 \n");
    printf("22 22 33 33 55 \n");
    printf("A B C D E \n");
    printf("\nactual output:\n");
    for(int i = 0; i<5;i++)
    {
        BubbleSort(test_cases_BubbleSort[i],5);
    }
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<5;i++)
        {
            if(k==4)
            {
                printf("%C ",test_cases_BubbleSort[k][i]);
            }
            else
            {
                printf("%d ",test_cases_BubbleSort[k][i]);
            }
        }
        printf("\n");
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
}
