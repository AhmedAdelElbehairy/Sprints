################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/SPI/subdir.mk
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
DesignImplementDriverForSPI_3.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: DesignImplementDriverForSPI_3.elf secondary-outputs

# Tool invocations
DesignImplementDriverForSPI_3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DesignImplementDriverForSPI_3.map -mmcu=atmega32 -o "DesignImplementDriverForSPI_3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DesignImplementDriverForSPI_3.lss: DesignImplementDriverForSPI_3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DesignImplementDriverForSPI_3.elf  >"DesignImplementDriverForSPI_3.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DesignImplementDriverForSPI_3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DesignImplementDriverForSPI_3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DesignImplementDriverForSPI_3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
