/*
 * STRING.c
 *
 *  Created on: Aug 6, 2021
 *      Author: zoldeyck
 */
#include "STD_TYPES.h"
#include "STRING.h"
uint8_t STR_Length(uint8_t* String, uint16_t* StringLength)
{
	*StringLength = 0;
	while(*String!='\0')
	{
		(*StringLength)++;
		String++;
	}
	return 0;
}
uint8_t STR_CharIsNumeric(uint8_t Character, uint8_t* Result)
{
	if(Character>=48 && Character<=57)
	{
		*Result=1;
	}
	else
	{
		*Result=0;
	}
	return 0;
}
uint8_t STR_StringIsNumeric(uint8_t* String, uint8_t* Result)
{
	uint8_t FunRetVal = 0;
	while(*String!='\0')
	{
		STR_CharIsNumeric(*String,&FunRetVal);
		if(!FunRetVal)
		{
			*Result = 0;
			break;
		}
		else
		{
			*Result = 1;
			String++;
			continue;
		}
	}
	return 0;
}
uint8_t STR_CompareString(uint8_t* String_1, uint8_t* String_2, uint8_t* Result)
{
	while(1)
	{
		if(*String_1==*String_2)
		{
			*Result = 1;
			String_1++;
			String_2++;
			if(*String_1=='\0'&&*String_2=='\0')
				break;
			continue;
		}
		else if(*String_1=='\0'&&*String_2=='\0')
		{
			*Result = 1;
			break;
		}
		else
		{
			*Result = 0;
			break;
		}
	}
	return 0;
}
uint8_t STR_String2Number(uint8_t* String, uint16_t* Number)
{
	uint32_t Multiplier=1;
	uint8_t* StartOfString=String;
	*Number=0;
	while(*String!='\0')
	{
		String++;
	}

	do
	{
		String--;
		(*Number)+=((*String-48)*Multiplier);
		Multiplier*=10;
	}while(String!=StartOfString);
	return 0;
}
uint8_t STR_Number2String(uint32_t Number, uint8_t* String)
{
	if(Number==0)
	{
		*String='0';
	}
	else
	{
		do
		{
			*String = (Number%10)+48;
			String++;
			Number%=10;
		}while(Number);
	}
	STR_StringReverse(String);
	return 0;
}
uint8_t STR_StringReverse(uint8_t* String)
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
	return 0;
}

