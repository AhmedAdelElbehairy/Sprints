#include <stdio.h>
#include <stdlib.h>
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
