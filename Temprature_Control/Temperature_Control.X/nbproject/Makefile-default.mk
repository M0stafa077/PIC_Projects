#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=APP/application.c ECUAL/BUZZER/buzzer.c ECUAL/DC_Motor/dc_motor.c ECUAL/LCD/lcd.c ECUAL/LED/LED.c ECUAL/ecu_layer_init.c MCAL/ADC/hal_adc.c MCAL/GPIO/gpio.c MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c MCAL/Interrupt/INT_interrupts/MCAL_INTI.c MCAL/Interrupt/MCAL_interrupt_manager.c MCAL/mcal_layer_init.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/APP/application.p1 ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 ${OBJECTDIR}/ECUAL/LCD/lcd.p1 ${OBJECTDIR}/ECUAL/LED/LED.p1 ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 ${OBJECTDIR}/MCAL/mcal_layer_init.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/APP/application.p1.d ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d ${OBJECTDIR}/ECUAL/LED/LED.p1.d ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/APP/application.p1 ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 ${OBJECTDIR}/ECUAL/LCD/lcd.p1 ${OBJECTDIR}/ECUAL/LED/LED.p1 ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 ${OBJECTDIR}/MCAL/mcal_layer_init.p1

# Source Files
SOURCEFILES=APP/application.c ECUAL/BUZZER/buzzer.c ECUAL/DC_Motor/dc_motor.c ECUAL/LCD/lcd.c ECUAL/LED/LED.c ECUAL/ecu_layer_init.c MCAL/ADC/hal_adc.c MCAL/GPIO/gpio.c MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c MCAL/Interrupt/INT_interrupts/MCAL_INTI.c MCAL/Interrupt/MCAL_interrupt_manager.c MCAL/mcal_layer_init.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/APP/application.p1: APP/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP" 
	@${RM} ${OBJECTDIR}/APP/application.p1.d 
	@${RM} ${OBJECTDIR}/APP/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP/application.p1 APP/application.c 
	@-${MV} ${OBJECTDIR}/APP/application.d ${OBJECTDIR}/APP/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1: ECUAL/BUZZER/buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/BUZZER" 
	@${RM} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 ECUAL/BUZZER/buzzer.c 
	@-${MV} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.d ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1: ECUAL/DC_Motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 ECUAL/DC_Motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.d ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LCD/lcd.p1: ECUAL/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LCD" 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LCD/lcd.p1 ECUAL/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LCD/lcd.d ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/LED.p1: ECUAL/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/LED.p1 ECUAL/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/LED.d ${OBJECTDIR}/ECUAL/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/ecu_layer_init.p1: ECUAL/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL" 
	@${RM} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 ECUAL/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECUAL/ecu_layer_init.d ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/hal_adc.p1: MCAL/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 MCAL/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/hal_adc.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1: MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.d ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1: MCAL/Interrupt/INT_interrupts/MCAL_INTI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt/INT_interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 MCAL/Interrupt/INT_interrupts/MCAL_INTI.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.d ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1: MCAL/Interrupt/MCAL_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 MCAL/Interrupt/MCAL_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/mcal_layer_init.p1: MCAL/mcal_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/mcal_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/mcal_layer_init.p1 MCAL/mcal_layer_init.c 
	@-${MV} ${OBJECTDIR}/MCAL/mcal_layer_init.d ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/APP/application.p1: APP/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP" 
	@${RM} ${OBJECTDIR}/APP/application.p1.d 
	@${RM} ${OBJECTDIR}/APP/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP/application.p1 APP/application.c 
	@-${MV} ${OBJECTDIR}/APP/application.d ${OBJECTDIR}/APP/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1: ECUAL/BUZZER/buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/BUZZER" 
	@${RM} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1 ECUAL/BUZZER/buzzer.c 
	@-${MV} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.d ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/BUZZER/buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1: ECUAL/DC_Motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1 ECUAL/DC_Motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.d ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LCD/lcd.p1: ECUAL/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LCD" 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LCD/lcd.p1 ECUAL/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LCD/lcd.d ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/LED.p1: ECUAL/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/LED.p1 ECUAL/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/LED.d ${OBJECTDIR}/ECUAL/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/ecu_layer_init.p1: ECUAL/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL" 
	@${RM} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/ecu_layer_init.p1 ECUAL/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECUAL/ecu_layer_init.d ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/hal_adc.p1: MCAL/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 MCAL/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/hal_adc.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1: MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1 MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.d ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/EXT_interrupts/MCAL_EXTI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1: MCAL/Interrupt/INT_interrupts/MCAL_INTI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt/INT_interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1 MCAL/Interrupt/INT_interrupts/MCAL_INTI.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.d ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_interrupts/MCAL_INTI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1: MCAL/Interrupt/MCAL_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1 MCAL/Interrupt/MCAL_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/MCAL_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/mcal_layer_init.p1: MCAL/mcal_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/mcal_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/mcal_layer_init.p1 MCAL/mcal_layer_init.c 
	@-${MV} ${OBJECTDIR}/MCAL/mcal_layer_init.d ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/mcal_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Temperature_Control.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
