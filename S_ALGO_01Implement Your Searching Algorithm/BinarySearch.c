#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "typedefs.h"
#include "BubbleSort.h"
#include "BinarySearch.h"
Sort SortedOrNot(uint32_t* arr, uint8_t numberOfelements)
{
    uint8_t answer = SORTED;
    for (uint8_t i = 0; i<numberOfelements-1; i++)
    {
        if(arr[i+1]<arr[i])
        {
            answer = NOTSORTED;
            break;
        }
    }
    return answer;
}
uint8_t binarySearch(uint32_t* arr, uint8_t numberOfelements, uint8_t number)
{
    uint8_t indx = -1;
    uint8_t end_indx=numberOfelements-1;
    uint8_t start_indx=0;
    uint8_t mid_indx=(uint8_t)((end_indx+start_indx)/2);
    uint8_t answer=SortedOrNot(arr, numberOfelements);
    if(answer==NOTSORTED)
    {
        BubbleSort(arr, numberOfelements);
    }
    printf("sorted array:\n");
    print(arr, numberOfelements);
    if(number>arr[end_indx])
    {
        return indx;
    }
    else
    {
        while(end_indx!=start_indx)
        {
            if(number==arr[mid_indx])
            {
                indx=mid_indx;
                break;
            }
            else if(number>arr[mid_indx])
            {
                if(number==arr[end_indx])
                {
                    indx=end_indx;
                    break;
                }
                start_indx=mid_indx;
                mid_indx=(uint8_t)((end_indx+start_indx)/2);
            }
            else
            {
                if(number==arr[start_indx])
                {
                    indx=start_indx;
                    break;
                }
                end_indx=mid_indx;
                mid_indx=(uint8_t)((end_indx+start_indx)/2);
            }
        }
    }

    //binary search algorithm
    //determine middle element
    //compare and make descision
    //determine middle element
    //compare and make descision
    //so on till element is found or not found
    return indx;
}
void UnitTestBinarySearch()
{
    printf("start unit testing for functions of binarySearch:\n");
    printf("1-unit testing of SortedOrNot() function\n");
    uint32_t test_cases_SortedOrNot[5][5]={{0,3,4,6,50},\
                                          {2,5,20,60,1},\
                                          {5,5,5,5,5,5},\
                                          {22,33,22,55,33},\
                                          {'A','B','C','D','E'}};
    printf("input:\n");
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<5;i++)
        {
            if(k==4)
            {
                printf("%C ",test_cases_SortedOrNot[k][i]);
            }
            else
            {
                printf("%d ",test_cases_SortedOrNot[k][i]);
            }
        }
        printf("\n");
    }
    printf("\nexpected output:\n");
    printf("Sorted\nNotSorted\nSorted\nNotSorted\nSorted\n");
    printf("\nactual output:\n");
    for(int i = 0; i<5;i++)
    {
        if(SortedOrNot(test_cases_SortedOrNot[i],5)==SORTED)
        {
            printf("Sorted\n");
        }
        else if(SortedOrNot(test_cases_SortedOrNot[i],5)==NOTSORTED)
        {
            printf("NotSorted\n");
        }
    }
    printf("\npress enter to continue");
    getch();
    system("cls");

    printf("unit testing for functions of binarySearch:\n");
    printf("2-unit testing of binarySearch() function\n");
    uint32_t test_cases_binarySearch[3][5]={{0,3,4,6,50},\
                                          {2,5,20,60,1},\
                                          {22,33,22,55,33}};
    printf("input:\n");
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<5;i++)
        {
            printf("%d ",test_cases_binarySearch[k][i]);
        }
        printf("\n");
    }
    printf("\nexpected output:\n");
    printf("sorted array:\n");
    printf("0 3 4 6 50 \n");
    printf("1\n");
    printf("sorted array:\n");
    printf("1 2 5 20 60 \n");
    printf("-1\n");
    printf("sorted array:\n");
    printf("22 22 33 33 55 \n");
    printf("4\n");
    printf("\nactual output:\n");
    printf("%d\n",binarySearch(test_cases_binarySearch[0],5,3));
    printf("%d\n",(char)binarySearch(test_cases_binarySearch[1],5,70));
    printf("%d\n",binarySearch(test_cases_binarySearch[2],5,55));
    printf("\npress enter to continue");
    getch();
    system("cls");
}

