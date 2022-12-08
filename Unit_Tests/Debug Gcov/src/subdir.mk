################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp 

CPP_DEPS += \
./src/Test.d 

OBJS += \
./src/Test.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\rafag\OneDrive - Universidad de Córdoba\Escritorio\ProyectoIS\Eclipse\pruebas_Unitarias\cute" -I"C:\Users\rafag\OneDrive - Universidad de Córdoba\Escritorio\ProyectoIS\Eclipse\pruebas_Unitarias\boost" -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Test.d ./src/Test.o

.PHONY: clean-src

