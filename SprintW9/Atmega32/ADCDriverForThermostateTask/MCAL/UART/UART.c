#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit Operations.h"
#include"UART.h"
void static (*UART_RX_Complete_callback)(void) = NULL;
void static (*UART_UDRE_Empty_callback)(void) = NULL;
void static (*UART_TX_Complete_callback)(void) = NULL;

static uint8_t UART_Set_RX_CompleteCallback(uint8_t UartNumber,
		void (*callBack)(void));
static uint8_t UART_UDRE_Empty_CompleteCallback(uint8_t UartNumber,
		void (*callBack)(void));
static uint8_t UART_Set_TX_CompleteCallback(uint8_t UartNumber,
		void (*callBack)(void));

uint8_t UART_Init(uint8_t UartNumber) {
	uint8_t ErrRetVal = OperationStarted;
	if (UartNumber > NumOfUARTChannels) {
		//error uart channel out of range
		ErrRetVal = Unavailable_UART_Channel;
	} else {
		/* configure control and status register A
		 * (double transmission speed & Multi-processor communication mode) */
		MODIFY_REG(UART_ControlStatusRegA, UART_DoubleTransmissionSpeed_MSK,
				DoubleSpeedTransmission<<UART_DoubleTransmissionSpeed_BIT);
		MODIFY_REG(UART_ControlStatusRegA,
				UART_MultiProcessorCommunicationMode_MSK,
				MultiProcessCommunicationMode<<UART_MultiProcessorCommunicationMode_BIT);

		/* Setting Uart Data Size */
		MODIFY_REG(UART_ControlStatusRegB, UART_CharacterSizeBit_2_MSK,
				READ_BIT(Uart_DataSize,2)<<UART_CharacterSizeBit_2_BIT);
		SET_BIT(UART_ControlStatusRegC, UART_RegisterSelect_BIT);
		MODIFY_REG(UART_ControlStatusRegC, UART_CharacterSizeBit_1_MSK,
				READ_BIT(Uart_DataSize,1)<<UART_CharacterSizeBit_1_BIT);
		MODIFY_REG(UART_ControlStatusRegC, UART_CharacterSizeBit_0_MSK,
				READ_BIT(Uart_DataSize,0)<<UART_CharacterSizeBit_0_BIT);

		/* setting Stop Bit */
		MODIFY_REG(UART_ControlStatusRegC, UART_StopBitSelect_MSK,
				StopBitMode<<UART_StopBitSelect_BIT);

		/* Setting Parity mode */
		MODIFY_REG(UART_ControlStatusRegC, UART_ParityModeSelectBit_1_MSK,
				READ_BIT(ParityMode,1)<<UART_ParityModeSelectBit_1_BIT);
		MODIFY_REG(UART_ControlStatusRegC, UART_ParityModeSelectBit_0_MSK,
				READ_BIT(ParityMode,0)<<UART_ParityModeSelectBit_0_BIT);
		/* Setting communication mode (synch. or Asynch.)*/
		MODIFY_REG(UART_ControlStatusRegC, UART_SynchAsynchModeSelect_MSK,
				CommunicationMode<<UART_SynchAsynchModeSelect_BIT);

		/*Set Clock Poalrity*/
		// ignored as all our work is asynchronus communication mode.
		/*Set the value of baud rate register*/
		CLEAR_BIT(UART_BaudRateRegH, UART_RegisterSelect_BIT);
		MODIFY_REG(UART_BaudRateRegH, UART_BaudRateRegH_MSK,
				(BaudCalc(BaudRate)>>8)&0x0F);
		WRITE_REG(UART_BaudRateRegL, BaudCalc(BaudRate)&0xFF);

		/* Enabling receiving and transmitting*/
		MODIFY_REG(UART_ControlStatusRegB, UART_ReceiveEnable_MSK,
				UART_ReceiveEnable_MSK);
		MODIFY_REG(UART_ControlStatusRegB, UART_TransmissionEnable_MSK,
				UART_TransmissionEnable_MSK);
		ErrRetVal = OperationSuccess;
	}
	return ErrRetVal;
}
uint8_t UART_FlushReceiveBuffer(void) {
	uint8_t ErrRetVal = OperationStarted;
	uint8_t flushedCharacter;
	flushedCharacter = UART_DataReg;
	ErrRetVal = OperationSuccess;
	return ErrRetVal;
}
uint8_t UART_SetCallback(uint8_t UartNumber,uint8_t UartInterruptType,void (*callBack)(void)) {
	uint8_t ErrRetVal = OperationStarted;
	switch (UartInterruptType) {
	case RxCompleteInterrupt:
		UART_Set_RX_CompleteCallback(UartNumber, callBack);
		break;
	case DataBufferEmptyInterrupt:
		UART_UDRE_Empty_CompleteCallback(UartNumber, callBack);
		break;
	case TxCompleteInterrupt:
		UART_Set_TX_CompleteCallback(UartNumber, callBack);
		break;
	default:
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}

uint8_t UART_TransmitChar(uint8_t UartNumber, uint8_t TxChar) {
	uint8_t ErrRetVal = OperationStarted;
	if (READ_BIT(UART_ControlStatusRegA, 5)) {
		UART_DataReg = TxChar;
		ErrRetVal = OperationSuccess;
	} else {
		ErrRetVal = Transmission_Fail;
	}
	return ErrRetVal;
}
uint8_t UART_ReceiveChar(uint8_t UartNumber, ptr_uint8_t RxChar) {
	uint8_t ErrRetVal = OperationStarted;
	if (READ_BIT(UART_ControlStatusRegA,7) == 1) {
		*RxChar = UART_DataReg;
		ErrRetVal = OperationSuccess;
	} else {
		ErrRetVal = Receiving_Fail;
	}
	return ErrRetVal;
}

uint8_t UART_TransmitString(uint8_t UartNumber, ptr_uint8_t TxString) {
	uint8_t ErrRetVal = OperationStarted;
	uint8_t iterator = 0;
	while (iterator <= 255) {
		if (*TxString == '\0') {
			ErrRetVal = OperationSuccess;
			while (UART_TransmitChar(UartNumber, '\r') != OperationSuccess)
				;
			break;
		} else {
			while (UART_TransmitChar(UartNumber, *TxString) != OperationSuccess)
				;
			iterator++;
			TxString++;
		}
	}
	return ErrRetVal;
}
uint8_t UART_ReceiveString(uint8_t UartNumber, ptr_uint8_t RxString) {
	uint8_t ErrRetVal = OperationStarted;
	uint8_t iterator = 0;
	while (iterator <= 255) {
		if (UART_ReceiveChar(UartNumber, RxString) == OperationSuccess) {
			if (*RxString == '\r' || *RxString == '\n') {
				*RxString = '\0';
				ErrRetVal = OperationSuccess;
				break;
			} else {
				RxString++;
				iterator++;
			}
		} else {
			continue;
		}
	}
	return ErrRetVal;
}

uint8_t UART_EnableInterrupt(uint8_t UartNumber, uint8_t UartInterruptType) {
	uint8_t ErrRetVal = OperationStarted;
	/*Enable Global Interrupt*/
	SET_BIT(STATUS_REG, 7);
	/*Enable Local Interrupt*/
	if (UartInterruptType < NumOfInterrupts) {
		switch (UartInterruptType) {
		case RxCompleteInterrupt:
			MODIFY_REG(UART_ControlStatusRegB,
					UART_ReceiveCompleteInterruptEnable_MSK,
					UART_ReceiveCompleteInterruptEnable_MSK);
			ErrRetVal = OperationSuccess;
			break;
		case DataBufferEmptyInterrupt:
			MODIFY_REG(UART_ControlStatusRegB,
					UART_DataRegisterEmptyInterruptEnable_MSK,
					UART_DataRegisterEmptyInterruptEnable_MSK);
			ErrRetVal = OperationSuccess;
			break;
		case TxCompleteInterrupt:
			MODIFY_REG(UART_ControlStatusRegB,
					UART_TransmissionCompleteInterruptEnable_MSK,
					UART_TransmissionCompleteInterruptEnable_MSK);
			ErrRetVal = OperationSuccess;
			break;
		default:
			ErrRetVal = Interrupt_Enabling_Fail;
		}
	} else {
		ErrRetVal = Interrupt_Enabling_Fail;
	}
	return ErrRetVal;
}
uint8_t UART_DisableInterrupt(uint8_t UartNumber, uint8_t UartInterruptType) {
	uint8_t ErrRetVal = OperationStarted;
	/*Disable Local Interrupt*/
	if (UartInterruptType < NumOfInterrupts) {
		switch (UartInterruptType) {
		case RxCompleteInterrupt:
			CLEAR_BIT(UART_ControlStatusRegB,
					UART_ReceiveCompleteInterruptEnable_BIT);
			ErrRetVal = OperationSuccess;
			break;
		case DataBufferEmptyInterrupt:
			CLEAR_BIT(UART_ControlStatusRegB,
					UART_DataRegisterEmptyInterruptEnable_BIT);
			ErrRetVal = OperationSuccess;
			break;
		case TxCompleteInterrupt:
			CLEAR_BIT(UART_ControlStatusRegB,
					UART_TransmissionCompleteInterruptEnable_BIT);
			ErrRetVal = OperationSuccess;
			break;
		default:
			ErrRetVal = Interrupt_Disabling_Fail;
		}
	} else {
		ErrRetVal = Interrupt_Disabling_Fail;
	}
	return ErrRetVal;
}

uint8_t UART_Set_RX_CompleteCallback(uint8_t UartNumber, void (*callBack)(void)) {
	uint8_t ErrRetVal = 0;
	if (callBack != NULL)
		UART_RX_Complete_callback = callBack;
	return ErrRetVal;
}
uint8_t UART_UDRE_Empty_CompleteCallback(uint8_t UartNumber,
		void (*callBack)(void)) {
	uint8_t ErrRetVal = 0;
	if (callBack != NULL)
		UART_UDRE_Empty_callback = callBack;
	return ErrRetVal;
}
uint8_t UART_Set_TX_CompleteCallback(uint8_t UartNumber, void (*callBack)(void)) {
	uint8_t ErrRetVal = 0;
	if (callBack != NULL)
		UART_TX_Complete_callback = callBack;
	return ErrRetVal;
}

void __vector_13(void) {
	if (UART_RX_Complete_callback != NULL)
		UART_RX_Complete_callback();
}
void __vector_14(void) {
	if (UART_UDRE_Empty_callback != NULL)
		UART_UDRE_Empty_callback();
}
void __vector_15(void) {
	if (UART_TX_Complete_callback != NULL)
		UART_TX_Complete_callback();
}

