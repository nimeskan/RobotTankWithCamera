################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
F2837xD_CodeStartBranch.obj: ../F2837xD_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_CodeStartBranch.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_DefaultISR.obj: ../F2837xD_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_DefaultISR.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_GlobalVariableDefs.obj: ../F2837xD_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_GlobalVariableDefs.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_Gpio.obj: ../F2837xD_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_Gpio.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_PieCtrl.obj: ../F2837xD_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_PieCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_PieVect.obj: ../F2837xD_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_PieVect.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_SysCtrl.obj: ../F2837xD_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_SysCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_usDelay.obj: ../F2837xD_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xD_usDelay.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

f28379d_motor_control_uart.obj: ../f28379d_motor_control_uart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/common/include" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xd/headers/include" --include_path="C:/Users/a0225962/workspace_robotics/F28379D_MotorControl_uart_control/device" --include_path="C:/ti/C2000Ware_1_00_05_00_Software/driverlib/f2837xd/driverlib" --include_path="C:/ti/ccs730/ccsv7/tools/compiler/ti-cgt-c2000_16.9.4.LTS/include" --define=_FLASH --define=_LAUNCHXL_F28379D --define=DEBUG --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="f28379d_motor_control_uart.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


