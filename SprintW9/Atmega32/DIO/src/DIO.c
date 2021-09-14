#include "MC_REGISTERS.h"
#include "LIB.h"
#include "DIO.h"

uint8_t DIO_PortInit(uint8_t DIO_port, uint8_t DIO_direction) {
	/*initialize the return value variable*/
	uint8_t ErrorValue = OperationStarted;
	/*Check that the the input arguments are in the acceptable range*/
	if ((DIO_port <= PORTD)	&& (DIO_direction == PORT_INPUT || DIO_direction == PORT_OUTPUT)) 
	{
		switch (DIO_port) {
		case PORTA:
			WRITE_REG(DDRA, DIO_direction);
			ErrorValue = OperationSuccess;
			break;
		case PORTB:
			WRITE_REG(DDRB, DIO_direction);
			ErrorValue = OperationSuccess;
			break;
		case PORTC:
			WRITE_REG(DDRC, DIO_direction);
			ErrorValue = OperationSuccess;
			break;
		case PORTD:
			WRITE_REG(DDRD, DIO_direction);
			ErrorValue = OperationSuccess;
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_PinInit(uint8_t DIO_port, uint8_t DIO_pin, uint8_t DIO_direction) 
{
	/*initialize the return value variable*/
	uint8_t ErrorValue = OperationStarted;
	/*Check that the the input arguments are in the acceptable range*/
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) 
	{
		/*Check that the required direction of the pin is Output*/
		if (DIO_direction == PIN_OUTPUT) 
		{
			switch (DIO_port) {
			case PORTA:
				SET_BIT(DDRA, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTB:
				SET_BIT(DDRB, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTC:
				SET_BIT(DDRC, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTD:
				SET_BIT(DDRD, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			default:
				ErrorValue = OperationFail;
				break;
			}
		} 
		/*Check that the required direction of the pin is Input*/
		else if (DIO_direction == PIN_INPUT) 
		{
			switch (DIO_port) 
			{
			case PORTA:
				CLEAR_BIT(DDRA, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTB:
				CLEAR_BIT(DDRB, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTC:
				CLEAR_BIT(DDRC, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			case PORTD:
				CLEAR_BIT(DDRD, DIO_pin);
				ErrorValue = OperationSuccess;
				break;
			default:
				ErrorValue = OperationFail;
				break;
			}
		}

		else {
			ErrorValue = OperationFail;
		}
	}

	else {
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_PinEnablePullUp(uint8_t DIO_port, uint8_t DIO_pin) 
{
	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {
		/* Check on the Required PORT Number */
		switch (DIO_port) {
		case PORTA:
			if (READ_BIT(DDRA, DIO_pin) == PIN_INPUT) 
			{
				SET_BIT(PORTA, DIO_pin);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTB:
			if (READ_BIT(DDRB, DIO_pin) == PIN_INPUT) 
			{
				SET_BIT(PORTB, DIO_pin);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTC:
			if (READ_BIT(DDRC, DIO_pin) == PIN_INPUT) 
			{
				SET_BIT(PORTC, DIO_pin);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTD:
			if (READ_BIT(DDRD, DIO_pin) == PIN_INPUT) 
			{
				SET_BIT(PORTD, DIO_pin);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_SetPortVal(uint8_t DIO_port, uint8_t value) 
{
	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD)) 
	{
		switch (DIO_port) 
		{
		case PORTA:
			WRITE_REG(PORTA, value);
			ErrorValue = OperationSuccess;
			break;
		case PORTB:
			WRITE_REG(PORTB, value);
			ErrorValue = OperationSuccess;
			break;
		case PORTC:
			WRITE_REG(PORTC, value);
			ErrorValue = OperationSuccess;
			break;
		case PORTD:
			WRITE_REG(PORTD, value);
			ErrorValue = OperationSuccess;
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_SetPinVal(uint8_t DIO_port, uint8_t DIO_pin, uint8_t value) {

	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) 
	{
		if (value == PIN_HIGH) 
		{

			switch (DIO_port) {
			case PORTA:
				if (READ_BIT(DDRA, DIO_pin) == PIN_OUTPUT) 
				{
					SET_BIT(PORTA, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTB:
				if (READ_BIT(DDRB, DIO_pin) == PIN_OUTPUT) 
				{
					SET_BIT(PORTB, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTC:
				if (READ_BIT(DDRC, DIO_pin) == PIN_OUTPUT) 
				{
					SET_BIT(PORTC, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTD:
				if (READ_BIT(DDRD, DIO_pin) == PIN_OUTPUT) {
					SET_BIT(PORTD, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			default:
				ErrorValue = OperationFail;
				break;
			}
		} 
		else if (value == PIN_LOW) 
		{
			switch (DIO_port) 
			{
			case PORTA:
				if (READ_BIT(DDRA, DIO_pin) == PIN_OUTPUT) 
				{
					CLEAR_BIT(PORTA, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTB:
				if (READ_BIT(DDRB, DIO_pin) == PIN_OUTPUT) 
				{
					CLEAR_BIT(PORTB, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTC:
				if (READ_BIT(DDRC, DIO_pin) == PIN_OUTPUT) 
				{
					CLEAR_BIT(PORTC, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			case PORTD:
				if (READ_BIT(DDRD, DIO_pin) == PIN_OUTPUT) 
				{
					CLEAR_BIT(PORTD, DIO_pin);
					ErrorValue = OperationSuccess;
				} 
				else 
				{
					ErrorValue = OperationFail;
				}
				break;
			default:
				ErrorValue = OperationFail;
				break;
			}
		} 
		else 
		{
			ErrorValue = OperationFail;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_GetPortVal(uint8_t DIO_port, uint8_t* PortVal) {
	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD)) {
		/* Check on the Required PORT Number */
		switch (DIO_port) {
		case PORTA:
			*PortVal = READ_REG(PINA);
			ErrorValue = OperationSuccess;
			break;
		case PORTB:
			*PortVal = READ_REG(PINB);
			ErrorValue = OperationSuccess;
			break;
		case PORTC:
			*PortVal = READ_REG(PINC);
			ErrorValue = OperationSuccess;
			break;
		case PORTD:
			*PortVal = READ_REG(PIND);
			ErrorValue = OperationSuccess;
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} else {
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_GetPinVal(uint8_t DIO_port, uint8_t DIO_pin, uint8_t *PinVal) {

	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {

		switch (DIO_port) {
		case PORTA:
			*PinVal = READ_BIT(PINA, DIO_pin);
			ErrorValue = OperationSuccess;
			break;
		case PORTB:
			*PinVal = READ_BIT(PINB, DIO_pin);
			ErrorValue = OperationSuccess;
			break;
		case PORTC:
			*PinVal = READ_BIT(PINC, DIO_pin);
			ErrorValue = OperationSuccess;
			break;
		case PORTD:
			*PinVal = READ_BIT(PIND, DIO_pin);
			ErrorValue = OperationSuccess;
			break;
		default:
			ErrorValue = OperationFail;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}

	return ErrorValue;
}

uint8_t DIO_TogPortVal(uint8_t DIO_port, uint8_t value) {
	uint8_t ErrorValue = OperationStarted;
	if ((DIO_port <= PORTD)) 
	{
		switch (DIO_port) 
		{
		case PORTA:
			if (READ_REG(DDRA) == PORT_OUTPUT) 
			{
				TOG_REG(PORTA, value);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTB:
			if (READ_REG(DDRB) == PORT_OUTPUT) 
			{
				TOG_REG(PORTB, value);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTC:
			if (READ_REG(DDRC) == PORT_OUTPUT) 
			{
				TOG_REG(PORTC, value);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTD:
			if (READ_REG(DDRD) == PORT_OUTPUT) 
			{
				TOG_REG(PORTD, value);
				ErrorValue = OperationSuccess;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

uint8_t DIO_TogPinVal(uint8_t DIO_port, uint8_t DIO_pin) {
	uint8_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) 
	{
		switch (DIO_port) 
		{
		case PORTA:
			if (READ_BIT(DDRA, DIO_pin) == PIN_OUTPUT) 
			{
				TOG_BIT(PORTA, DIO_pin);
				ErrorValue = OperationStarted;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTB:
			if (READ_BIT(DDRB, DIO_pin) == PIN_OUTPUT) 
			{
				TOG_BIT(PORTB, DIO_pin);
				ErrorValue = OperationStarted;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTC:
			if (READ_BIT(DDRC, DIO_pin) == PIN_OUTPUT) 
			{
				TOG_BIT(PORTC, DIO_pin);
				ErrorValue = OperationStarted;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		case PORTD:
			if (READ_BIT(DDRD, DIO_pin) == PIN_OUTPUT) 
			{
				TOG_BIT(PORTD, DIO_pin);
				ErrorValue = OperationStarted;
			} 
			else 
			{
				ErrorValue = OperationFail;
			}
			break;
		default:
			ErrorValue = OperationFail;
			break;
		}
	} 
	else 
	{
		ErrorValue = OperationFail;
	}
	return ErrorValue;
}

