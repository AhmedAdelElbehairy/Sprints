#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedefs.h"
#include "server.h"
ST_accountBalance_t Global_Server_Array[10] = {{"123456789", 100.00},{"234567891", 6000.00},\
                                                {"567891234", 3250.25},{"456789123", 1500.12},\
                                                {"258649173",500.00},{"654823719", 2100.00},\
                                                {"971362485", 0.00},{"793148625", 1.00},\
                                                {"123123456", 10.12},{"456789321", 0.55}};
uint8_t sizeofGlobal_Server_Array=10;

PAN_EXISTANCE SearchingForPan(uint8_t* PAN)
{
    uint8_t n;
    PAN_EXISTANCE state=NON_EXISTANT;
    for(int i = 0; i<sizeofGlobal_Server_Array; i++)
    {
        n=strlen(Global_Server_Array[i].primaryAccountNumber);
//        printf("n:%d\n",n);
//        printf("%d\n",strlen(Global_Server_Array[i].primaryAccountNumber));
//        printf("%d\n",strlen(PAN));
//        printf("%s : %s\n",Global_Server_Array[i].primaryAccountNumber,PAN);
        if(strncmp(Global_Server_Array[i].primaryAccountNumber,PAN,n)==0&&\
             strlen(PAN)==strlen(Global_Server_Array[i].primaryAccountNumber))
        {
//            printf("it exists\n");
            state=EXISTANT;
            break;
        }
    }
    return state;
}
serverAcceptance TransactionAmountAcceptanceByServer(double amount, uint8_t* PAN)
{
    uint8_t n;
    serverAcceptance state = SERVERNOTACCEPT;
    for(int i = 0; i<sizeofGlobal_Server_Array; i++)
    {

        //for(n=0;Global_Server_Array[i].primaryAccountNumber[n]!='\0';n++);
        n=strlen(Global_Server_Array[i].primaryAccountNumber);

        if(strncmp(Global_Server_Array[i].primaryAccountNumber,PAN,n)==0&&\
           strlen(PAN)==strlen(Global_Server_Array[i].primaryAccountNumber)&&\
           Global_Server_Array[i].balance>= amount && amount>0.0)
        {
            state = SERVERACCEPT;
            break;
        }
    }
    return state;
}
void modify_Global_server(uint8_t* PAN,double amount)
{
    uint8_t n;
    for(int i = 0; i<sizeofGlobal_Server_Array; i++)
    {
        for(n=0;PAN[n]!='\0';n++);

//        printf("%s : %s\n",Global_Server_Array[i].primaryAccountNumber,PAN);
        if(!(strncmp(Global_Server_Array[i].primaryAccountNumber,PAN,n-1)))
        {
            Global_Server_Array[i].balance=Global_Server_Array[i].balance-amount;
        }
}
}
void print_Global_server_data(void)
{
    for(uint8_t i = 0; i<sizeofGlobal_Server_Array; i++)
    {
        printf("%s: %lf\n",Global_Server_Array[i].primaryAccountNumber,Global_Server_Array[i].balance);
    }
}
void unitTestingserver(void)
{
    printf("start unit testing for functions of server:\n");
    printf("1-unit testing of SearchingForPan() function\n");
    uint8_t* arrOfPans[]={"255412","123456789","12345678910","793148625","11111"};
    printf("PANS to be searched for:\n");
    printf("input:\n");
    for(int i=0;i<5;i++)
    {
        printf("%S\n",arrOfPans[i]);
    }
    printf("expected output:\n");
    printf("NON-EXISTANT\nEXISTANT\nNON-EXISTANT\nEXISTANT\nNON-EXISTANT\n");
    printf("\nactual output:\n");
    for(int i=0;i<5;i++)
    {
        if(SearchingForPan(arrOfPans[i])==EXISTANT)
        {
            printf("EXISTANT\n");
        }
        else
        {
            printf("NON-EXISTANT\n");
        }
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of server:\n");
    printf("2-unit testing of TransactionAmountAcceptanceByServer() function\n");
    uint8_t* PANS[]={"567891234","123456789","258649173","793148625","123123456"};
    double transactionAmounts[5]={300.0,101.0,250.0,0.5,-2.0};

    printf("input:\n");
    printf("values needed to check for server acceptance:\n");
    for(int i=0; i<5; i++)
    {
        printf("%lf\t\t\t%s\n",transactionAmounts[i],PANS[i]);
    }
    printf("\nexpected output:\n");

    printf("ACCEPTED\nNOT-ACCEPTED\nACCEPTED\nACCEPTED\nNOT-ACCEPTED\n");

    printf("\nactual output:\n");
    for(int i=0; i<5; i++)
    {
        if(TransactionAmountAcceptanceByServer(transactionAmounts[i],PANS[i])==SERVERACCEPT)
            printf("ACCEPTED\n");
        else
            printf("NOT-ACCEPTED\n");
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of server:\n");
    printf("3-unit testing of modify_Global_server() function\n");
    uint8_t* PANs[]={"567891234","123456789","258649173","793148625","123123456"};
    double transactionamounts[5]={300.0,99.0,250.0,0.5,2.0};
    printf("server data before modification\n");
    print_Global_server_data();
    printf("values needed to modifying the server data:\n");
    printf("input:\n");
    for(int i=0; i<5; i++)
    {
        printf("%lf\t\t\t%s\n",transactionAmounts[i],PANs[i]);
    }
    printf("\nexpected output:\n");
    printf("567891234: %lf\n",3250.25-300.0);
    printf("123456789: %lf\n",100.0-100.0);
    printf("258649173: %lf\n",500-250.0);
    printf("793148625: %lf\n",1.0-0.5);
    printf("123123456: %lf\n",10.12-2.0);
    for(int i=0; i<5;i++)
    {
        modify_Global_server(PANs[i],transactionamounts[i]);
    }
    printf("\nserver data after modification\n");
    printf("actual output:\n");
    print_Global_server_data();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
//    printf("unit testing for functions of server:\n");
//    printf("4-unit testing of print_Global_server_data() function\n");
//    printf("input:\n");
//
//
//    printf("\nexpected output:\n");
//
//
//    printf("\nactual output:\n");
//
//
//    printf("\npress enter to continue");
//    getch();
//    system("cls");
}
//bonus
