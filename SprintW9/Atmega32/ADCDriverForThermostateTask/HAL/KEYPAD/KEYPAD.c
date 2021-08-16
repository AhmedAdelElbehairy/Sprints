/*
 * KEYPAD.c
 *
 *  Created on: Jul 26, 2021
 *      Author: zoldeyck
 */
#include "../../Infrastructure/LIB/STD_TYPES.h"
#include "../../Infrastructure/LIB/Bit Operations.h"
#include "../../MCAL/DIO/DIO_DRIVER_TypeDef.h"
#include "../../MCAL/DIO/DIO_DRIVER.h"
#include "../../MCAL/TIM/TIMER_DRIVER_typedefs.h"
#include "../../MCAL/TIM/TIMER_DRIVER.h"
#include "KEYPAD.h"

uint8_t KeypadArr[4][4] = {
						{'7', '8', '9', '/'},
						{'4', '5', '6', 'X'},
						{'1', '2', '3', '-'},
						{'O', '0', '=', '+'}
											};
void KPAD_vidInit(void)
{
	DIO_SetPinDirection(KPAD_ROW_PORT,KPAD_ROW0,PIN_INPUT);
	DIO_SetPinDirection(KPAD_ROW_PORT,KPAD_ROW1,PIN_INPUT);
	DIO_SetPinDirection(KPAD_ROW_PORT,KPAD_ROW2,PIN_INPUT);
	DIO_SetPinDirection(KPAD_ROW_PORT,KPAD_ROW3,PIN_INPUT);
	DIO_EnablePinPullup(KPAD_ROW_PORT,KPAD_ROW0);
	DIO_EnablePinPullup(KPAD_ROW_PORT,KPAD_ROW1);
	DIO_EnablePinPullup(KPAD_ROW_PORT,KPAD_ROW2);
	DIO_EnablePinPullup(KPAD_ROW_PORT,KPAD_ROW3);

	DIO_SetPinDirection(KPAD_COLUMN_PORT,KPAD_COLUMN0,PIN_OUTPUT);
	DIO_SetPinDirection(KPAD_COLUMN_PORT,KPAD_COLUMN1,PIN_OUTPUT);
	DIO_SetPinDirection(KPAD_COLUMN_PORT,KPAD_COLUMN2,PIN_OUTPUT);
	DIO_SetPinDirection(KPAD_COLUMN_PORT,KPAD_COLUMN3,PIN_OUTPUT);
	//all initialized at high state
	DIO_WritePin(KPAD_COLUMN_PORT,KPAD_COLUMN0,PIN_HIGH);
	DIO_WritePin(KPAD_COLUMN_PORT,KPAD_COLUMN1,PIN_HIGH);
	DIO_WritePin(KPAD_COLUMN_PORT,KPAD_COLUMN2,PIN_HIGH);
	DIO_WritePin(KPAD_COLUMN_PORT,KPAD_COLUMN3,PIN_HIGH);
}



uint8_t KPAD_GetKey(void)
{
	uint8_t index;
	uint8_t KPAD_auint8_tROW[4]={KPAD_ROW0, KPAD_ROW1, KPAD_ROW2, KPAD_ROW3};
	uint8_t KPAD_auint8_tCOL[4]={KPAD_COLUMN0, KPAD_COLUMN1, KPAD_COLUMN2, KPAD_COLUMN3};
	uint8_t cloop=0;//Columns iterator
	uint8_t rloop=0;//Rows iterator
	uint8_t Accumlator=255;
	for(cloop=0; cloop < 4; cloop++)
	{
		//set only one of the columns with low
		DIO_WritePin(KPAD_COLUMN_PORT, KPAD_auint8_tCOL[cloop],PIN_LOW);
		//check which row pin is low
		for(rloop=0; rloop < 4; rloop++)
		{
			DIO_ReadPin(KPAD_ROW_PORT,KPAD_auint8_tROW[rloop],&Accumlator);
			if(Accumlator==PIN_LOW)
			{
				//delay for avoiding debouncing problem
				TIM_Delay_MS(TIMER0,10);
				//block the code while the button is pressed
				while(Accumlator==PIN_LOW)
				{
				DIO_ReadPin(KPAD_ROW_PORT,KPAD_auint8_tROW[rloop],&Accumlator);
				}

				DIO_WritePin(KPAD_COLUMN_PORT, KPAD_auint8_tCOL[cloop],PIN_HIGH);
//				index=(rloop*4)+(cloop);
				index = KeypadArr[rloop][cloop];
				rloop=4;
				cloop=4;
			}
			else
			{
				index=KPAD_NO_KPRESSED;
			}
		}
		DIO_WritePin(KPAD_COLUMN_PORT, KPAD_auint8_tCOL[cloop],PIN_HIGH);
	}
	return index;
}
