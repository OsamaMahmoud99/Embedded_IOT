################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
Mqtt_App.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Mqtt_App.list \

OBJCOPY_BIN += \
Mqtt_App.bin \


# All Target
all: Mqtt_App.elf secondary-outputs

# Tool invocations
Mqtt_App.elf: $(OBJS) $(USER_OBJS) F:\OSAMAA\Embedded\ System\20-NTI\ARM2022\MQTT\Mqtt_App\STM32F401VETX_FLASH.ld
	arm-none-eabi-gcc -o "Mqtt_App.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\OSAMAA\Embedded System\20-NTI\ARM2022\MQTT\Mqtt_App\STM32F401VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Mqtt_App.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Mqtt_App.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Mqtt_App.list"
	@echo 'Finished building: $@'
	@echo ' '

Mqtt_App.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Mqtt_App.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
