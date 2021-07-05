#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include"typedefs.h"
#include "linkedlistdriver.h"



void Insert(struct Node** head, uint8_t insertedData, uint32_t index)
{
    struct Node* inserted=(struct Node*)calloc(1,sizeof(struct Node));
    inserted->data = insertedData;
    struct Node* temp=*head;
    if (index==START_NODE)
    {
        inserted->link = temp;
        *head = inserted;
    }
    else if(index == END_NODE)
    {
        if(temp!=NULL)
        {
            while(temp->link != NULL)
            {
                temp=temp->link;
            }
            temp->link=inserted;
            inserted->link=NULL;
        }
        else
        {
            *head=inserted;
            inserted->link=NULL;
        }
    }
    else
    {
        for(int i=0; i<(index-2); i++)
        {
            if(temp->link!=NULL)
            {
                temp=temp->link;
            }
            else
            {
                printf("ERORR:inserted index is out of scope.\n");
                printf("Insertion failure\n");
                return;
                //exit(EXIT_FAILURE);
            }

        }
        inserted->link=temp->link;
        temp->link = inserted;
    }
}
void Delete(struct Node** head, uint32_t index)
{
    struct Node* temp=*head;
    struct Node* secondtemp=NULL;
    if (index == START_NODE)
    {
        *head=temp->link;
        free(temp);
    }
    else if(index == END_NODE)
    {
        if(temp!=NULL)
        {
            while(temp->link != NULL)
            {
                secondtemp=temp;
                temp=temp->link;
            }
            secondtemp->link=NULL;
            free(temp);
        }
        else
        {
            printf("linked list is empty");
        }
    }
    else
    {
        for(int i=0; i<(index-2); i++)
        {
            if (temp->link!=NULL)
            {
                temp=temp->link;
            }
            else
            {
                printf("ERORR:inserted index is out of scope.\n");
                printf("Deletion failure\n");
                return;
                //exit(EXIT_FAILURE);
            }
        }
        secondtemp=temp->link;
        temp->link=secondtemp->link;
        free(secondtemp);

    }
}
void print(struct Node* head)
{
    struct Node* temp=head;
    if (temp==NULL)
    {
        printf("###empty###\n");
    }
    else
    {
        printf("    %C\n",temp->data);
        while (temp->link!=NULL)
        {
            temp=temp->link;
            printf("    %C\n",temp->data);
        }
        //printf("\n");
    }

}
uint8_t getValue (struct Node* head, uint32_t index)
{
    uint8_t Value=-1;
    struct Node* temp=head;
    if (index==START_NODE)
    {
        Value=head->data;
    }
    else if(index == END_NODE)
    {
        if(temp!=NULL)
        {
            while(temp->link != NULL)
            {
                temp=temp->link;
            }
            Value=temp->data;
        }
        else
        {
            printf("linked list is empty");
            Value=NULL;
        }
    }
    else
    {
        for(int i=0; i<(index-2); i++)
        {
            if (temp->link->link!=NULL)
            {
                temp=temp->link;
            }
            else
            {
                printf("ERORR:inserted index is out of scope.\n");
                printf("Deletion failure\n");
                return;
                //exit(EXIT_FAILURE);
            }
        }
        Value=temp->link->data;
    }
    return Value;
}
void UnitTestLinkedListDriver(void)
{
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
}
