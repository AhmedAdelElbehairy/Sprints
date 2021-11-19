/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CPU_Cfg.h
 *       Module:  CPU Driver
 *
 *  Description:  Null     
 *  
 *********************************************************************************************************************/
#ifndef CPU_CFG_H
#define CPU_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BASE_PRIORITY_ALL_UNMASKED		(0x0UL)
#define BASE_PRIORITY_1_TO_7_MASKED		(0x1UL)
#define BASE_PRIORITY_2_TO_7_MASKED		(0x2UL)
#define BASE_PRIORITY_3_TO_7_MASKED		(0x3UL)
#define BASE_PRIORITY_4_TO_7_MASKED		(0x4UL)
#define BASE_PRIORITY_5_TO_7_MASKED		(0x5UL)
#define BASE_PRIORITY_6_TO_7_MASKED		(0x6UL)
#define BASE_PRIORITY_ONLY_7_MASKED		(0x7UL)
#define BASE_PRIORITY_DEFAULT					(BASE_PRIORITY_ALL_UNMASKED)
#define BASE_PRIORITY									(BASE_PRIORITY_DEFAULT)<<(5)


#define CHANGE_PROCESSOR_STATE_IRQ_ENABLE				(0x0UL)
#define CHANGE_PROCESSOR_STATE_FIQ_ENABLE				(0x1UL)
#define CHANGE_PROCESSOR_STATE_IRQ_FIQ_ENABLE		(0x2UL)
#define CHANGE_PROCESSOR_STATE_IRQ_FIQ_DISABLE	(0x3UL)
#define CHANGE_PROCESSOR_STATE_DEFAULT					(CHANGE_PROCESSOR_STATE_IRQ_FIQ_ENABLE)
#define PROCESSOR_STATE													(CHANGE_PROCESSOR_STATE_DEFAULT)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: SYSTEMTIMER.h
 *********************************************************************************************************************/
