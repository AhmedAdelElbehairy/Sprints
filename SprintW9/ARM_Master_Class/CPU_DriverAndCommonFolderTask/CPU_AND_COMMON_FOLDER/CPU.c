/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  CPU.c
 *        \brief  The source file for the CPU Driver
 *
 *      \details  NULL
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM.h"
#include "CPU.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CPU_MODE_PRIVILEGED     0
#define CPU_MODE_USER           1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint8_t CPU_Mode = CPU_MODE_PRIVILEGED;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void SVC_Handler(void) 
{
   switch(CPU_Mode)
   {
   case CPU_MODE_PRIVILEGED:
     __asm ("MRS R1, CONTROL");
     __asm ("AND R1, #0xfffffffe");
     __asm ("MSR CONTROL, R1");
     break;
   case CPU_MODE_USER:
     __asm ("MRS R1, CONTROL");
     __asm ("AND R1, #0xfffffffe");
     __asm ("ORR R1, #1");      
     __asm ("MSR CONTROL, R1");
     break;
   default:
     break;
   }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void CPU_SwitchToPrivilegedMode(void)
{
  CPU_Mode = CPU_MODE_PRIVILEGED;
  __asm ("SVC #1");
}

void CPU_SwitchToUserMode(void)
{
  CPU_Mode = CPU_MODE_USER;
  __asm ("SVC #1");
}

void CPU_SetBasePriority()
{
	CPU_SwitchToPrivilegedMode();
	switch(BASE_PRIORITY)
	{
		case BASE_PRIORITY_ALL_UNMASKED:
			__asm ("LDR R0, =(0)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_1_TO_7_MASKED:
			__asm ("LDR R0, =(1<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_2_TO_7_MASKED:
			__asm ("LDR R0, =(2<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_3_TO_7_MASKED:
			__asm ("LDR R0, =(3<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_4_TO_7_MASKED:
			__asm ("LDR R0, =(4<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_5_TO_7_MASKED:
			__asm ("LDR R0, =(5<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_6_TO_7_MASKED:
			__asm ("LDR R0, =(6<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		case BASE_PRIORITY_ONLY_7_MASKED:
			__asm ("LDR R0, =(7<<5)");
			__asm ("MSR BASEPRI, R0");
			break;
		default:
			__asm ("LDR R0, =(0)");
			__asm ("MSR BASEPRI, R0");
			break;
	}
}


void CPU_Config_IRQ_FIQ()
{
	CPU_SwitchToPrivilegedMode();
	switch(PROCESSOR_STATE)
	{
		case CHANGE_PROCESSOR_STATE_IRQ_ENABLE:
			__asm ("CPSID f");
			__asm ("CPSIE i");
			break;
		case CHANGE_PROCESSOR_STATE_FIQ_ENABLE:
			__asm ("CPSIE f");
			__asm ("CPSID i");
			break;
		case CHANGE_PROCESSOR_STATE_IRQ_FIQ_ENABLE:
			__asm ("CPSIE if");
			break;
		case CHANGE_PROCESSOR_STATE_IRQ_FIQ_DISABLE:
			__asm ("CPSID if");
			break;
		default:
			__asm ("CPSIE if");
			break;
	}
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
/*Std_ReturnType FunctionName(AnyType parameterName)
{
	
	
}*/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
