#include <stdio.h>
#include <stdlib.h>

//Software Engineer Name:

//All inputs are unsigned character

/*
- Define your global variables if needed here:
actual_result
expected_result
- Please concider the memoery optimization.
*/

/*
- Define your functional prototypes used here:
sum
unittest
- Please concider optimum Misra C when writing your functions.
*/
int sum(unsigned char, unsigned char);
int* unittest (int ,int);

int main()
{
//Please declare your initializations here.
int firstOperand = 0;
int secondOperand = 0;
int expected_result = 0;
int testcase_counter = 0;
int* actualresults = 0;

//Please define your infinite loop here.
    while(1)
    {
        testcase_counter++;
//Please insert your screen visualization here.
        printf("\n***************************************\n");
        fflush(stdin);
//Please write an expression that takes 2 numbers from the user here (consider screen readability).
        printf("\nEnter the first Operand:");
        scanf("%d",&firstOperand);

        printf("\nEnter the second Operand:");
        scanf("%d",&secondOperand);

        printf("\nEnter the Expected result:");
        scanf("%d",&expected_result);

//Please write an expression that calls the two function, the activation logic function and the unit test function in sequence.
        actualresults = unittest(sum(firstOperand,secondOperand), expected_result);

        printf("\nActual result:%d",*actualresults);
    }
    return 0;
}


//Please write the functional description of the sum function here:
int sum(unsigned char first_operand, unsigned char second_operand)
{
    int result = 0;
    result = (unsigned int) first_operand + (unsigned int) second_operand;
    return result;
}

//Pleas write the functional description of the unittest function here:
int* unittest (int value, int expected_result)
{
    static int actual_result;
    actual_result = value;
    if(actual_result == expected_result)
        printf("\nPass");
    else
        printf("\nFail");
    return (&actual_result);
}
