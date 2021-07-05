#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "typedefs.h"
#include "linkedlistdriver.h"
#include "stackdriver.h"
#include "stackframework.h"
#define Unit_Testing 1
int main()
{
    #if Unit_Testing
        printf("unit testing of linked list driver:\n");
        printf("1-testing Insert() Function:\n");
        struct Node *head= NULL;
        uint32_t Insert_test_cases_indces[5]={START_NODE,END_NODE,2,4,5};
        uint8_t Insert_test_cases_data[5]={'A','B','C','D','E'};
        for(int i=0;i<5;i++)
        {
            Insert(&head,\
                   Insert_test_cases_data[i],\
                   Insert_test_cases_indces[i]);
                   if(i==1)
                   {
                       printf("linked list after insertion of %c at index END_NODE\n",Insert_test_cases_data[i]);
                   }
                   else
                   {
                       printf("linked list after insertion of %c at index %d\n",Insert_test_cases_data[i]\
                              ,Insert_test_cases_indces[i]);
                   }
            printf("linked list:\n");
            print(head);
        }
        printf("\npress enter to continue");
        getch();
        system("cls");
        /****************************************************************************************/
        printf("testing functions of linked list driver:\n");
        printf("2-testing Delete() Function:\n");
        uint32_t Delete_test_cases_indces[4]={START_NODE,END_NODE,2,4};
        for(int i=0;i<4;i++)
        {
            if(i==1)
            {
               printf("linked list after deletion of element at index END_NODE\n");
            }
            else
            {
               printf("linked list after deletion of element at index %d\n",Insert_test_cases_indces[i]);
            }
            Delete(&head,\
                   Insert_test_cases_indces[i]);
            printf("linked list:\n");
            print(head);
        }
        printf("\npress enter to continue");
        getch();
        system("cls");
        /****************************************************************************************/
        printf("testing functions of linked list driver:\n");
        printf("3-testing getValue() Function:\n");
        uint32_t getValue_test_cases_indces[5]={START_NODE, END_NODE, 2, 4, 6};
        for(int i=0;i<4;i++)
        {
            Insert(&head,\
            Insert_test_cases_data[i],\
            Insert_test_cases_indces[i]);
        }
        printf("linked list:\n");
        print(head);
        printf("\n\n");
        for(int i=0;i<5;i++)
        {
            if(i==1)
            {
               printf("value at index END_NODE is %c\n",getValue(head,\
                   getValue_test_cases_indces[i]));
            }
            else
            {
               printf("value at index %d is %c\n",getValue_test_cases_indces[i],getValue(head,\
                   getValue_test_cases_indces[i]));
            }

        }
        printf("\npress enter to continue");
        getch();
        system("cls");
        /****************************************************************************************/
        /****************************************************************************************/
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
        /****************************************************************************************/
        /****************************************************************************************/
        printf("unit testing of stack framework:\n");
        printf("1-testing balancedParentheses Function:\n");
        uint8_t *balancedParentheses_test_cases_data[]={"{[()]}","{{(})}","{{{(())}}}","(()(()))","(()))("};
        printf("\nexpected output:\n");
        printf("Balanced\n");
        printf("Not Balanced\n");
        printf("Balanced\n");
        printf("Balanced\n");
        printf("Not Balanced\n");
        printf("\nactual output:\n");
        for(int i=0;i<5;i++)
        {
            printf("%s\n",balancedParentheses(balancedParentheses_test_cases_data[i]));
        }
        printf("\npress enter to continue");
        getch();
        system("cls");
        /****************************************************************************************/
    #else
        uint32_t maxSizeOfStack=1024/sizeof(struct Node);//1MB
        uint8_t* word[maxSizeOfStack];
        printf("enter your expression to check it's balance:\n");
        gets((char*)word);
        uint8_t* characters=balancedParentheses((uint8_t*)word);
        printf("%s\n",characters);
    #endif
    return 0;

}
