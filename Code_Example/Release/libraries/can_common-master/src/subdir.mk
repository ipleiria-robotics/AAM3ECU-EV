################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\eclipse\arduinoPlugin\libraries\can_common-master\1.1.0\src\can_common.cpp 

LINK_OBJ += \
.\libraries\can_common-master\src\can_common.cpp.o 

CPP_DEPS += \
.\libraries\can_common-master\src\can_common.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\can_common-master\src\can_common.cpp.o: C:\eclipse\arduinoPlugin\libraries\can_common-master\1.1.0\src\can_common.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10802 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Due\"" "-IC:\eclipse\/arduinoPlugin/packages/arduino/hardware/sam/1.6.12/system/libsam" "-IC:\eclipse\/arduinoPlugin/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-IC:\eclipse\/arduinoPlugin/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/"   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\sam\1.6.12\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\sam\1.6.12\variants\arduino_due_x" -I"C:\eclipse\arduinoPlugin\libraries\due_can-master\1.1.0\src" -I"C:\eclipse\arduinoPlugin\libraries\can_common-master\1.1.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


