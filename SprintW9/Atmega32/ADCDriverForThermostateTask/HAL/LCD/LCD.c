#define F_CPU 8000000UL
#include "../../Infrastructure/LIB/STD_TYPES.h"
#include "../../Infrastructure/LIB/Bit Operations.h"
#include "../../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../../MCAL/DIO/DIO_DRIVER.h"
#include "../../MCAL/TIM/TIMER_DRIVER_typedefs.h"
#include "../../MCAL/TIM/TIMER_DRIVER.h"
#include "LCD.h"

void LCD_SendCommand(uint8_t CMD)
{
	DIO_WritePin(LCD_PORT,LCD_D7,READ_BIT(CMD,7));
	DIO_WritePin(LCD_PORT,LCD_D6,READ_BIT(CMD,6));
	DIO_WritePin(LCD_PORT,LCD_D5,READ_BIT(CMD,5));
	DIO_WritePin(LCD_PORT,LCD_D4,READ_BIT(CMD,4));

	DIO_WritePin(LCD_PORT,LCD_RS,PIN_LOW);
	DIO_WritePin(LCD_PORT,LCD_RW,PIN_LOW);
	DIO_WritePin(LCD_PORT,LCD_EN,PIN_HIGH);
	DIO_WritePin(LCD_PORT,LCD_EN,PIN_LOW);

	DIO_WritePin(LCD_PORT,LCD_D7,READ_BIT(CMD,3));
	DIO_WritePin(LCD_PORT,LCD_D6,READ_BIT(CMD,2));
	DIO_WritePin(LCD_PORT,LCD_D5,READ_BIT(CMD,1));
	DIO_WritePin(LCD_PORT,LCD_D4,READ_BIT(CMD,0));

	DIO_WritePin(LCD_PORT,LCD_RS,PIN_LOW);
	DIO_WritePin(LCD_PORT,LCD_RW,PIN_LOW);
	DIO_WritePin(LCD_PORT,LCD_EN,PIN_HIGH);
	DIO_WritePin(LCD_PORT,LCD_EN,PIN_LOW);
}
void LCD_SendCharacter(uint8_t Character)
{
	DIO_WritePin(LCD_PORT, LCD_D7, READ_BIT(Character, 7));
	DIO_WritePin(LCD_PORT, LCD_D6, READ_BIT(Character, 6));
	DIO_WritePin(LCD_PORT, LCD_D5, READ_BIT(Character, 5));
	DIO_WritePin(LCD_PORT, LCD_D4, READ_BIT(Character, 4));

	DIO_WritePin(LCD_PORT, LCD_RS, PIN_HIGH);
	DIO_WritePin(LCD_PORT, LCD_RW, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_EN, PIN_HIGH);
	DIO_WritePin(LCD_PORT, LCD_EN, PIN_LOW);

	DIO_WritePin(LCD_PORT, LCD_D7, READ_BIT(Character, 3));
	DIO_WritePin(LCD_PORT, LCD_D6, READ_BIT(Character, 2));
	DIO_WritePin(LCD_PORT, LCD_D5, READ_BIT(Character, 1));
	DIO_WritePin(LCD_PORT, LCD_D4, READ_BIT(Character, 0));

	DIO_WritePin(LCD_PORT, LCD_RS, PIN_HIGH);
	DIO_WritePin(LCD_PORT, LCD_RW, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_EN, PIN_HIGH);
	DIO_WritePin(LCD_PORT, LCD_EN, PIN_LOW);
}
void LCD_Init()
{
	DIO_SetPinDirection(LCD_PORT, LCD_D7, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_D6, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_D5, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_D4, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_RS, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_RW, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_PORT, LCD_EN, PIN_OUTPUT);

	DIO_WritePin(LCD_PORT, LCD_D7, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_D6, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_D5, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_D4, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_RS, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_RW, PIN_LOW);
	DIO_WritePin(LCD_PORT, LCD_EN, PIN_LOW);

//	TIM_Delay_MS(TIMER0, 40);
	LCD_SendCommand(LCD_Init_CMD_1);
	LCD_SendCommand(LCD_Init_CMD_2);
	LCD_SendCommand(LCD_FUNCSET_6);
	LCD_SendCommand(LCD_DISPON_CURSOFF);
	LCD_SendCommand(LCD_INCREMENTENTRYMODE);
	LCD_SendCommand(LCD_CLR);
//	TIM_Delay_MS(TIMER0, 2);
	LCD_SendCommand(LCD_CURS_Position0);
}
void LCD_SendString(uint8_t* String)
{
	while(*String!='\0')
	{
		LCD_SendCharacter(*String);
		String++;
	}
}
void LCD_SendNumber(uint16_t Number)
{
	uint8_t String[255];
	LCD_NumberToString(Number,String);
	LCD_SendString(String);
}
void LCD_NumberToString(uint16_t Number, uint8_t* String)
{
	uint8_t NumberOfDigits = 0;
	uint8_t* StartOfString = String;
	if(Number==0)
	{
		NumberOfDigits=1;
	}
	else
	{
		while(Number)
		{
			*String=Number%10+48;
			String++;
			Number/=10;
		}
	}
	LCD_StringReverse(StartOfString);
}
void LCD_StringReverse(uint8_t* String)
{
	uint8_t* A = String;
	uint8_t* B = String;
	uint8_t Temp = 0;
	while(*B != '\0')
	{
		B++;
	}
	B--;
	while(A<B)
	{
		//swap
		Temp=*A;
		*A=*B;
		*B=Temp;
		A++;B--;
	}

}
uint8_t LCD_ReadBusyFlag()
{
uint8_t ErrRetVal= OperationStarted;
uint8_t D7Reading=0;
uint8_t State = OperationStarted;
switch(State)
 {
	case OperationStarted:
		DIO_SetPinDirection(LCD_PORT, LCD_D7, PIN_INPUT);
		DIO_WritePin(LCD_PORT, LCD_RS, PIN_LOW);
		DIO_WritePin(LCD_PORT, LCD_RW, PIN_HIGH);
		State = OperationRunning;
		break;
	case OperationRunning:
		DIO_ReadPin(LCD_PORT, LCD_D7, &D7Reading);
		if (D7Reading) {
			ErrRetVal = OperationFail;
		} else {
			State = OperationStarted;
			ErrRetVal = OperationSuccess;
			DIO_SetPinDirection(LCD_PORT, LCD_D7, PIN_OUTPUT);
		}
		break;
	}
	return ErrRetVal;
}
