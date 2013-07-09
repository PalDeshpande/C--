################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BasePlusCommissionEmployee.cpp \
../src/CommissionEmployee.cpp \
../src/inheritanceFrank.cpp \
../src/pensionEmployee.cpp 

OBJS += \
./src/BasePlusCommissionEmployee.o \
./src/CommissionEmployee.o \
./src/inheritanceFrank.o \
./src/pensionEmployee.o 

CPP_DEPS += \
./src/BasePlusCommissionEmployee.d \
./src/CommissionEmployee.d \
./src/inheritanceFrank.d \
./src/pensionEmployee.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


