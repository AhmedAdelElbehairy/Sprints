#ifndef CARDANDTERMINAL_H
    #define CARDANDTERMINAL_H

    //type definitions
    typedef struct ST_cardData_t
    {
        uint8_t cardHolderName [25];
        uint8_t primaryAccountNumber [20];
        uint8_t cardExpirationDate [6];
    }ST_cardData_t;

    typedef struct ST_termianlData_t
    {
        double transAmount;
        double maxTransAmount;
        uint8_t transactionDate[11];
    }ST_termianlData_t;

    typedef enum expiration
    {
        EXPIRED,
        NOTEXPIRED
    }expiration;

    typedef enum terminalAcceptance
    {
        TERMINALACCEPT,
        TERMINALNOTACCEPT
    }terminalAcceptance;

    ST_cardData_t get_card_data(void);
    ST_termianlData_t get_terminal_data(void);
    expiration IsTheCardExpired(uint8_t* expirationDate, uint8_t* transactionDate);
    terminalAcceptance TransactionAmountAcceptanceByTerminal(double amount);

    void unitTestingCardAndTerminal(void);
#endif // CARDANDTERMINAL_
