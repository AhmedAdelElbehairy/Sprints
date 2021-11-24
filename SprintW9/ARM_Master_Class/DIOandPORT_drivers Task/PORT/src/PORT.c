/*
 * File Name: PORT.c
 * 
 */ 
 
#include "PORT.h"
#define LOCK_VALUE      0x4C4F434BU
#define ANALOG_MODE 20
volatile uint8_t number_of_elements_of_pin_configuration_array = 0;

static volatile uint32_t *DirectionRegisters[6] ={
	((volatile uint32_t*)0x40004400UL),
	((volatile uint32_t*)0x40005400UL),
	((volatile uint32_t*)0x40006400UL),
	((volatile uint32_t*)0x40007400UL),
	((volatile uint32_t*)0x40024400UL),
	((volatile uint32_t*)0x40025400UL),
};
static volatile uint32_t *InterruptSenseRegisters[6] ={
	((volatile uint32_t*)0x40004404UL),
	((volatile uint32_t*)0x40005404UL),
	((volatile uint32_t*)0x40006404UL),
	((volatile uint32_t*)0x40007404UL),
	((volatile uint32_t*)0x40024404UL),
	((volatile uint32_t*)0x40025404UL),
};
static volatile uint32_t *InterruptBothEdgesRegisters[6] ={
	((volatile uint32_t*)0x40004408UL),
	((volatile uint32_t*)0x40005408UL),
	((volatile uint32_t*)0x40006408UL),
	((volatile uint32_t*)0x40007408UL),
	((volatile uint32_t*)0x40024408UL),
	((volatile uint32_t*)0x40025408UL),
};
static volatile uint32_t *InterruptClearRegisters[6] ={
	((volatile uint32_t*)0x4000441CUL),
	((volatile uint32_t*)0x4000541CUL),
	((volatile uint32_t*)0x4000641CUL),
	((volatile uint32_t*)0x4000741CUL),
	((volatile uint32_t*)0x4002441CUL),
	((volatile uint32_t*)0x4002541CUL),
};
static volatile uint32_t *InterrupteventRegisters[6] ={
	((volatile uint32_t*)0x4000440CUL),
	((volatile uint32_t*)0x4000540CUL),
	((volatile uint32_t*)0x4000640CUL),
	((volatile uint32_t*)0x4000740CUL),
	((volatile uint32_t*)0x4002440CUL),
	((volatile uint32_t*)0x4002540CUL),
};
static volatile uint32_t *InterruptMaskRegisters[6] ={
	((volatile uint32_t*)0x40004410UL),
	((volatile uint32_t*)0x40005410UL),
	((volatile uint32_t*)0x40006410UL),
	((volatile uint32_t*)0x40007410UL),
	((volatile uint32_t*)0x40024410UL),
	((volatile uint32_t*)0x40025410UL),
};
static volatile uint32_t *AlternateFunctionRegisters[6] ={
	((volatile uint32_t*)0x40004420UL),
	((volatile uint32_t*)0x40005420UL),
	((volatile uint32_t*)0x40006420UL),
	((volatile uint32_t*)0x40007420UL),
	((volatile uint32_t*)0x40024420UL),
	((volatile uint32_t*)0x40025420UL),
};
static volatile uint32_t *TwomAmperRegisters[6] ={
	((volatile uint32_t*)0x40004500UL),
	((volatile uint32_t*)0x40005500UL),
	((volatile uint32_t*)0x40006500UL),
	((volatile uint32_t*)0x40007500UL),
	((volatile uint32_t*)0x40024500UL),
	((volatile uint32_t*)0x40025500UL),
};
static volatile uint32_t *FourmAmperRegisters[6] ={
	((volatile uint32_t*)0x40004504UL),
	((volatile uint32_t*)0x40005504UL),
	((volatile uint32_t*)0x40006504UL),
	((volatile uint32_t*)0x40007504UL),
	((volatile uint32_t*)0x40024504UL),
	((volatile uint32_t*)0x40025504UL),
};
static volatile uint32_t *EightmAmperRegisters[6] ={
	((volatile uint32_t*)0x40004508UL),
	((volatile uint32_t*)0x40005508UL),
	((volatile uint32_t*)0x40006508UL),
	((volatile uint32_t*)0x40007508UL),
	((volatile uint32_t*)0x40024508UL),
	((volatile uint32_t*)0x40025508UL),
};
static volatile uint32_t *OpenDrainRegisters[6] ={
	((volatile uint32_t*)0x4000450CUL),
	((volatile uint32_t*)0x4000550CUL),
	((volatile uint32_t*)0x4000650CUL),
	((volatile uint32_t*)0x4000750CUL),
	((volatile uint32_t*)0x4002450CUL),
	((volatile uint32_t*)0x4002550CUL),
};
static volatile uint32_t *PullUpRegisters[6] ={
	((volatile uint32_t*)0x40004510UL),
	((volatile uint32_t*)0x40005510UL),
	((volatile uint32_t*)0x40006510UL),
	((volatile uint32_t*)0x40007510UL),
	((volatile uint32_t*)0x40024510UL),
	((volatile uint32_t*)0x40025510UL),
};
static volatile uint32_t *PullDownRegisters[6] ={
	((volatile uint32_t*)0x40004514UL),
	((volatile uint32_t*)0x40005514UL),
	((volatile uint32_t*)0x40006514UL),
	((volatile uint32_t*)0x40007514UL),
	((volatile uint32_t*)0x40024514UL),
	((volatile uint32_t*)0x40025514UL),
};
static volatile uint32_t *DigitalEnRegisters[6] ={
	((volatile uint32_t*)0x4000451CUL),
	((volatile uint32_t*)0x4000551CUL),
	((volatile uint32_t*)0x4000651CUL),
	((volatile uint32_t*)0x4000751CUL),
	((volatile uint32_t*)0x4002451CUL),
	((volatile uint32_t*)0x4002551CUL),
};
static volatile uint32_t *LockRegisters[6] ={
	((volatile uint32_t*)0x40004520UL),
	((volatile uint32_t*)0x40005520UL),
	((volatile uint32_t*)0x40006520UL),
	((volatile uint32_t*)0x40007520UL),
	((volatile uint32_t*)0x40024520UL),
	((volatile uint32_t*)0x40025520UL),
};
static volatile uint32_t *CommitRegisters[6] ={
	((volatile uint32_t*)0x40004524UL),
	((volatile uint32_t*)0x40005524UL),
	((volatile uint32_t*)0x40006524UL),
	((volatile uint32_t*)0x40007524UL),
	((volatile uint32_t*)0x40024524UL),
	((volatile uint32_t*)0x40025524UL),
};
static volatile uint32_t *AnalogModeRegisters[6] ={
	((volatile uint32_t*)0x40004528UL),
	((volatile uint32_t*)0x40005528UL),
	((volatile uint32_t*)0x40006528UL),
	((volatile uint32_t*)0x40007528UL),
	((volatile uint32_t*)0x40024528UL),
	((volatile uint32_t*)0x40025528UL),
};
static volatile uint32_t *PortControlRegisters[6] ={
	((volatile uint32_t*)0x4000452CUL),
	((volatile uint32_t*)0x4000552CUL),
	((volatile uint32_t*)0x4000652CUL),
	((volatile uint32_t*)0x4000752CUL),
	((volatile uint32_t*)0x4002452CUL),
	((volatile uint32_t*)0x4002552CUL),
};
/**/
void PORT_Init(PORT_CFG_t* config_arr)
{
	int iterator = 0;
	for (iterator = 0; iterator < number_of_elements_of_pin_configuration_array; iterator++)
	{
		/*unlocking for changes*/
		*(LockRegisters[config_arr[iterator].PIN/8]) = LOCK_VALUE;
		SET_BIT_ATOMIC(*(CommitRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
		/*configuring the pin direction*/
		switch(config_arr[iterator].PIN_DIRECTION)
		{
			case PORT_PIN_IN:
				CLEAR_BIT_ATOMIC(*(DirectionRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
				break;
			case PORT_PIN_OUT:
				SET_BIT_ATOMIC(*(DirectionRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
				break;
			case PORT_PIN_INVALID_DIR:
				break;
		}
		/*Configure the drive current strength*/
		switch(config_arr[iterator].PIN_CURRENT)
		{
			case PIN_2mA:
				SET_BIT_ATOMIC(*(TwomAmperRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			break;
			case PIN_4mA:
				SET_BIT_ATOMIC(*(FourmAmperRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			break;
			case PIN_8mA:
				SET_BIT_ATOMIC(*(EightmAmperRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			break;
			case PIN_INVALID_CURRENT:
				break;
		}
		/*configuring the pin internal connection*/
		switch(config_arr[iterator].PIN_INTERNAL_CONNECTION)
		{
			case OPEN_DRAIN:
				SET_BIT_ATOMIC(*(OpenDrainRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
				break;
			case PULL_UP:
				SET_BIT_ATOMIC(*(PullUpRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
				break;
			case PULL_DOWN:
				SET_BIT_ATOMIC(*(PullDownRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
				break;
			case PIN_INVALID_CONNECTION:
				break;
		}
		/*configuring the pin mode*/
		if(config_arr[iterator].PIN_MODE >= 1 && config_arr[iterator].PIN_MODE <= 14)/*Alternate digital function*/
		{
			SET_BIT_ATOMIC(*(AlternateFunctionRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			/*set the alternate function*/
			*PortControlRegisters[config_arr[iterator].PIN/8] &= ~(0xFU<<((config_arr[iterator].PIN%8)*4));
			*PortControlRegisters[config_arr[iterator].PIN/8] |= ((uint32_t)(config_arr[iterator].PIN_MODE)<<((config_arr[iterator].PIN%8)*4));
			/*digital enable*/
			SET_BIT_ATOMIC(*(DigitalEnRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			
		}
		else if(config_arr[iterator].PIN_MODE == ANALOG_MODE) /*Analog Mode*/
		{
			/*configuring the alternate function*/
			SET_BIT_ATOMIC(*(AlternateFunctionRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			/*enable gpio pins to their analog function*/
			SET_BIT_ATOMIC(*(AnalogModeRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
		}
		else/*GPIO Mode and EXTI*/
		{
			/*configuring the alternate function to non*/
			CLEAR_BIT_ATOMIC(*(AlternateFunctionRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
			/*switch if certain external interrupt mode is selected*/
			switch(config_arr[iterator].PIN_MODE)
			{
				case PIN_GPIO_MODE_EXT_HIGH_LEVELS:
					CLEAR_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptSenseRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterrupteventRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					break;
				case PIN_GPIO_MODE_EXT_LOW_LEVELS:
					CLEAR_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptSenseRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					CLEAR_BIT_ATOMIC(*(InterrupteventRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					break;
				case PIN_GPIO_MODE_EXT_RISING_EDGES:
					CLEAR_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					CLEAR_BIT_ATOMIC(*(InterruptSenseRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterrupteventRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptClearRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					break;
				case PIN_GPIO_MODE_EXT_FALLING_EDGES:
					CLEAR_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					CLEAR_BIT_ATOMIC(*(InterruptSenseRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					CLEAR_BIT_ATOMIC(*(InterrupteventRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptClearRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					break;
				case PIN_GPIO_MODE_EXT_BOTH_EDGES:
					CLEAR_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					CLEAR_BIT_ATOMIC(*(InterruptSenseRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptBothEdgesRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptClearRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					SET_BIT_ATOMIC(*(InterruptMaskRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
					break;
				default:
					break;				
			}
			/*digital enable*/
			SET_BIT_ATOMIC(*(DigitalEnRegisters[config_arr[iterator].PIN/8]), (config_arr[iterator].PIN%8));
		}
		/*optionally we can lock the pin_configuration*/
	}
}

