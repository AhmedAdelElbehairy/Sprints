#ifndef __DIO_DRIVER_H__
	#define __DIO_DRIVER_H__
	
	#define PIN0 0
	#define PIN1 1
	#define PIN2 2
	#define PIN3 3
	#define PIN4 4
	#define PIN5 5
	#define PIN6 6
	#define PIN7 7
	
	#define PORTA 1
	#define PORTB 2
	#define PORTC 3
	#define PORTD 4
	
	#define PIN_INPUT  0
	#define PIN_OUTPUT 1
	
	#define PIN_LOW  0 
	#define PIN_HIGH 1
	
	#define PORT_INPUT  0x00
	#define PORT_OUTPUT 0xFF
	
	#define PORT_LOW  0x00
	#define PORT_HIGH 0xFF
	
	#define EXIT_SUCCESFUL 0
	#define EXIT_FAILURE   1
		
	
	DIO_ERROR_RETVAL_t DIO_PortInit (DIO_PORT_ID_t port, DIO_DIRECTION_t direction);
	DIO_ERROR_RETVAL_t DIO_PinInit (DIO_PORT_ID_t port, DIO_PIN_ID_t pin, DIO_DIRECTION_t direction);
	DIO_ERROR_RETVAL_t DIO_PinEnablePullUp (DIO_PORT_ID_t port, DIO_PIN_ID_t pin);
	DIO_ERROR_RETVAL_t DIO_SetPortVal (DIO_PORT_ID_t port, Byte value);
	DIO_ERROR_RETVAL_t DIO_SetPinVal (DIO_PORT_ID_t port, DIO_PIN_ID_t pin, Byte value);
	Byte DIO_GetPortVal (DIO_PORT_ID_t port);
	Byte DIO_GetPinVal (DIO_PORT_ID_t port, DIO_PIN_ID_t pin);
	
#endif