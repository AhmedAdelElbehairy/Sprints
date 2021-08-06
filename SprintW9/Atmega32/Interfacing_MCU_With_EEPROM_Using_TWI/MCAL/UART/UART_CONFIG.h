#ifndef _UART_CONFIG_H
	#define _UART_CONFIG_H
	#define F_CPU 8000000UL
	/*data for initialization*/
	#define NumOfUARTChannels 1
	#define UARTChannel_1 1
	/*************************/
	#define UCSRC_Select 1
	#define UBRRH_Select 0
	/*************************/
	#define NumOfInterrupts 3
	#define RxCompleteInterrupt 0
	#define DataBufferEmptyInterrupt 1
	#define TxCompleteInterrupt 2
	/********************************/
	#define Enabled 1
	#define Disabled 0
	#define MaxStrSize 255
	#define BaudRate 9600UL
	#define DoubleSpeedTransmission Enabled
	#define MultiProcessCommunicationMode Disabled
	#if DoubleSpeedTransmission
		#define BaudCalc(Baud) ((uint16_t)(((F_CPU)/(8*(Baud)))-1))
	#else
		#define BaudCalc(Baud) ((uint16_t)(((F_CPU)/(16*(Baud)))-1))
	#endif
	/*STOP BITS NUMBER*/
	#define OneStopBit 0
	#define TwoStopBit 1
	#define StopBitMode OneStopBit
	/*PARITY MODE SELECT*/
	#define ParityDisabled 0
	#define ParityEven 2
	#define ParityOdd 3
	#define ParityMode ParityDisabled
	/*Data Size Select*/
	#define DataSize_5_Bits 0
	#define DataSize_6_Bits 1
	#define DataSize_7_Bits 2
	#define DataSize_8_Bits 3
	#define DataSize_9_Bits 7
	#define Uart_DataSize DataSize_8_Bits
	/*communication mode select*/
	#define Asynch 0
	#define Synch 1
	#define CommunicationMode Asynch



	/*register UART_ControlStatusRegA Bits and Masks*/
	#define UART_MultiProcessorCommunicationMode_BIT 0UL
	#define UART_MultiProcessorCommunicationMode_MSK 1UL
	#define UART_DoubleTransmissionSpeed_BIT 1UL
	#define UART_DoubleTransmissionSpeed_MSK 2UL
	#define UART_ParityErrorFlag_BIT 2UL
	#define UART_ParityErrorFlag_MSK 4UL
	#define UART_DataOverRunFlag_BIT 3UL
	#define UART_DataOverRunFlag_MSK 8UL
	#define UART_FrameErrorFlag_BIT 4UL
	#define UART_FrameErrorFlag_MSK 16UL
	#define UART_DataRegEmptyFlag_BIT 5UL
	#define UART_DataRegEmptyFlag_MSK 32UL
	#define UART_TransmissionCompleteFlag_BIT 6UL
	#define UART_TransmissionCompleteFlag_MSK 64UL
	#define UART_ReceiveCompleteFlag_BIT 7UL
	#define UART_ReceiveCompleteFlag_MSK 128UL
	/*register UART_ControlStatusRegB Bits and Masks*/
	#define UART_TransmissionDataBit_9_BIT 0UL
	#define UART_TransmissionDataBit_9_MSK 1UL
	#define UART_ReceiveDataBit_9_BIT 1UL
	#define UART_ReceiveDataBit_9_MSK 2UL
	#define UART_CharacterSizeBit_2_BIT 2UL
	#define UART_CharacterSizeBit_2_MSK 4UL
	#define UART_TransmissionEnable_BIT 3UL
	#define UART_TransmissionEnable_MSK 8UL
	#define UART_ReceiveEnable_BIT 4UL
	#define UART_ReceiveEnable_MSK 16UL
	#define UART_DataRegisterEmptyInterruptEnable_BIT 5UL
	#define UART_DataRegisterEmptyInterruptEnable_MSK 32UL
	#define UART_TransmissionCompleteInterruptEnable_BIT 6UL
	#define UART_TransmissionCompleteInterruptEnable_MSK 64UL
	#define UART_ReceiveCompleteInterruptEnable_BIT 7UL
	#define UART_ReceiveCompleteInterruptEnable_MSK 128UL
	/*register UART_ControlStatusRegC Bits and Masks*/
	#define UART_CLKPolarity_BIT 0UL
	#define UART_CLKPolarity_MSK 1UL
	#define UART_CharacterSizeBit_0_BIT 1UL
	#define UART_CharacterSizeBit_0_MSK 2UL
	#define UART_CharacterSizeBit_1_BIT 2UL
	#define UART_CharacterSizeBit_1_MSK 4UL
	#define UART_StopBitSelect_BIT 3UL
	#define UART_StopBitSelect_MSK 8UL
	#define UART_ParityModeSelectBit_0_BIT 4UL
	#define UART_ParityModeSelectBit_0_MSK 16UL
	#define UART_ParityModeSelectBit_1_BIT 5UL
	#define UART_ParityModeSelectBit_1_MSK 32UL
	#define UART_SynchAsynchModeSelect_BIT 6UL
	#define UART_SynchAsynchModeSelect_MSK 64UL
	#define UART_RegisterSelect_BIT 7UL
	#define UART_RegisterSelect_MSK 128UL
	#define UART_BaudRateRegH_MSK 15UL
	/*TERMINATION SUCCESS CODES*/
	#define OperationSuccess 0
	/*ERROR CODES*/
	#define Unavailable_UART_Channel 1
	#define ReceiverBuffer_Is_Empty 2
	#define Transmission_Fail 3
	#define Receiving_Fail 4
	#define StringTransimission_Fail 5
	#define StringReceivingFail 6
	#define Setting_CallBack_Fail 7
	#define Interrupt_Disabling_Fail 8
	#define Interrupt_Enabling_Fail 9
	#define OperationStarted 255

#endif
