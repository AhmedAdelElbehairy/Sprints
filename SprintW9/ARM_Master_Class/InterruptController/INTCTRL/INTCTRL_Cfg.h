/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  INTCTRL_Cfg.h
 *       Module:  Interrupt Control
 *
 *  Description:  preprocessor configuration header file for the interrupt controller driver     
 *  
 *********************************************************************************************************************/
#ifndef _INTCTRL_CFG_H_
#define _INTCTRL_CFG_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTERRUPTS_NUMBER            (uint8_t)(2)
#define VECTKEY                      (uint32_t)(0x05FA << SCB_AIRCR_VECTKEY_Pos) /*must be placed in comon folder*/
#define PRI_GROUP_XXX                (uint32_t)(0x4)
#define PRI_GROUP_XXY                (uint32_t)(0x5)
#define PRI_GROUP_XYY                (uint32_t)(0x6)
#define PRI_GROUP_YYY                (uint32_t)(0x7)
#define PRI_GROUP                    (PRI_GROUP_YYY)
#define VECTKEY_WITH_PRIGROUP        (uint32_t)(VECTKEY|(PRI_GROUP << SCB_AIRCR_PRIGROUP_Pos))

#define INTERRUPT_ENABLED           (uint8_t)(1)
#define INTERRUPT_DISABLED          (uint8_t)(0)


    #define SUBGROUP_XXX_PRIORITY_0     (uint8_t)0
    #define GROUP_XXX_PRIORITY_0        (uint8_t)0
    #define GROUP_XXX_PRIORITY_1        (uint8_t)1
    #define GROUP_XXX_PRIORITY_2        (uint8_t)2
    #define GROUP_XXX_PRIORITY_3        (uint8_t)3
    #define GROUP_XXX_PRIORITY_4        (uint8_t)4
    #define GROUP_XXX_PRIORITY_5        (uint8_t)5
    #define GROUP_XXX_PRIORITY_6        (uint8_t)6
    #define GROUP_XXX_PRIORITY_7        (uint8_t)7

    #define SUBGROUP_XXY_PRIORITY_0     (uint8_t)0
    #define SUBGROUP_XXY_PRIORITY_1     (uint8_t)1
    #define GROUP_XXY_PRIORITY_0        (uint8_t)0
    #define GROUP_XXY_PRIORITY_1        (uint8_t)1
    #define GROUP_XXY_PRIORITY_2        (uint8_t)2
    #define GROUP_XXY_PRIORITY_3        (uint8_t)3

    #define SUBGROUP_XYY_PRIORITY_0     (uint8_t)0
    #define SUBGROUP_XYY_PRIORITY_1     (uint8_t)1
    #define SUBGROUP_XYY_PRIORITY_2     (uint8_t)2
    #define SUBGROUP_XYY_PRIORITY_3     (uint8_t)3
    #define GROUP_XYY_PRIORITY_0        (uint8_t)0
    #define GROUP_XYY_PRIORITY_1        (uint8_t)1

    #define GROUP_YYY_PRIORITY_0        (uint8_t)0
    #define SUBGROUP_YYY_PRIORITY_0     (uint8_t)0
    #define SUBGROUP_YYY_PRIORITY_1     (uint8_t)1
    #define SUBGROUP_YYY_PRIORITY_2     (uint8_t)2
    #define SUBGROUP_YYY_PRIORITY_3     (uint8_t)3
    #define SUBGROUP_YYY_PRIORITY_4     (uint8_t)4
    #define SUBGROUP_YYY_PRIORITY_5     (uint8_t)5
    #define SUBGROUP_YYY_PRIORITY_6     (uint8_t)6
    #define SUBGROUP_YYY_PRIORITY_7     (uint8_t)7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct STR_InterruptCfg_t
{
  int16_t Exception_Vector_Number;
  uint8_t Exception_State_Enabled_Disabled;
  uint8_t Exception_Group_SubGroup_Priority[2];
}STR_InterruptCfg_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif
/**********************************************************************************************************************
 *  END OF FILE: INTCTRL_Cfg.h
 *********************************************************************************************************************/
