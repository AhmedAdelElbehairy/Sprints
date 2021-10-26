#include "TM4C123GH6PM.h"
int main()
{
 /*Initialize a timer*/
  /*0-Enable clock gating to the timer*/
  
  /*1- make sure timer is disabled*/
  WTIMER0->CTL &= (~1U<<0);
  /*2-Reset the configuration register*/
  WTIMER0->CFG = 0x00000000U;
  /*3-configure the timer mode register*/
  WTIMER0->TAMR |= 0x2U<<0;
  /*4-configure the TnCDIR bit in the GPTMTnMR register to count up*/
  WTIMER0->TAMR |= 0x1U<<4;
  /*5-Loading the start value*/
  WTIMER0->TAILR = 0x00000000U;
  /*6-set the appropriate bits IN The GPTMIMR Interrupt mask Register*/
  
  /*7-Set the Enable bit to 1 to enable the timer to start count*/
  WTIMER0->CTL |= 1U<<0;
  /*Note: clear the flag of the interrupt by writing 1 to the appropriate bit in the GPTMICR*/
  while (1)
  {
    
  }
  return 0;
}
