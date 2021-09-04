/*
 * UART_PRIV.h
 *
 *  Created on: Jul 16, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_

	#define UART_ControlStatusRegA  *((volatile uint8_t*)0x2B)//UCSRA
	#define UART_ControlStatusRegB  *((volatile uint8_t*)0x2A)//UCSRB
	#define UART_ControlStatusRegC  *((volatile uint8_t*)0x40)//UCSRC
	#define UART_DataReg  			*((volatile uint8_t*)0x2C)//UDR
	#define UART_BaudRateRegL   	*((volatile uint8_t*)0x29)//UBRRL
	#define UART_BaudRateRegH		*((volatile uint8_t*)0x40)//UBRRH

	#define STATUS_REG		 		*((volatile uint8_t*)0x5F)//SREG

#endif /* MCAL_UART_UART_PRIV_H_ */
