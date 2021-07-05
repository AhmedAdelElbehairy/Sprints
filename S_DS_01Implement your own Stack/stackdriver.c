#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include"typedefs.h"
#include "linkedlistdriver.h"
#include "stackdriver.h"
struct Node* GLOBAL_STACK_HEAD = NULL;
struct Node* GLOBAL_STACK_TAIL = NULL;
void push(uint8_t u8_data)
{
    Insert(&GLOBAL_STACK_HEAD, u8_data, START_NODE);
    //make tail pointing to last element
        //modify the linked list functions to return addresses
}
uint8_t pull(void)
{
    uint8_t Value;
    Value = getValue(GLOBAL_STACK_HEAD, START_NODE);
    Delete(&GLOBAL_STACK_HEAD, START_NODE);
    //make tail pointing to last element
        //modify the linked list functions to return addresses
    return Value;
}
void printStack(void)
{
    printf("TOP OF STACK\n");
    print(GLOBAL_STACK_HEAD);
    printf("BOTTOM OF STACK\n");
    printf("###############\n");
}
isEmpty isStackEmpty(void)
{
    isEmpty state;
    if(GLOBAL_STACK_HEAD==NULL)
        state= EMPTY;
    else
        state= NOTEMPTY;
    return state;
}
void pullWithNoReturn(void)
{
    Delete(&GLOBAL_STACK_HEAD, START_NODE);
}
void empty_the_stack(void)
{
    while(GLOBAL_STACK_HEAD!=NULL)
        pullWithNoReturn();
}
void UnitTestStackDriver(void)
{
    printf("unit testing of stack driver:\n");
    printf("1-testing push() Function:\n");
    uint8_t push_test_cases_data[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
    {
        push(push_test_cases_data[i]);
        printf("stack after pushing element %c\n",push_test_cases_data[i]);
        printf("stack:\n");
        printStack();
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    /****************************************************************************************/
    printf("testing functions of stack driver:\n");
    printf("2-testing pull() Function:\n");
    uint8_t pull_test_cases_data[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
    {
        push(pull_test_cases_data[i]);
        printf("stack after pushing element %c\n",pull_test_cases_data[i]);
    }
    printf("stack:\n");
    printStack();
    for(int i=0;i<5;i++)
    {
        printf("the top element which is %c is pulled\n",pull());
        printf("stack after pulling: \n");
        printStack();
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    /****************************************************************************************/
    printf("testing functions of stack driver:\n");
    printf("2-testing emptyTheStack() and isStackEmpty() Functions:\n");
    if(isStackEmpty()== EMPTY)
        printf("\nthe stack is empty!!\n");
    else if(isStackEmpty()== NOTEMPTY)
        printf("\nthe stack is NOT empty!!\n");
    printf("stack:\n");
    printStack();

    printf("\nemptying the stack.......\n");
    empty_the_stack();
    if(isStackEmpty()== EMPTY)
        printf("\nthe stack is empty!!\n");
    else if(isStackEmpty()== NOTEMPTY)
        printf("\nthe stack is NOT empty!!\n");
    printf("\nstack:\n");
    printStack();
    printf("\npress enter to continue");
    getch();
    system("cls");
}
