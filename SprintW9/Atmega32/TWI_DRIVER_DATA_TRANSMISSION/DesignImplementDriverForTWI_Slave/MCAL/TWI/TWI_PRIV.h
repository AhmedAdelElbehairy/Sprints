/*
 * TWI_PRIV.h
 *
 *  Created on: Jul 23, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_TWI_TWI_PRIV_H_
#define MCAL_TWI_TWI_PRIV_H_

#define TWI_ControlRegister (*(volatile uint8_t*)0x56)
#define TWI_DataRegister (*(volatile uint8_t*)0x23)
#define TWI_AddressRegister (*(volatile uint8_t*)0x22)
#define TWI_StatusRegister (*(volatile uint8_t*)0x21)
#define TWI_BaudRateRegister (*(volatile uint8_t*)0x20)


#endif /* MCAL_TWI_TWI_PRIV_H_ */
