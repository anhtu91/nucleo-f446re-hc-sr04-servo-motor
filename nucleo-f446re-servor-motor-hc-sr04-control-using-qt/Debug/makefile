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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.list \

OBJCOPY_BIN += \
nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.bin \


# All Target
all: nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.elf secondary-outputs

# Tool invocations
nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.elf: $(OBJS) $(USER_OBJS) /home/atn/STM32CubeIDE/workspace_1.3.0/nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt/STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/atn/STM32CubeIDE/workspace_1.3.0/nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt/STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.list"
	@echo 'Finished building: $@'
	@echo ' '

nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "nucleo-f446re-servor-motor-hc-sr04-tmp102-control-using-qt.bin"
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
