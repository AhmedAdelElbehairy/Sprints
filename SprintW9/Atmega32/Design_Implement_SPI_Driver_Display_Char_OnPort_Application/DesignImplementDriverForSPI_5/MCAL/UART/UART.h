#ifndef _UART_H_
#define _UART_H_
/*- INCLUDES -----------------------------------------------*/
#include "UART_CONFIG.h"
#include "UART_PRIV.h"
/*- CONSTANTS ----------------------------------------------*/
/*- PRIMITIVE TYPES ----------------------------------------*/
/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/
/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
uint8_t UART_Init(uint8_t UartNumber);
uint8_t UART_TransmitChar(uint8_t UartNumber,uint8_t TxChar);
uint8_t UART_TransmitString(uint8_t UartNumber,ptr_uint8_t TxString);
uint8_t UART_ReceiveChar(uint8_t UartNumber,ptr_uint8_t RxChar);
uint8_t UART_ReceiveString(uint8_t UartNumber,ptr_uint8_t RxString);
uint8_t UART_EnableInterrupt(uint8_t UartNumber,uint8_t UartInterruptType);
uint8_t UART_DisableInterrupt(uint8_t UartNumber,uint8_t UartInterruptType);
uint8_t UART_SetCallback(uint8_t UartNumber,uint8_t UartInterruptType,
		void(*callBack)(void));
uint8_t UART_FlushReceiveBuffer(void);

#endif
