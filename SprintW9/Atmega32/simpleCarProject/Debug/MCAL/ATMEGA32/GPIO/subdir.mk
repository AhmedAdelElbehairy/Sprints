################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ATMEGA32/GPIO/Gpio.c 

OBJS += \
./MCAL/ATMEGA32/GPIO/Gpio.o 

C_DEPS += \
./MCAL/ATMEGA32/GPIO/Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ATMEGA32/GPIO/%.o: ../MCAL/ATMEGA32/GPIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


