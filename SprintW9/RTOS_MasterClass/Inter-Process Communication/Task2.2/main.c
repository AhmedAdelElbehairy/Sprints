/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include "bit_math.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
static void UART_SendString(char*,int);
/*-----------------------------------------------------------*/


/*
 *Type definitions.
 */
typedef struct{
	char* String;
	int StringLength;
}Queue_Element_t;
/*-----------------------------------------------------------*/


/*
 *Semaphors/mutex/Queues/EventFlags handlers.
 */
QueueHandle_t UART_1_Queue;
/*-----------------------------------------------------------*/


/*
 *Task functions handlers.
 */
TaskHandle_t Button_1_Handler = NULL;
TaskHandle_t Button_2_Handler = NULL;
TaskHandle_t Consumer_Handler = NULL;
TaskHandle_t Periodic_String_Handler = NULL;
/*-----------------------------------------------------------*/


/*
 *Task functions prototypes.
 */
void Button_1( void* );
void Button_2( void* );
void Consumer( void* );
void Periodic_String( void* );
/*-----------------------------------------------------------*/


/*
 *Global Variables.
 */
 char String_1[] = "Falling Edge Detected At Button One\n";//36
 char String_2[] = "Rising Edge Detected At Button One\n";//35
 char String_3[] = "Falling Edge Detected At Button Two\n";//36
 char String_4[] = "Rising Edge Detected At Button Two\n";//35
 char String_5[] = "The Periodic String\n";//20
/*-----------------------------------------------------------*/
 
 
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	volatile int i = 0;
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	/* Create Queues/semaphores/mutex/EventFlags here */
	UART_1_Queue = xQueueCreate(3,sizeof(Queue_Element_t));
  /* Create Tasks here */
	xTaskCreate(Button_1, "Button_1", 45, NULL, 1, &Button_1_Handler);
	xTaskCreate(Button_2, "Button_2", 45, NULL, 1, &Button_2_Handler);
	xTaskCreate(Consumer, "Consumer", 45, NULL, 1, &Consumer_Handler);
	xTaskCreate(Periodic_String, "Periodic", 45, NULL, 1, &Periodic_String_Handler);

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/
static void UART_SendString(char* string,int string_length)
{
	int i = 0;
	for(i = 0; i < string_length; i++)
	{
		xSerialPutChar(string[i]);
		while(GET_BIT(U1LSR,6)==0);
	}
}



void Button_1( void* parameter)
{
	Queue_Element_t Queue_Element_Button_1;
	int oldState = PIN_IS_HIGH;
	int currentState;
	for(;;)
	{
		currentState = GPIO_read(PORT_0,PIN0);
		if((currentState == PIN_IS_HIGH) && (oldState == PIN_IS_LOW))//rising edge
		{
			Queue_Element_Button_1.String = String_2;
			Queue_Element_Button_1.StringLength = 35;
			xQueueSend(UART_1_Queue, &Queue_Element_Button_1, portMAX_DELAY);
			
		}
		else if((currentState == PIN_IS_LOW) && (oldState == PIN_IS_HIGH))//Falling edge
		{
			Queue_Element_Button_1.String = String_1;
			Queue_Element_Button_1.StringLength = 36;
			xQueueSend(UART_1_Queue, &Queue_Element_Button_1, portMAX_DELAY);
		}
		oldState = currentState;
		vTaskDelay(20);
	}
}
 


void Button_2( void* parameter)
{
	Queue_Element_t Queue_Element_Button_2;
	int oldState = PIN_IS_HIGH;
	int currentState;
	for(;;)
	{
		currentState = GPIO_read(PORT_0,PIN1);
		if((currentState == PIN_IS_HIGH) && (oldState == PIN_IS_LOW))//rising edge
		{
			Queue_Element_Button_2.String = String_4;
			Queue_Element_Button_2.StringLength = 35;
			xQueueSend(UART_1_Queue, &Queue_Element_Button_2, portMAX_DELAY);
			
		}
		else if((currentState == PIN_IS_LOW) && (oldState == PIN_IS_HIGH))//Falling edge
		{
			Queue_Element_Button_2.String = String_3;
			Queue_Element_Button_2.StringLength = 36;
			xQueueSend(UART_1_Queue, &Queue_Element_Button_2, portMAX_DELAY);
		}
		oldState = currentState;
		vTaskDelay(20);
	}
}


void Consumer( void* parameter)
{
	Queue_Element_t Queue_Element_Consumer;
	for(;;)
	{
		if(xQueueReceive(UART_1_Queue, &Queue_Element_Consumer, portMAX_DELAY))
		{
			UART_SendString(Queue_Element_Consumer.String, Queue_Element_Consumer.StringLength);
		}
		vTaskDelay(50);
	}
}


void Periodic_String( void* parameter)
{
	Queue_Element_t Queue_Element_Periodic_String;
	Queue_Element_Periodic_String.String = String_5;
	Queue_Element_Periodic_String.StringLength = 20;
	for(;;)
	{
		xQueueSend(UART_1_Queue, &Queue_Element_Periodic_String, portMAX_DELAY);
		vTaskDelay(100);
	}
}
