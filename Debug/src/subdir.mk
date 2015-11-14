################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ADUASCII.cpp \
../src/ADURTU.cpp \
../src/ADUTCP.cpp \
../src/ModbusSerialTransaction.cpp \
../src/PDU.cpp \
../src/ReadHoldingRegistersRequest.cpp \
../src/ReadHoldingRegistersResponse.cpp \
../src/ReadInputRegistersRequest.cpp \
../src/ReadInputRegistersResponse.cpp \
../src/Request.cpp \
../src/Response.cpp \
../src/SerialConnection.cpp \
../src/SerialParameters.cpp \
../src/mbcrc.cpp 

OBJS += \
./src/ADUASCII.o \
./src/ADURTU.o \
./src/ADUTCP.o \
./src/ModbusSerialTransaction.o \
./src/PDU.o \
./src/ReadHoldingRegistersRequest.o \
./src/ReadHoldingRegistersResponse.o \
./src/ReadInputRegistersRequest.o \
./src/ReadInputRegistersResponse.o \
./src/Request.o \
./src/Response.o \
./src/SerialConnection.o \
./src/SerialParameters.o \
./src/mbcrc.o 

CPP_DEPS += \
./src/ADUASCII.d \
./src/ADURTU.d \
./src/ADUTCP.d \
./src/ModbusSerialTransaction.d \
./src/PDU.d \
./src/ReadHoldingRegistersRequest.d \
./src/ReadHoldingRegistersResponse.d \
./src/ReadInputRegistersRequest.d \
./src/ReadInputRegistersResponse.d \
./src/Request.d \
./src/Response.d \
./src/SerialConnection.d \
./src/SerialParameters.d \
./src/mbcrc.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


