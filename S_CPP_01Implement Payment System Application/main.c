#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "typedefs.h"
#include "cardandterminal.h"
#include "server.h"
#include "transaction.h"
#define Unit_Testing 1

int main()
{
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
