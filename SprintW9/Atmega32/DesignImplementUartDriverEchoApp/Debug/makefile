################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/DIO/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DesignImplementUartDriverEchoApp.lss \

FLASH_IMAGE += \
DesignImplementUartDriverEchoApp.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DesignImplementUartDriverEchoApp.elf secondary-outputs

# Tool invocations
DesignImplementUartDriverEchoApp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DesignImplementUartDriverEchoApp.map -mmcu=atmega32 -o "DesignImplementUartDriverEchoApp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DesignImplementUartDriverEchoApp.lss: DesignImplementUartDriverEchoApp.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DesignImplementUartDriverEchoApp.elf  >"DesignImplementUartDriverEchoApp.lss"
	@echo 'Finished building: $@'
	@echo ' '

DesignImplementUartDriverEchoApp.hex: DesignImplementUartDriverEchoApp.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DesignImplementUartDriverEchoApp.elf  "DesignImplementUartDriverEchoApp.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DesignImplementUartDriverEchoApp.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DesignImplementUartDriverEchoApp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DesignImplementUartDriverEchoApp.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
