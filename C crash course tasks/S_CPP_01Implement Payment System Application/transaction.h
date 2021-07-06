#ifndef TRANSACTION_H
    #define TRANSACTION_H
    typedef enum EN_transStat_t
    {
        DECLINED,
        APPROVED
    }EN_transStat_t;
    typedef struct ST_transaction_t
    {
        ST_cardData_t cardHolderData;
        ST_termianlData_t transData;
        EN_transStat_t transStat;
    }ST_transaction_t;

    EN_transStat_t transactionVerification(ST_transaction_t transaction);
    ST_transaction_t transactionProcess (void);

    void unitTestingtransaction(void);
#endif
