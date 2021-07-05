#include <stdio.h>
#include <stdlib.h>
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
