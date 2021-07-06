#ifndef SERVER_H
    #define SERVER_H

    typedef enum PAN_EXISTANCE
    {
        NON_EXISTANT,
        EXISTANT
    }PAN_EXISTANCE;

    typedef enum serverAcceptance
    {
        SERVERACCEPT,
        SERVERNOTACCEPT
    }serverAcceptance;

    typedef struct ST_accountBalance_t
    {
        uint8_t primaryAccountNumber[20];
        double balance;
    }ST_accountBalance_t;

    PAN_EXISTANCE SearchingForPan(uint8_t* PAN);
    serverAcceptance TransactionAmountAcceptanceByServer(double amount, uint8_t* PAN);
    void modify_Global_server(uint8_t* PAN,double amount);
    void print_Global_server_data(void);

    void unitTestingserver(void);
#endif // SERVER_H
