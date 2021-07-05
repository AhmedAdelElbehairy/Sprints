#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"typedefs.h"
#include "linkedlistdriver.h"
#include "stackdriver.h"
#include "stackframework.h"
uint8_t* balanced=(unsigned char*)"Balanced";
uint8_t* notbalanced=(unsigned char*)"Not Balanced";

uint8_t* balancedParentheses (uint8_t* expression)
{
    uint8_t* returnword = balanced;
    uint8_t i = 0;
    uint8_t pull_result;
    while(expression[i]!='\0')
    {
        if(expression[i]=='{' || expression[i]=='(')
           {
            push(expression[i]);
            i++;
           }
        else if (expression[i]=='}' || expression[i]==')' )
        {
            if(isStackEmpty()== EMPTY)
            {
                returnword = notbalanced;
                break;
            }
            else if (expression[i]=='}')
            {
                pull_result=pull();
                if(pull_result=='{')
                {
                    i++;
                    continue;
                }
                else
                {
                    returnword=notbalanced;
                    break;
                }
            }
            else if (expression[i]==')')
            {
                pull_result=pull();
                if(pull_result=='(')
                {
                    i++;
                    continue;
                }
                else
                {
                    returnword=notbalanced;
                    break;
                }
            }
        }
        else
        {
            i++;
            continue;
        }

    }
    if(isStackEmpty()== NOTEMPTY)
    {
        returnword=notbalanced;
        empty_the_stack();
    }
    return returnword;
}
