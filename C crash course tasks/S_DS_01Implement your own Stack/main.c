#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "config.h"
#include "typedefs.h"
#include "linkedlistdriver.h"
#include "stackdriver.h"
#include "stackframework.h"

int main()
{
    //edit config file to run the unit test
    #if Unit_Testing
        UnitTestLinkedListDriver();
        UnitTestStackDriver();
        UnitTestBalancedParantheses();
    #else
        uint32_t maxSizeOfStack=1024/sizeof(struct Node);//1MB
        uint8_t* word[maxSizeOfStack];
        printf("enter your expression to check it's balance:\n");
        gets((char*)word);
        uint8_t* characters=balancedParentheses((uint8_t*)word);
        printf("%s\n",characters);
    #endif
    return 0;

}
