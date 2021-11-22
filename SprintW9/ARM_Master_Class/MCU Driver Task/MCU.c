#include "MCU.h"

#define SYSCTL_RCC_MOSCDIS_POS          1 /*Main Oscillator Disable*/ 
#define XTAL_VAL                        0x15Ul/*16 MHz*/
#define SYSCTL_RCC_XTAL_POS             6 /*Crystal Value*/
#define SYSCTL_RCC_OSCSRC_POS           4 /*Oscillator Source*/
#define SYSCTL_RCC_PWRDN_POS            13 /*PLL Power Down*/
#define SYSCTL_RCC_BYPASS_POS           11 /*Bybass the PLL*/
#define SYSCTL_RCC_SYSDIV_POS           23 /*Clock divisor (prescalar) of systems clock*/
#define SYSCTL_RCC_USESYSDIV_POS        22 /*Enable Systems clock divider*/

/*static variables that will hold the address of configurations (input passed by the user)*/
static uint8_t *GatesArr;
static STR_CLK_CFG_t *ClkCfgArr;
static uint8_t GatesNum = 0;
static uint32_t RCC_Var = 0;
static uint32_t RCC2_Var = 0;

/*Reset APIs*/
/*performs reset*/
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
/*gets the cause of reset and clear register to be updated*/
uint8_t MCU_GetResetCause(void)
{
  uint8_t Reset_Cause = 0;
  /*get the reset cause*/  
  Reset_Cause = SYSCTL->RESC & 0x0000003F;
  /*clear the bit of reset cause*/
  SYSCTL->RESC &= ~0x0000003F;
  return Reset_Cause;
}
/*enable the clocks for the peripherals*/
static void MCU_ActivateClockGates(void)
{
  uint8_t GatesIterator = 0;
  for(GatesIterator = 0; GatesIterator < GatesNum; GatesIterator++)
  {
    //*((uint32_t*)(0x400FE600+(GatesArr[GatesIterator]>>4)*4)) = (1<<(GatesArr[GatesIterator]&0x0F));
    switch(GatesArr[GatesIterator]>>4)
    {
    case 0:/*watch dog*/
      SYSCTL->RCGCWD |= (1<<(GatesArr[GatesIterator]&0x0F));
        break;
    case 1:/*general purpose timer*/
      SYSCTL->RCGCTIMER |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 2:/*general purpose input output*/
      SYSCTL->RCGCGPIO |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 3:/*micro direct memory access*/
      SYSCTL->RCGCDMA |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 4:/*Hibernation*/
      SYSCTL->RCGCHIB |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 5:/*UART*/
      SYSCTL->RCGCUART |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 6:/*synchronus serial interface*/
      SYSCTL->RCGCSSI |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 7:/*I2c*/
      SYSCTL->RCGCI2C |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 8:/*USB*/
      SYSCTL->RCGCUSB |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 9:/*CAN*/
      SYSCTL->RCGCCAN |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 10:/*ADC*/
      SYSCTL->RCGCADC |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 11:/*Analog comparator*/
      SYSCTL->RCGCACMP |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 12:/*PWM*/
      SYSCTL->RCGCPWM |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 13:/*Quadrature encoder interface*/
      SYSCTL->RCGCQEI |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 14:/*EEPROM*/
      SYSCTL->RCGCEEPROM |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    case 15:/*wide general purpose timer*/
      SYSCTL->RCGCWTIMER |= (1<<(GatesArr[GatesIterator]&0x0F));
      break;
    default:
      break;
    }
  }
}
/*gets the configurations from the user*/
void MCU_Clk_Cfg_Init(STR_CLK_CFG_t *ClkArrPtr, uint8_t *GatesArrPtr, uint8_t Gates_array_size)
{
  /*casting the pointer to the required data type*/
  /*1.casting and assigning the array of pointers to gates*/
  GatesArr = GatesArrPtr;
  /*2.casting and assigning array of configurations*/
  ClkCfgArr = ClkArrPtr;  
  /*3.*/
  GatesNum = Gates_array_size;
}
/*Clock control APIs*/
void MCU_InitClock(uint8_t Clock_Cfg_Index)
{
  /*assigning the clock source and the XTAL*/
  /*1-xtal val*/
  RCC_Var |= XTAL_VAL<<SYSCTL_RCC_XTAL_POS;
  RCC2_Var |= XTAL_VAL<<SYSCTL_RCC_XTAL_POS;
  /*2-clk val*/
  RCC_Var |= ClkCfgArr[Clock_Cfg_Index].clock_source<<SYSCTL_RCC_OSCSRC_POS;
  RCC2_Var |= ClkCfgArr[Clock_Cfg_Index].clock_source<<SYSCTL_RCC_OSCSRC_POS;
  /*disabling the main oscillator if not used*/
  if(ClkCfgArr[Clock_Cfg_Index].clock_source != MOSC)
  {
    RCC_Var |= 0x1<<SYSCTL_RCC_MOSCDIS_POS;
  }
  /*Configuring the BYPASS and PWRDN Bits*/
  if(ClkCfgArr[Clock_Cfg_Index].pll_state == PLL_OPERATING_NORMALLY)
  {
    /*1-PWRDN Bit*/
    RCC_Var &= ~(0x01UL<<SYSCTL_RCC_PWRDN_POS);
    RCC2_Var &= ~(0x01UL<<SYSCTL_RCC_PWRDN_POS);
    
  }
  else
  {
    /*1-PWRDN Bit*/
    RCC_Var |= (0x01UL<<SYSCTL_RCC_PWRDN_POS);
    RCC2_Var |= (0x01UL<<SYSCTL_RCC_PWRDN_POS);
    /*2-BYPASS Bit*/
    RCC_Var |= (0x01UL<<SYSCTL_RCC_BYPASS_POS);
    RCC2_Var |= (0x01UL<<SYSCTL_RCC_BYPASS_POS);
  }
  /*configuring the system div*/
    if(ClkCfgArr[Clock_Cfg_Index].system_clock_freq_div > SYSCTL_SYSDIV_1)
    {
      /*set the divisor value then enable the division*/
      RCC_Var &= ~(0xFU<<SYSCTL_RCC_SYSDIV_POS);
      RCC_Var |= (ClkCfgArr[Clock_Cfg_Index].system_clock_freq_div<<SYSCTL_RCC_SYSDIV_POS);
      /*enable the Division*/
      RCC_Var |= (0x1U<<SYSCTL_RCC_USESYSDIV_POS);
    }
    else
    {
      /*disable the Division*/
      RCC_Var &= ~(0x1U<<SYSCTL_RCC_USESYSDIV_POS);
    }
  /*assigning the values to the registers if pll not used*/
  if(ClkCfgArr[Clock_Cfg_Index].pll_state == PLL_POWERED_DWN)
  {
      SYSCTL->RCC = RCC_Var;
      SYSCTL->RCC2 = (RCC2_Var & ~(0x01<<31));
  }
  /*Enabling the clock gates for the different perpherals*/
  MCU_ActivateClockGates();
}



/*MCU APIs*/
/*takes a pointer from the user's application and asigns
 it to a static one to be accessible to the functions of the
 MCU module*/

/*for future development*/
void MCU_DistributePLL(void)
{
  /*configuring the bypass*/
  RCC_Var &= ~(0x01UL<<SYSCTL_RCC_BYPASS_POS);
  RCC2_Var &= ~(0x01UL<<SYSCTL_RCC_BYPASS_POS);
  /*assign the value to the RCC registers*/
  SYSCTL->RCC = RCC_Var;
  SYSCTL->RCC2 = (RCC2_Var & ~(0x01<<31));
}
uint8_t MCU_GetStatusPLL(void)
{
  /*return the pllstat */
  return (SYSCTL->PLLSTAT&0x01);
}
