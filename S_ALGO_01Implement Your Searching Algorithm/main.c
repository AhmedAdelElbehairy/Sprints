#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "typedefs.h"
#include "BubbleSort.h"
#include "BinarySearch.h"
#define Unit_Testing 0
int main()
{
    #if Unit_Testing
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
