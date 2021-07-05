#include <stdio.h>
#include <stdlib.h>
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

