#include <stdio.h>
#include <stdlib.h>
#include "typedefs.h"
#include "cardandterminal.h"
#include "server.h"
#include "transaction.h"
//extern ST_accountBalance_t Global_Server_Array[10];
ST_transaction_t transactionProcess()
{
    ST_transaction_t transaction;
    transaction.cardHolderData=get_card_data();
    transaction.transData=get_terminal_data();
    transaction.transStat=transactionVerification(transaction);
    if(transaction.transStat==APPROVED)
    {
        modify_Global_server(transaction.cardHolderData.primaryAccountNumber,\
                             transaction.transData.transAmount);
    }
    return transaction;
}
EN_transStat_t transactionVerification(ST_transaction_t transaction)
{
    EN_transStat_t state=DECLINED;

    expiration expiryState;
    terminalAcceptance terminalacceptanceState;
    PAN_EXISTANCE panexistanceState;
    serverAcceptance serveracceptanceState;

    //is card expired?
    expiryState=IsTheCardExpired(&(transaction.cardHolderData.cardExpirationDate), &(transaction.transData.transactionDate));
    //is amount accepted by the terminal?
    terminalacceptanceState=TransactionAmountAcceptanceByTerminal(transaction.transData.transAmount);
    //does PAN exists?
    uint8_t* pan=&(transaction.cardHolderData.primaryAccountNumber);
    panexistanceState=SearchingForPan(pan);
    //is amount accepted by the server?
    serveracceptanceState=TransactionAmountAcceptanceByServer(transaction.transData.transAmount, pan);

    if(expiryState==NOTEXPIRED&&\
       terminalacceptanceState==TERMINALACCEPT&&\
       panexistanceState==EXISTANT&&\
       serveracceptanceState==SERVERACCEPT)
    {
        state=APPROVED;
        printf("transaction approved\n");
    }
    else
    {
        printf("transaction declined\n");
    }
    return state;
}
void unitTestingtransaction(void)
{
//    printf("start unit testing for functions of transaction:\n");
//    printf("1-unit testing of transactionVerification() function\n");
//    printf("input:\n");
//
//
//    printf("\nexpected output:\n");
//
//
//    printf("\nactual output:\n");
//
//
//
//    printf("\npress enter to continue");
//    getch();
//    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of transaction:\n");
    printf("2-unit testing of transactionProcess() function\n");
    printf("function call:\n");
    ST_transaction_t transaction = transactionProcess();
    printf("\ncollected data by the function: \n");
    printf("entered card holder name: %s",transaction.cardHolderData.cardHolderName);
    printf("entered Primary Account Number PAN: \n%s",transaction.cardHolderData.primaryAccountNumber);
    printf("entered card expiration date: %s\n",transaction.cardHolderData.cardExpirationDate);
    printf("entered transaction amount: %lf\n",transaction.transData.transAmount);
    printf("entered transaction date: %s\n",transaction.transData.transactionDate);
    printf("value of maximum limit of transaction: %lf\n",transaction.transData.maxTransAmount);
    printf("transaction verification result: %s\n",transaction.transStat==APPROVED?"APPROVED":"DECLINED");
    printf("Data of the server: \n");
    print_Global_server_data();
    printf("\npress enter to continue");
    getch();
    system("cls");

}

