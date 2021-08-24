/*
 * TWI_CONFIG.h
 *
 *  Created on: Aug 3, 2021
 *      Author: zoldeyck
 */

#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_

/*some defaults*/
#define F_CPU 8000000UL
#define TWI_Channel_1 1
#define ResgisterDefaultVal 0
#define Enabled 1
#define Disabled 0
/*SCL Configuration*/
#define SCK_FREQ 100000UL // 100 KHz HIGHEST CLK 400KHz
#define CLKRATIO(FSCK) (((F_CPU)/(2*(FSCK)))-8)
#define ClockRatio CLKRATIO(SCK_FREQ)
/*Device address configration*/
#define deviceAddress 0x55 //0b01010101
/*General call configuration*/
#define GeneralCallRecognition Enabled
/*Interrupt Configuration*/
#define Interrupt Disabled
/*Bits and masks of TWI control register*/
#define TWI_InterruptEnable_BIT 0
#define TWI_InterruptEnable_MSK 1
#define TWI_ModuleEnable_BIT 2
#define TWI_ModuleEnable_MSK 4
#define TWI_WireCollision_BIT 3
#define TWI_WireCollision_MSK 8
#define TWI_StopCondition_BIT 4
#define TWI_StopCondition_MSK 16
#define TWI_StartCondition_BIT 5
#define TWI_StartCondition_MSK 32
#define TWI_EnableAcknowledge_BIT 6
#define TWI_EnableAcknowledge_MSK 64
#define TWI_InterruptFlag_BIT 7
#define TWI_InterruptFlag_MSK 128
/*Bits and masks of TWI status register*/
#define TWI_Prescalar_MSK 3
#define TWI_Status_MSK 0xF8
/*Bits and masks of TWI Address register*/
#define TWI_GeneralCallRecognitionEnable_BIT 0
#define TWI_GeneralCallRecognitionEnable_MSK 1
/*TWI Errors and States*/
#define OperationSuccess 0
#define OperationFail 1
#define OperationStarted 255
/*States of TWI_ReadDataWithACK()*/
#define FlagLowForReadDataWithACK 1
/*States of TWI_ReadDataWithNACK()*/
#define FlagLowForReadDataWithNACK 1
/*States of TWI_WriteData()*/
#define FlagLowForWritingDataRegister 1
/*States ofTWI_SendStartCondition()*/
#define StartConditionFiredInterruptFlagLow 1
/*States ofTWI_SendStopCondition()*/
#define StopConditionFired 1

/* Master */
/** def TW_START start condition transmitted */
#define TW_START		0x08
/** def TW_REP_START repeated start condition transmitted */
#define TW_REP_START		0x10

/* Master Transmitter */
/**def TW_MT_SLA_ACK SLA+W transmitted, ACK received */
#define TW_MT_SLA_ACK		0x18
/**def TW_MT_SLA_NACK SLA+W transmitted, NACK received */
#define TW_MT_SLA_NACK		0x20
/**def TW_MT_DATA_ACK data transmitted, ACK received */
#define TW_MT_DATA_ACK		0x28
/**def TW_MT_DATA_NACK data transmitted, NACK received */
#define TW_MT_DATA_NACK		0x30
/**def TW_MT_ARB_LOST arbitration lost in SLA+W or data */
#define TW_MT_ARB_LOST		0x38

/* Master Receiver */
/**def TW_MR_ARB_LOST arbitration lost in SLA+R or NACK */
#define TW_MR_ARB_LOST		0x38
/**def TW_MR_SLA_ACK SLA+R transmitted, ACK received */
#define TW_MR_SLA_ACK		0x40
/**def TW_MR_SLA_NACK SLA+R transmitted, NACK received */
#define TW_MR_SLA_NACK		0x48
/**def TW_MR_DATA_ACK data received, ACK returned */
#define TW_MR_DATA_ACK		0x50
/**def TW_MR_DATA_NACK data received, NACK returned */
#define TW_MR_DATA_NACK		0x58

/* Slave Transmitter */
/**def TW_ST_SLA_ACK SLA+R received, ACK returned */
#define TW_ST_SLA_ACK		0xA8
/**def TW_ST_ARB_LOST_SLA_ACK arbitration lost in SLA+RW, SLA+R received, ACK returned */
#define TW_ST_ARB_LOST_SLA_ACK	0xB0
/**def TW_ST_DATA_ACK data transmitted, ACK received */
#define TW_ST_DATA_ACK		0xB8
/**def TW_ST_DATA_NACK data transmitted, NACK received */
#define TW_ST_DATA_NACK		0xC0
/**def TW_ST_LAST_DATA last data byte transmitted, ACK received */
#define TW_ST_LAST_DATA		0xC8

/* Slave Receiver */
/**def TW_SR_SLA_ACK SLA+W received, ACK returned */
#define TW_SR_SLA_ACK		0x60
/**def TW_SR_ARB_LOST_SLA_ACK arbitration lost in SLA+RW, SLA+W received, ACK returned */
#define TW_SR_ARB_LOST_SLA_ACK	0x68
/**def TW_SR_GCALL_ACK general call received, ACK returned */
#define TW_SR_GCALL_ACK		0x70
/**def TW_SR_ARB_LOST_GCALL_ACK arbitration lost in SLA+RW, general call received, ACK returned */
#define TW_SR_ARB_LOST_GCALL_ACK 0x78
/**def TW_SR_DATA_ACK data received, ACK returned */
#define TW_SR_DATA_ACK		0x80
/**def TW_SR_DATA_NACK data received, NACK returned */
#define TW_SR_DATA_NACK		0x88
/** def TW_SR_GCALL_DATA_ACK general call data received, ACK returned */
#define TW_SR_GCALL_DATA_ACK	0x90
/**def TW_SR_GCALL_DATA_NACK general call data received, NACK returned */
#define TW_SR_GCALL_DATA_NACK	0x98
/**def TW_SR_STOP stop or repeated start condition received while selected */
#define TW_SR_STOP		0xA0

/* Misc */
/**def TW_NO_INFO no state information available */
#define TW_NO_INFO		0xF8

/**def TW_BUS_ERROR illegal start or stop condition */
#define TW_BUS_ERROR		0x00


#endif /* MCAL_TWI_TWI_CONFIG_H_ */
