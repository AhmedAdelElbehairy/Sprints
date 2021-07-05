#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "config.h"
#include "typedefs.h"
#include "cardandterminal.h"
#include "server.h"
#include "transaction.h"


int main()
{
    //edit config file to run unit tests
    #if Unit_Testing
        unitTestingCardAndTerminal();
        fflush(stdin);
        unitTestingserver();
        fflush(stdin);
        unitTestingtransaction();
    #else
		transactionProcess();
    #endif // Unit_Testing
    printf("\npress enter to continue");
    getch();
    system("cls");
    return 0;
}
