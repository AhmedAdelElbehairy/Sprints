/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  INTCTRL_Lcfg.c
 *        \brief  The source file for the linking configurations for interrupt control Driver
 *
 *      \details  NULL
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "INTCTRL_Cfg.h"
const STR_InterruptCfg_t aSTR_InterruptCfg[INTERRUPTS_NUMBER] = 
{{GPIOA_IRQn, INTERRUPT_ENABLED, {GROUP_YYY_PRIORITY_0,SUBGROUP_YYY_PRIORITY_1}},
{GPIOB_IRQn, INTERRUPT_ENABLED, {GROUP_YYY_PRIORITY_0,SUBGROUP_YYY_PRIORITY_7}}};