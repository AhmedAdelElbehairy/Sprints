#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit Operations.h"
#include "TWI.h"

/*static functions*/
static void TWI_SetClk(void);


uint8_t TWI_Init(uint8_t TWI_channel)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;

	/*setting control register to default value*/
	WRITE_REG(TWI_ControlRegister, ResgisterDefaultVal);

	/*Set TWI CLK (SCL)*/
	TWI_SetClk();

	/*Set the Device Address*/
	TWI_AddressRegister = (deviceAddress<<1);

	/*Enable or Disable general call*/
	if(GeneralCallRecognition==Enabled)
	{
		SET_BIT(TWI_AddressRegister,TWI_GeneralCallRecognitionEnable_BIT);
	}
	else
	{
		CLEAR_BIT(TWI_AddressRegister,TWI_GeneralCallRecognitionEnable_BIT);
	}

	/*clear the interrupt flag*/
	SET_BIT(TWI_ControlRegister,TWI_InterruptFlag_BIT);

	/*Enable TWI_Module*/
	SET_BIT(TWI_ControlRegister,TWI_ModuleEnable_BIT);

	return ErrRetVal;
}

uint8_t TWI_ReadDataWithACK(uint8_t TWI_channel, ptr_uint8_t Data)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;

	switch(State)
	{
	/*Function's Starting State*/
	case OperationStarted:
		/*clear start, stop and enable Acknowledge bits*/
		TWI_ControlRegister &=0x07;

		/*Set enable_acknowledgement bit and Clearing the interrupt flag*/
		MODIFY_REG(TWI_ControlRegister,
				TWI_StartCondition_MSK|TWI_EnableAcknowledge_MSK|TWI_StopCondition_MSK|TWI_InterruptFlag_MSK,
				TWI_EnableAcknowledge_MSK|TWI_InterruptFlag_MSK);

		/*changing the function state*/
		State = FlagLowForReadDataWithACK;
		break;
	/*Function's Ending State*/
	case FlagLowForReadDataWithACK:
		/*Checking if TWI-interrupt Flag is raised for Data Reading event*/
		if((TWI_ControlRegister&TWI_InterruptFlag_MSK))
		{
			/*Submit DATA received to the argument used for data return*/
			*Data=TWI_DataRegister;

			/*reseting the Functions State*/
			State=OperationStarted;

			/*setting Error return value to OperationSuccess*/
			ErrRetVal=OperationSuccess;
		}
		break;
	default:
		/*setting Error return value to OperationFail*/
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}

uint8_t TWI_ReadDataWithNACK(uint8_t TWI_channel, ptr_uint8_t Data)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;

	switch(State)
	{
	/*Function's Starting State*/
	case OperationStarted:
		/*clear start, stop and enable Acknowledge bits*/
		TWI_ControlRegister &=0x07;

		/*Clear interrupt flag manually*/
		SET_BIT(TWI_ControlRegister, TWI_InterruptFlag_BIT);

		/*changing the function state*/
		State = FlagLowForReadDataWithNACK;
		break;
	/*Function's Ending State*/
	case FlagLowForReadDataWithNACK:
		/*Checking if TWI-interrupt Flag is raised for Data Reading event*/
		if((TWI_ControlRegister&TWI_InterruptFlag_MSK))
		{
			/*Submit DATA received to the argument used for data return*/
			*Data=TWI_DataRegister;

			/*reseting the Functions State*/
			State=OperationStarted;

			/*setting Error return value to OperationSuccess*/
			ErrRetVal=OperationSuccess;
		}
		break;
	default:
		/*setting Error return value to OperationFail*/
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}

uint8_t TWI_WriteData(uint8_t TWI_channel, uint8_t Data)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;

	switch (State)
	{
	/*Function's Starting State*/
	case OperationStarted:
		/*clear start, stop and enable Acknowledge bits*/
		TWI_ControlRegister &= 0x07;

		/*set the data register*/
		TWI_DataRegister = Data;

		/*Clear interrupt flag manually*/
		SET_BIT(TWI_ControlRegister, TWI_InterruptFlag_BIT);

		/*changing the function state*/
		State = FlagLowForWritingDataRegister;
		break;
	/*Function's Ending State*/
	case FlagLowForWritingDataRegister:
		/*Checking if TWI-interrupt Flag is raised for Data Writing event*/
		if ((TWI_ControlRegister & TWI_InterruptFlag_MSK)) {
			/*reseting the Functions State*/
			State = OperationStarted;

			/*setting Error return value to OperationSuccess*/
			ErrRetVal = OperationSuccess;
		}
		break;
	default:
		/*setting Error return value to OperationFail*/
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}

uint8_t TWI_SendStartCondition(uint8_t TWI_channel)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;

	switch (State)
	{
	/*Function's Starting State*/
	case OperationStarted:
		/*Clearing bits of control register except TWI_Enable and TWI_Interrupt Bits*/
		TWI_ControlRegister=0x07;

		/*Set start_condition bit and Clearing the interrupt flag*/
		MODIFY_REG(TWI_ControlRegister,
				TWI_StartCondition_MSK|TWI_EnableAcknowledge_MSK|TWI_StopCondition_MSK|TWI_InterruptFlag_MSK,
				TWI_StartCondition_MSK|TWI_InterruptFlag_MSK);

		/*changing the function state*/
		State = StartConditionFiredInterruptFlagLow;
		break;
	/*Function's Ending State*/
	case StartConditionFiredInterruptFlagLow:
		/*Checking if TWI-interrupt Flag is raised for Starting event*/
		if((TWI_ControlRegister&TWI_InterruptFlag_MSK))
		{
			/*reseting the Functions State*/
			State=OperationStarted;

			/*setting Error return value to OperationSuccess*/
			ErrRetVal=OperationSuccess;
		}
		break;
	default:
		/*setting Error return value to OperationFail*/
		ErrRetVal=OperationFail;
	}
	return ErrRetVal;
}

uint8_t TWI_SendStopCondition(uint8_t TWI_channel)
{
	/*function variables initialization*/
	uint8_t ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;

	switch (State) {
	/*Function's Starting State*/
	case OperationStarted:
		/*Clearing bits of control register except TWI_Enable and TWI_Interrupt Bits*/
		TWI_ControlRegister = 0x07;

		/*Setting The stop_condition bit and Clearing the interrupt flag*/
		MODIFY_REG(TWI_ControlRegister,
				TWI_StartCondition_MSK|TWI_EnableAcknowledge_MSK|TWI_StopCondition_MSK|TWI_InterruptFlag_MSK,
				TWI_StopCondition_MSK|TWI_InterruptFlag_MSK);

		/*Changing the State of the Function*/
		State=StopConditionFired;
		break;
	/*Function's Ending State*/
	case StopConditionFired:
		/*checking if the Stop-condition Bit is reseted to zero or not*/
		if (!(TWI_ControlRegister & TWI_StopCondition_MSK)) {
			/*reseting the Functions State*/
			State = OperationStarted;

			/*setting Error return value to OperationSuccess*/
			ErrRetVal = OperationSuccess;
		}
		break;
	default:
		/*setting Error return value to OperationFail*/
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}

uint8_t TWI_GetStatus()
{
	uint8_t statusRegVal=0;
	statusRegVal = TWI_StatusRegister & TWI_Status_MSK;
	return	statusRegVal;
}

void TWI_EnableACK()
{
	TWI_ControlRegister &=0x07;

	/*Set enable_acknowledgement bit and Clearing the interrupt flag*/
	MODIFY_REG(TWI_ControlRegister,
			TWI_StartCondition_MSK|TWI_EnableAcknowledge_MSK|TWI_StopCondition_MSK|TWI_InterruptFlag_MSK,
			TWI_EnableAcknowledge_MSK|TWI_InterruptFlag_MSK);
}

static void TWI_SetClk(void)
{
	uint8_t TWBR,Prescalar;
	uint8_t Flag = 0;
	for(Prescalar=1; Prescalar<=64; Prescalar=Prescalar*4)
	{
		for(TWBR=1; TWBR<=255; TWBR++)
		{
			if((TWBR*Prescalar)==ClockRatio)
			{
				Flag=1;
				break;
			}
			else
			{
				continue;
			}
		}
		if(Flag==1)
		{
			TWI_BaudRateRegister=TWBR;
			MODIFY_REG(TWI_StatusRegister,TWI_Prescalar_MSK,Prescalar/4);
			break;
		}
		else if(TWBR==255 && Prescalar==64)
		{
			//required SCL isn't available.
			TWI_BaudRateRegister=0;
			MODIFY_REG(TWI_StatusRegister,TWI_Prescalar_MSK,0);
		}
		else
		{
			continue;
		}
	}
}

