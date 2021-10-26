#include "TM4C123GH6PM.h"
#include "MCU.h"

int main()
{
  //MCU_PerformReset();
  SYSCTL->RCGCGPIO = 1;
  uint8_t arrayof[1] = {GPIO0_Gate};
  uint8_t arra[1][3] = {MOSC, 1, 0};
  MCU_Init((void*)arra, (void*)arrayof);
  MCU_InitClock(0);
  return 0;
}
