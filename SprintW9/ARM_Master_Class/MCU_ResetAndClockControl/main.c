#include "TM4C123GH6PM.h"
#include "MCU.h"

int main()
{
  //MCU_PerformReset();
  SYSCTL->RCGCGPIO = 1<<5;
  while((SYSCTL->PRGPIO & 1<<5) != 1<<5);
  GPIOF->LOCK = 0x4C4F434B;
  //while(GPIOF_AHB->LOCK !=0);
  GPIOF->DIR &=~ 1<<0;
  GPIOF->AFSEL = 0;
  //GPIOF->DR8R = 1<<1;
  GPIOf->PUR |= 1<<0;
  GPIOF->DEN = 1<<0;
  while((GPIOF->CR & 1<<5) != 1<<5);
  //GPIOF->CR = 1<<5;
  while(1)
  {
  //GPIOF->DATA = 1<<1;
  //GPIOF->DATA &=~ 1<<1;
  }
  /*uint8_t arrayof[1] = {GPIO0_Gate};
  uint8_t arra[1][3] = {MOSC, 1, 0};
  MCU_Init((void*)arra, (void*)arrayof);
  MCU_InitClock(0);
  return 0;*/
}
