#include "MCU.h"

#define PeripheralsClockGattingBase     ((uint32_t*)(0x400FE600))
#define SYSCTL_RCC_ACG_POS              27 /*Auto Clock Gating RunMode-ClockGating Control or Sleep modes control*/
#define SYSCTL_RCC_SYSDIV_POS           23 /*Clock divisor (prescalar) of systems clock*/
#define SYSCTL_RCC_USESYSDIV_POS        22 /*Enable Systems clock divider*/
//#define SYSCTL_RCC_USEPWMDIV_POS        20 /*Enable PWM Clock Divisor*/
//#define SYSCTL_RCC_PWMDIV_POS           17 /*PWM Unit Clock Divisor*/
#define SYSCTL_RCC_PWRDN_POS            13 /*PLL Power Down*/
#define SYSCTL_RCC_BYPASS_POS           11 /*Bybass the PLL*/
#define SYSCTL_RCC_XTAL_POS             6 /*Crystal Value*/
#define SYSCTL_RCC_OSCSRC_POS           4 /*Oscillator Source*/
#define SYSCTL_RCC_MOSCDIS_POS          1 /*Main Oscillator Disable*/ 
static uint8_t* GatesArr;
static uint8_t** ClkCfgArr;
/*MCU APIs*/
/*takes a pointer from the user's application and asigns
 it to a static one to be accessible to the functions of the
 MCU module*/
void MCU_Init(void* ClkArrPtr, void* GatesArrPtr)
{
  /*casting the pointer to the required data type*/
  /*1.casting and assigning the array of pointers to gates*/
  GatesArr = (uint8_t*) GatesArrPtr;
  /*2.casting and assigning array of configurations*/
  ClkCfgArr = (uint8_t**)ClkArrPtr;  
}
/*Reset APIs*/
void MCU_PerformReset(void)
{
  /*Switch to privilege mode*/
  CPU_SwitchToPrivilegedMode();
  __DSB();
  /*Modify the APINT reg. to perform a system reset*/
  SCB->AIRCR  = (uint32_t)((0x5FAUL << SCB_AIRCR_VECTKEY_Pos)    |
                           (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |
                            SCB_AIRCR_SYSRESETREQ_Msk    );
  __DSB();
  for(;;);
}
uint8_t MCU_GetResetCause(void)
{
  uint8_t Reset_Cause = 0;
  /*get the reset cause*/  
  Reset_Cause = SYSCTL->RESC & 0x0000003F;
  /*clear the bit of reset cause*/
  SYSCTL->RESC &= ~0x0000003F;
  return Reset_Cause;
}
/*Clock control APIs*/
void MCU_InitClock(uint8_t Clock_Cfg_Index)
{
  /*Disable RCC2 register use (in future development RCC2 can be added)*/
  //SYSCTL->RCC2 &= ~(1<<31);
  SYSCTL->RCC2 = 0;
  /*setting the clock source*/
  SYSCTL->RCC = ClkCfgArr[Clock_Cfg_Index][0]<< SYSCTL_RCC_OSCSRC_POS|
                    ClkCfgArr[Clock_Cfg_Index][1]<< SYSCTL_RCC_PWRDN_POS|
                      ClkCfgArr[Clock_Cfg_Index][2]<< SYSCTL_RCC_SYSDIV_POS|
                        1U<<SYSCTL_RCC_USESYSDIV_POS | 1U<<SYSCTL_RCC_BYPASS_POS|
                          0x15U<<SYSCTL_RCC_XTAL_POS;
  /*Enable/disable the PLL*/
  //SYSCTL->RCC |= ClkCfgArr[Clock_Cfg_Index][1]<< SYSCTL_RCC_PWRDN_POS;
  /*Setting the clock freq. (division)*/
  //SYSCTL->RCC |= ClkCfgArr[Clock_Cfg_Index][2]<< SYSCTL_RCC_SYSDIV_POS;
  /*Setting to RunMode-ClockGating*/
  //SYSCTL->RCC &= ~(1<<SYSCTL_RCC_ACG_POS);
  /*enable usage of sytem Div*/
  //SYSCTL->RCC |= 1<<SYSCTL_RCC_USESYSDIV_POS;
  /*Disabling the PLL (for the future we can add this to configurations)*/
  //SYSCTL->RCC &= ~ (1<<SYSCTL_RCC_PWRDN_POS);
  /*Bypass the PLL (for the future we can add this to configurations)*/
  //SYSCTL->RCC |= 1<<SYSCTL_RCC_BYPASS_POS;
  /*Crystal Value 16 MHZ*/
  //SYSCTL->RCC &= ~(0xff<<SYSCTL_RCC_XTAL_POS);
  //SYSCTL->RCC |= 0x15<<SYSCTL_RCC_XTAL_POS;
  //if(ClkCfgArr[Clock_Cfg_Index][0] == 0)
  //{
  //  SYSCTL->RCC &= ~1U<<SYSCTL_RCC_MOSCDIS_POS;
  //}
  MCU_ActivateClockGates();
}
static void MCU_ActivateClockGates(void)
{
  uint8_t GatesIterator = 0;
  for(GatesIterator = 0; GatesIterator < GatesNum; GatesIterator++)
  {
    *((uint32_t*)(0x400FE600+(GatesArr[GatesIterator]>>4)*4)) = (1<<(GatesArr[GatesIterator]&0x0F));
  }
}
/*for future development*/
void MCU_DistributePLL(void)
{
  
}
uint8_t MCU_GetStatusPLL(void)
{
  
  return 0;
}
