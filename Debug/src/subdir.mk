################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/continent.cpp \
../src/main.cpp \
../src/map.cpp \
../src/territory.cpp 

OBJS += \
./src/continent.o \
./src/main.o \
./src/map.o \
./src/territory.o 

CPP_DEPS += \
./src/continent.d \
./src/main.d \
./src/map.d \
./src/territory.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


