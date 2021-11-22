#include "TM4C123GH6PM.h"
#include "CPU.h"
/*clk sources*/
#define MOSC                            0x0U /*Main Oscillator Source*/
#define PIOSC                           0x1U /*Percision Internal Oscillator source*/
/*PLL States*/
#define PLL_OPERATING_NORMALLY          0x0U
#define PLL_POWERED_DWN                 0x1U
/*pll Locking status*/
#define PLL_LOCKED                      0x1U
#define PLL_UNLOCKED                    0x0U
/*system clock divisors*/
#define SYSCTL_SYSDIV_1                 0x00U
#define SYSCTL_SYSDIV_2                 0x01U
#define SYSCTL_SYSDIV_3                 0x02U
#define SYSCTL_SYSDIV_4                 0x03U
#define SYSCTL_SYSDIV_5                 0x04U
#define SYSCTL_SYSDIV_6                 0x05U
#define SYSCTL_SYSDIV_7                 0x06U
#define SYSCTL_SYSDIV_8                 0x07U
#define SYSCTL_SYSDIV_9                 0x08U
#define SYSCTL_SYSDIV_10                0x09U
#define SYSCTL_SYSDIV_11                0x0AU
#define SYSCTL_SYSDIV_12                0x0BU
#define SYSCTL_SYSDIV_13                0x0CU
#define SYSCTL_SYSDIV_14                0x0DU
#define SYSCTL_SYSDIV_15                0x0EU
#define SYSCTL_SYSDIV_16                0x0FU
typedef struct{
  uint8_t clock_source;
  uint8_t pll_state;/*enabled disabled*/
  uint32_t system_clock_freq_div;
}STR_CLK_CFG_t;

typedef enum
{
  WDG0_Gate = 0x00,
  WDG1_Gate = 0x01,
  
  GPT0_Gate = 0x10,
  GPT1_Gate = 0x11,
  GPT2_Gate = 0x12,
  GPT3_Gate = 0x13,
  GPT4_Gate = 0x14,
  GPT5_Gate = 0x15,
  
  GPIO0_Gate = 0x20,
  GPIO1_Gate = 0x21,
  GPIO2_Gate = 0x22,
  GPIO3_Gate = 0x23,
  GPIO4_Gate = 0x24,
  GPIO5_Gate = 0x25,
  
  MDMA0_Gate = 0x30,
  
  HIB0_Gate = 0x40,
  
  UART0_Gate = 0x50,
  UART1_Gate = 0x51,
  UART2_Gate = 0x52,
  UART3_Gate = 0x53,
  UART4_Gate = 0x54,
  UART5_Gate = 0x55,
  UART6_Gate = 0x56,
  UART7_Gate = 0x57,
  
  SSI0_Gate = 0x60,
  SSI1_Gate = 0x61,
  SSI2_Gate = 0x62,
  SSI3_Gate = 0x63,
  
  I2C0_Gate = 0x70,
  I2C1_Gate = 0x71,
  I2C2_Gate = 0x72,
  I2C3_Gate = 0x73,
  
  USB0_Gate = 0x80,
  
  CAN0_Gate = 0x90,
  CAN1_Gate = 0x91,
  
  ADC0_Gate = 0xA0,
  ADC1_Gate = 0xA1,
  
  ACMP0_Gate = 0xB0,
  
  PWM0_Gate = 0xC0,
  PWM1_Gate = 0xC1,
  
  QEI0_Gate = 0xD0,
  QEI1_Gate = 0xD1,
  
  EEPROM0_Gate = 0xE0,
  
  WGPT0_Gate = 0xF0,
  WGPT1_Gate = 0xF1,
  WGPT2_Gate = 0xF2,
  WGPT3_Gate = 0xF3,
  WGPT4_Gate = 0xF4,
  WGPT5_Gate = 0xF5,
}Gates_t;
/*Reset APIs*/
void MCU_PerformReset(void);
uint8_t MCU_GetResetCause(void);
/*Clock control APIs*/
void MCU_InitClock(uint8_t Clock_Cfg_Index);
static void MCU_ActivateClockGates(void);
void MCU_DistributePLL(void);
uint8_t MCU_GetStatusPLL(void);
/*MCU APIs*/
void MCU_Clk_Cfg_Init(STR_CLK_CFG_t *ClkArrPtr, uint8_t *GatesArrPtr, uint8_t Gates_array_size);