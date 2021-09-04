#include "../../INFRASTRUCTURE/LIB/STD_TYPES.h"
#include "../../INFRASTRUCTURE/LIB/Bit_Operations.h"
#include "../DIO/DIO_DRIVER_TypeDef.h"
#include "../DIO/DIO_DRIVER.h"
#include "../DIO/DIO_DRIVER_Priv.h"

DIO_ERROR_RETVAL_t DIO_PortInit(DIO_PORT_ID_t DIO_port,
		DIO_DIRECTION_t DIO_direction) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;

	if ((DIO_port <= PORTD)
			&& (DIO_direction == PORT_INPUT || DIO_direction == PORT_OUTPUT)) {
		switch (DIO_port) {
		case PORTA:
			WRITE_REG(DDRA_Register, DIO_direction);
			break;
		case PORTB:
			WRITE_REG(DDRB_Register, DIO_direction);
			break;
		case PORTC:
			WRITE_REG(DDRC_Register, DIO_direction);
			break;
		case PORTD:
			WRITE_REG(DDRD_Register, DIO_direction);
			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_PinInit(DIO_PORT_ID_t DIO_port, DIO_PIN_ID_t DIO_pin,
		DIO_DIRECTION_t DIO_direction) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;

	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {
		if (DIO_direction == PIN_OUTPUT) {

			switch (DIO_port) {
			case PORTA:
				SET_BIT(DDRA_Register, DIO_pin);
				break;
			case PORTB:
				SET_BIT(DDRB_Register, DIO_pin);
				break;
			case PORTC:
				SET_BIT(DDRC_Register, DIO_pin);
				break;
			case PORTD:
				SET_BIT(DDRD_Register, DIO_pin);
				break;
			default:
				ErrorValue = EXIT_FAILURE;
				break;
			}
		} else if (DIO_direction == PIN_INPUT) {

			switch (DIO_port) {
			case PORTA:
				CLEAR_BIT(DDRA_Register, DIO_pin);
				break;
			case PORTB:
				CLEAR_BIT(DDRB_Register, DIO_pin);
				break;
			case PORTC:
				CLEAR_BIT(DDRC_Register, DIO_pin);
				break;
			case PORTD:
				CLEAR_BIT(DDRD_Register, DIO_pin);
				break;
			default:
				ErrorValue = EXIT_FAILURE;
				break;
			}
		}

		else {
			ErrorValue = EXIT_FAILURE;
		}
	}

	else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_PinEnablePullUp(DIO_PORT_ID_t DIO_port,
		DIO_PIN_ID_t DIO_pin) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {
		/* Check on the Required PORT Number */
		switch (DIO_port) {
		case PORTA:
			if (READ_REG(DDRA_Register) == PIN_INPUT) {
				SET_BIT(PORTA_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTB:
			if (READ_REG(DDRB_Register) == PIN_INPUT) {
				SET_BIT(PORTB_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTC:
			if (READ_REG(DDRC_Register) == PIN_INPUT) {
				SET_BIT(PORTC_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTD:
			if (READ_REG(DDRD_Register) == PIN_INPUT) {
				SET_BIT(PORTD_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_SetPortVal(DIO_PORT_ID_t DIO_port, Byte value) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD)) {
		switch (DIO_port) {
		case PORTA:

			MODIFY_REG(PORTA_Register, value, value);

			break;
		case PORTB:

			MODIFY_REG(PORTB_Register, value, value);

			break;
		case PORTC:

			MODIFY_REG(PORTC_Register, value, value);

			break;
		case PORTD:

			MODIFY_REG(PORTD_Register, value, value);

			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_ClrPortVal(DIO_PORT_ID_t DIO_port, Byte value) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD)) {
		switch (DIO_port) {
		case PORTA:

			MODIFY_REG(PORTA_Register, value, ~value);

			break;
		case PORTB:

			MODIFY_REG(PORTB_Register, value, ~value);

			break;
		case PORTC:

			MODIFY_REG(PORTC_Register, value, ~value);

			break;
		case PORTD:

			MODIFY_REG(PORTD_Register, value, ~value);

			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_SetPinVal(DIO_PORT_ID_t DIO_port, DIO_PIN_ID_t DIO_pin,
		Byte value) {

	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {
		if (value == PIN_HIGH) {

			switch (DIO_port) {
			case PORTA:
				if (READ_BIT(DDRA_Register, DIO_pin) == PIN_OUTPUT) {
					SET_BIT(PORTA_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTB:
				if (READ_BIT(DDRB_Register, DIO_pin) == PIN_OUTPUT) {
					SET_BIT(PORTB_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTC:
				if (READ_BIT(DDRC_Register, DIO_pin) == PIN_OUTPUT) {
					SET_BIT(PORTC_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTD:
				if (READ_BIT(DDRD_Register, DIO_pin) == PIN_OUTPUT) {
					SET_BIT(PORTD_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			default:
				ErrorValue = EXIT_FAILURE;
				break;
			}
		} else if (value == PIN_LOW) {

			switch (DIO_port) {
			case PORTA:
				if (READ_BIT(DDRA_Register, DIO_pin) == PIN_OUTPUT) {
					CLEAR_BIT(PORTA_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTB:
				if (READ_BIT(DDRB_Register, DIO_pin) == PIN_OUTPUT) {
					CLEAR_BIT(PORTB_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTC:
				if (READ_BIT(DDRC_Register, DIO_pin) == PIN_OUTPUT) {
					CLEAR_BIT(PORTC_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			case PORTD:
				if (READ_BIT(DDRD_Register, DIO_pin) == PIN_OUTPUT) {
					CLEAR_BIT(PORTD_Register, DIO_pin);
				} else {
					ErrorValue = EXIT_FAILURE;
				}
				break;
			default:
				ErrorValue = EXIT_FAILURE;
				break;
			}
		} else {
			ErrorValue = EXIT_FAILURE;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

Byte DIO_GetPortVal(DIO_PORT_ID_t DIO_port) {
	Byte RETVAL = EXIT_FAILURE;
	if ((DIO_port <= PORTD)) {
		/* Check on the Required PORT Number */
		switch (DIO_port) {
		case PORTA:
			RETVAL = READ_REG(PINA_Register);
			break;
		case PORTB:
			RETVAL = READ_REG(PINB_Register);
			break;
		case PORTC:
			RETVAL = READ_REG(PINC_Register);
			break;
		case PORTD:
			RETVAL = READ_REG(PIND_Register);
			break;
		default:
			RETVAL = EXIT_FAILURE;
			break;
		}
	} else {
		RETVAL = EXIT_FAILURE;
	}
	return RETVAL;
}

Byte DIO_GetPinVal(DIO_PORT_ID_t DIO_port, DIO_PIN_ID_t DIO_pin) {

	Byte RETVAL = EXIT_FAILURE;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {

		switch (DIO_port) {
		case PORTA:
			RETVAL = READ_BIT(PINA_Register, DIO_pin);
			break;
		case PORTB:
			RETVAL = READ_BIT(PINB_Register, DIO_pin);
			break;
		case PORTC:
			RETVAL = READ_BIT(PINC_Register, DIO_pin);
			break;
		case PORTD:
			RETVAL = READ_BIT(PIND_Register, DIO_pin);
			break;
		}
	} else {
		RETVAL = EXIT_FAILURE;
	}

	return RETVAL;
}

DIO_ERROR_RETVAL_t DIO_TogPortVal(DIO_PORT_ID_t DIO_port, Byte value) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD)) {
		switch (DIO_port) {
		case PORTA:
			if (READ_REG(DDRA_Register) == PORT_OUTPUT) {
				TOG_REG(PORTA_Register, value);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTB:
			if (READ_REG(DDRB_Register) == PORT_OUTPUT) {
				TOG_REG(PORTB_Register, value);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTC:
			if (READ_REG(DDRC_Register) == PORT_OUTPUT) {
				TOG_REG(PORTC_Register, value);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTD:
			if (READ_REG(DDRD_Register) == PORT_OUTPUT) {
				TOG_REG(PORTD_Register, value);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

DIO_ERROR_RETVAL_t DIO_TogPinVal(DIO_PORT_ID_t DIO_port, DIO_PIN_ID_t DIO_pin) {
	DIO_ERROR_RETVAL_t ErrorValue = EXIT_SUCCESFUL;
	if ((DIO_port <= PORTD) && (DIO_pin <= PIN7)) {
		switch (DIO_port) {
		case PORTA:
			if (READ_BIT(DDRA_Register, DIO_pin) == PIN_OUTPUT) {
				TOG_BIT(PORTA_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTB:
			if (READ_BIT(DDRB_Register, DIO_pin) == PIN_OUTPUT) {
				TOG_BIT(PORTB_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTC:
			if (READ_BIT(DDRC_Register, DIO_pin) == PIN_OUTPUT) {
				TOG_BIT(PORTC_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		case PORTD:
			if (READ_BIT(DDRD_Register, DIO_pin) == PIN_OUTPUT) {
				TOG_BIT(PORTD_Register, DIO_pin);
			} else {
				ErrorValue = EXIT_FAILURE;
			}
			break;
		default:
			ErrorValue = EXIT_FAILURE;
			break;
		}
	} else {
		ErrorValue = EXIT_FAILURE;
	}
	return ErrorValue;
}

