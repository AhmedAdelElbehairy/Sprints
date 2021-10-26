/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  INTCTRL.c
 *       Module:  Interrupt Control
 *
 *  Description:  header file for the interrupt controller driver     
 *  
 *********************************************************************************************************************/
#include "INTCTRL.h"



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
//static void INTCTRL_SetPriority(uint8_t InterruptNum);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void INTCTRL_Init(void)
* \Description     : Initializes all the required interrupts                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                               
*******************************************************************************/
void INTCTRL_Init(void)
{
  uint8_t IteratorCfgArr = 0;
  /*Switch To priviledged mode*/
  CPU_SwitchToPrivilegedMode();
  /*Configuring the priority grouping and sub-grouping control*/
  SCB->AIRCR |= VECTKEY_WITH_PRIGROUP;
  /*TODO: Setting the priorities and sub-priorities for each interrupt*/
  for(IteratorCfgArr = 0; IteratorCfgArr <= INTERRUPTS_NUMBER; IteratorCfgArr++)
  {
    /*exception of constant priority whiose vector number less than 0*/
    if(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number < 0)
    {
      /*TODO: Enable/disable the System's exceptions*/
      switch(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)
      {
      case Reset_IRQn:
        break;
      case NonMaskableInt_IRQn:
        break;
      case HardFault_IRQn:
        break;
      case MemoryManagement_IRQn:
        SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_MEMFAULTENA_Pos);
        break;
      case BusFault_IRQn:
        SCB->SHCSR &= ~SCB_SHCSR_BUSFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_BUSFAULTENA_Pos);
        break;
      case UsageFault_IRQn:
        SCB->SHCSR &= ~SCB_SHCSR_USGFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_USGFAULTENA_Pos);
        break;
      case SVCall_IRQn:
        break;
      case DebugMonitor_IRQn:
        break;
      case PendSV_IRQn:
        break;
      case SysTick_IRQn:
        break;
      default:
        break;
      }
    }
    /*exception of controllable priority whose vector number more than or equal 0*/
    else
    {
      /*TODO: Enable/disable the Peripheral's exceptions*/
      NVIC->ISER[(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)/31] 
        |= aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled << (aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)%31;
      /*TODO : Assign the priority*/
      *(volatile uint8_t*)(0xE000E400 + aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number) = (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
    }
  }
  /*TODO: (optional) switch to user mode*/
}

//static void INTCTRL_SetPriority(uint8_t InterruptNum)
//{
  
//}







