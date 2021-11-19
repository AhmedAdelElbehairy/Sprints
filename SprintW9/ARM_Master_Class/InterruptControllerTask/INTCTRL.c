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
	/*Todo: Enable/Disable main gates for Interrupt and faults*/
  uint8_t IteratorCfgArr = 0;
  /*Switch To priviledged mode*/
  CPU_SwitchToPrivilegedMode();
  /*Configuring the priority grouping and sub-grouping control*/
  SCB->AIRCR |= VECTKEY_WITH_PRIGROUP;
  /*Enable/Disable and Setting the priorities and sub-priorities for each interrupt*/
  for(IteratorCfgArr = 0; IteratorCfgArr <= INTERRUPTS_NUMBER; IteratorCfgArr++)
  {
    /*System Interrupts whose vector number less than 0*/
    if(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number < 0)
    {
      /*Enable/disable the System's exceptions*/
      switch(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)
      {
      case Reset_IRQn:
				/*Enable / Disable*/
			
				/*Control the priority*/
				
        break;
      case NonMaskableInt_IRQn:
				/*Enable / Disable*/
			
				/*Control the priority*/
				
        break;
      case HardFault_IRQn:
				/*Enable / Disable*/
			
				/*Control the priority*/
				
        break;
      case MemoryManagement_IRQn:
        /*Enable / Disable*/
        SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_MEMFAULTENA_Pos);
        /*Control the priority*/
        SCB->SHP[0] &= ~(7U<<5U);
        SCB->SHP[0] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case BusFault_IRQn:
        /*Enable / Disable*/
        SCB->SHCSR &= ~SCB_SHCSR_BUSFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_BUSFAULTENA_Pos);
        /*Control the priority*/
        SCB->SHP[1] &= ~(7U<<5U);
        SCB->SHP[1] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case UsageFault_IRQn:
        /*Enable / Disable*/
        SCB->SHCSR &= ~SCB_SHCSR_USGFAULTENA_Msk;
        SCB->SHCSR |= ((uint32_t)(aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled)<<SCB_SHCSR_USGFAULTENA_Pos);
        /*Control the priority*/
        SCB->SHP[2] &= ~(7U<<5U);
        SCB->SHP[2] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case SVCall_IRQn:
        /*Enable / Disable*/
       
        /*Control the priority*/
        SCB->SHP[6] &= ~(7U<<5U);
        SCB->SHP[6] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case DebugMonitor_IRQn:
        /*Enable / Disable*/
       
        /*Control the priority*/
        SCB->SHP[7] &= ~(7U<<5U);
        SCB->SHP[7] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case PendSV_IRQn:
        /*Enable / Disable*/
       
        /*Control the priority*/
        SCB->SHP[9] &= ~(7U<<5U);
        SCB->SHP[9] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      case SysTick_IRQn:
        /*Enable / Disable*/
       
        /*Control the priority*/
        SCB->SHP[10] &= ~(7U<<5U);
        SCB->SHP[10] |= (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|
                       aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
        break;
      default:
        break;
      }
    }
    /*exception of controllable priority whose vector number more than or equal 0*/
    else
    {
      /*Enable/disable the Peripheral's exceptions*/
      NVIC->ISER[(aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)/31] 
        |= aSTR_InterruptCfg[IteratorCfgArr].Exception_State_Enabled_Disabled << (aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number)%31;
      /*Assign the priority*/
      *(volatile uint8_t*)(0xE000E400 + aSTR_InterruptCfg[IteratorCfgArr].Exception_Vector_Number) = (aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[0]|aSTR_InterruptCfg[IteratorCfgArr].Exception_Group_SubGroup_Priority[1])<<5;
    }
  }
  /*TODO: (optional) switch to user mode*/
}








