#include <stdio.h>
#include <stdlib.h>
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
