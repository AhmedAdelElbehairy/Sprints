#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedefs.h"
#include "cardandterminal.h"

const double maxTransactionAmount = 5000.0;
 ST_cardData_t get_card_data(void)
 {
     ST_cardData_t cardData;
     printf("please enter the card data:\n");
     printf("please enter the card holder name:\n");
     fgets(&(cardData.cardHolderName),25,stdin);
     printf("please enter card expiry date:\n");
     fgets(&(cardData.cardExpirationDate),6,stdin);
     printf("please enter the primary account number:\n");
     scanf("%s",cardData.primaryAccountNumber);
     return cardData;
 }
ST_termianlData_t get_terminal_data(void)
{
    ST_termianlData_t terminalData;
    printf("please enter the terminal data:\n");
    printf("please enter the transaction amount:\n");
    scanf("%lf",&(terminalData.transAmount));
    printf("please enter transaction date:\n");
    fflush(stdin);
    fgets(&(terminalData.transactionDate),11,stdin);
    terminalData.maxTransAmount= maxTransactionAmount;
    return terminalData;
}
expiration IsTheCardExpired(uint8_t* expirationDate, uint8_t* transactionDate)
{
    //"MM/YY"CardExpirationDateFormate
    //"DD/MM/YYYY"TransactionDateFormate
    expiration state;
    uint8_t year_of_cardExpiration[]={expirationDate[3],expirationDate[4],'\0'};
    uint8_t Month_of_cardExpiration[]={expirationDate[0],expirationDate[1],'\0'};
    uint8_t year_of_transaction[]={transactionDate[8],transactionDate[9],'\0'};
    uint8_t Month_of_transaction[]={transactionDate[3],transactionDate[4],'\0'};
//    printf("date of transaction:%s:%s\n",Month_of_transaction,year_of_transaction);
//    printf("date of expiration:%s:%s\n",Month_of_cardExpiration,year_of_cardExpiration);
    if(atoi(year_of_cardExpiration)<atoi(year_of_transaction))
    {
        state=EXPIRED;
    }
    else if((atoi(Month_of_cardExpiration)<atoi(Month_of_transaction))&&\
            (atoi(year_of_cardExpiration)==atoi(year_of_transaction)))
    {
        state=EXPIRED;
    }
    else
    {
        state=NOTEXPIRED;
    }
    return state;
}
terminalAcceptance TransactionAmountAcceptanceByTerminal(double amount)
{
    terminalAcceptance state;
    if(amount>maxTransactionAmount)
    {
        state=TERMINALNOTACCEPT;
    }
    else if(amount<0.0)
    {
        state=TERMINALNOTACCEPT;
    }
    else
    {
        state=TERMINALACCEPT;
    }
    return state;
}
void unitTestingCardAndTerminal(void)
{
    printf("start unit testing for functions of cardandterminal:\n");
    printf("1-unit testing of get_card_data() function\n");
    printf("function call:\n");
    ST_cardData_t cardData = get_card_data();
    printf("\ncollected data by the function: \n");
    printf("entered card holder name: %s",cardData.cardHolderName);
    printf("entered Primary Account Number PAN: %s\n",cardData.primaryAccountNumber);
    printf("entered card expiration date: %s\n",cardData.cardExpirationDate);
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of cardandterminal: \n");
    printf("2-unit testing of get_terminal_data() function\n");
    printf("\nfunction call: \n");
    ST_termianlData_t terminalData = get_terminal_data();
    printf("\ncollected data by the function: \n");
    printf("entered transaction amount: %lf\n",terminalData.transAmount);
    printf("entered transaction date: %s\n",terminalData.transactionDate);
    printf("value of maximum limit of transaction: %lf\n",terminalData.maxTransAmount);
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of cardandterminal:\n");
    printf("3-unit testing of IsTheCardExpired() function\n");
    uint8_t*expirationdates[]={"01/22","12/21","07/25","05/05","01/11"};
    uint8_t*transactiondates[]={"25/01/2018","17/06/2019","04/07/2021","15/05/2015","25/01/2011"};
    printf("input:\n");
    printf("expiration dates\ttransaction dates\n");
    for(int i=0; i<5;i++)
    {
        printf("%s\t\t\t%s\n",expirationdates[i],transactiondates[i]);
    }
    printf("\nexpected output:\n");
    printf("NOT-EXPIRED\nNOT-EXPIRED\nNOT-EXPIRED\nEXPIRED\nNOT-EXPIRED\n");
    printf("\nactual output:\n");
    for(int i=0; i<5;i++)
    {
        if(IsTheCardExpired(expirationdates[i],transactiondates[i])==EXPIRED)
            printf("EXPIRED\n");
        else
            printf("NOT-EXPIRED\n");
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of cardandterminal:\n");
    printf("4-unit testing of TransactionAmountAcceptanceByTerminal() function\n");
    double transactionAmounts[5]={20.0,7000.0,5000.0,0.0,-2000.0};
    printf("input:\n");
    printf("transaction amounts to be checked for terminal acceptance:\n");
    for(int i=0; i<5; i++)
    {
        printf("%lf\n",transactionAmounts[i]);
    }
    printf("\nexpected output:\n");

    printf("ACCEPTED\nNOT-ACCEPTED\nACCEPTED\nACCEPTED\nNOT-ACCEPTED\n");

    printf("\nactual output:\n");
    for(int i=0; i<5; i++)
    {
        if(TransactionAmountAcceptanceByTerminal(transactionAmounts[i])==TERMINALACCEPT)
            printf("ACCEPTED\n");
        else
            printf("NOT-ACCEPTED\n");
    }
    printf("\npress enter to continue");
    getch();
    system("cls");
}



