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
FINAL_IMAGE=${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MCAL/EXT_INTERRUPT/EXT_Interrupt.c MCAL/GPIO/GPIO.c MCAL/Timer/Timer.c Services/Timer_Services/Timer_Services.c main.c ECUAL/LED/LED.c ECUAL/LCD/LCD.c MCAL/GPIO/GPIO_Lcfg.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o ${OBJECTDIR}/MCAL/GPIO/GPIO.o ${OBJECTDIR}/MCAL/Timer/Timer.o ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ECUAL/LED/LED.o ${OBJECTDIR}/ECUAL/LCD/LCD.o ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d ${OBJECTDIR}/MCAL/GPIO/GPIO.o.d ${OBJECTDIR}/MCAL/Timer/Timer.o.d ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/ECUAL/LED/LED.o.d ${OBJECTDIR}/ECUAL/LCD/LCD.o.d ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o ${OBJECTDIR}/MCAL/GPIO/GPIO.o ${OBJECTDIR}/MCAL/Timer/Timer.o ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ECUAL/LED/LED.o ${OBJECTDIR}/ECUAL/LCD/LCD.o ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o

# Source Files
SOURCEFILES=MCAL/EXT_INTERRUPT/EXT_Interrupt.c MCAL/GPIO/GPIO.c MCAL/Timer/Timer.c Services/Timer_Services/Timer_Services.c main.c ECUAL/LED/LED.c ECUAL/LCD/LCD.c MCAL/GPIO/GPIO_Lcfg.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o: MCAL/EXT_INTERRUPT/EXT_Interrupt.c  .generated_files/flags/default/7daf67bc5d1676279c9ac9f2a9fdf3837ac73f2a .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/EXT_INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d" -MT "${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d" -MT ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o -o ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o MCAL/EXT_INTERRUPT/EXT_Interrupt.c 
	
${OBJECTDIR}/MCAL/GPIO/GPIO.o: MCAL/GPIO/GPIO.c  .generated_files/flags/default/e5d9b6220d85e61a02f5e99959f9832e7d50bc9b .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.o.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/GPIO/GPIO.o.d" -MT "${OBJECTDIR}/MCAL/GPIO/GPIO.o.d" -MT ${OBJECTDIR}/MCAL/GPIO/GPIO.o -o ${OBJECTDIR}/MCAL/GPIO/GPIO.o MCAL/GPIO/GPIO.c 
	
${OBJECTDIR}/MCAL/Timer/Timer.o: MCAL/Timer/Timer.c  .generated_files/flags/default/58867d60aa63e0ae1a8cc85f74562395316394f8 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/Timer" 
	@${RM} ${OBJECTDIR}/MCAL/Timer/Timer.o.d 
	@${RM} ${OBJECTDIR}/MCAL/Timer/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/Timer/Timer.o.d" -MT "${OBJECTDIR}/MCAL/Timer/Timer.o.d" -MT ${OBJECTDIR}/MCAL/Timer/Timer.o -o ${OBJECTDIR}/MCAL/Timer/Timer.o MCAL/Timer/Timer.c 
	
${OBJECTDIR}/Services/Timer_Services/Timer_Services.o: Services/Timer_Services/Timer_Services.c  .generated_files/flags/default/b2407e6469a018c404133efcf4361422e8938c0b .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/Services/Timer_Services" 
	@${RM} ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d 
	@${RM} ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d" -MT "${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d" -MT ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o -o ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o Services/Timer_Services/Timer_Services.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/d380cd2d9fa63d61e44b367b1ec9ea993f9b3adc .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/ECUAL/LED/LED.o: ECUAL/LED/LED.c  .generated_files/flags/default/fdeeef4d2881d236e4cf21964a0d259e7acecdef .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.o.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ECUAL/LED/LED.o.d" -MT "${OBJECTDIR}/ECUAL/LED/LED.o.d" -MT ${OBJECTDIR}/ECUAL/LED/LED.o -o ${OBJECTDIR}/ECUAL/LED/LED.o ECUAL/LED/LED.c 
	
${OBJECTDIR}/ECUAL/LCD/LCD.o: ECUAL/LCD/LCD.c  .generated_files/flags/default/574c9168d84dc550d01a1326bf5bec0f49b3f75d .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/ECUAL/LCD" 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/LCD.o.d 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ECUAL/LCD/LCD.o.d" -MT "${OBJECTDIR}/ECUAL/LCD/LCD.o.d" -MT ${OBJECTDIR}/ECUAL/LCD/LCD.o -o ${OBJECTDIR}/ECUAL/LCD/LCD.o ECUAL/LCD/LCD.c 
	
${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o: MCAL/GPIO/GPIO_Lcfg.c  .generated_files/flags/default/e7aba48485938251134a79f90b9c396eb5e7077c .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d" -MT "${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d" -MT ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o -o ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o MCAL/GPIO/GPIO_Lcfg.c 
	
else
${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o: MCAL/EXT_INTERRUPT/EXT_Interrupt.c  .generated_files/flags/default/c720a7dc344d5d44febc67f36fc7d5136e3c6156 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/EXT_INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d" -MT "${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o.d" -MT ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o -o ${OBJECTDIR}/MCAL/EXT_INTERRUPT/EXT_Interrupt.o MCAL/EXT_INTERRUPT/EXT_Interrupt.c 
	
${OBJECTDIR}/MCAL/GPIO/GPIO.o: MCAL/GPIO/GPIO.c  .generated_files/flags/default/147c14fd021c45778b88c3c122c22d26cfc357d8 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.o.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/GPIO/GPIO.o.d" -MT "${OBJECTDIR}/MCAL/GPIO/GPIO.o.d" -MT ${OBJECTDIR}/MCAL/GPIO/GPIO.o -o ${OBJECTDIR}/MCAL/GPIO/GPIO.o MCAL/GPIO/GPIO.c 
	
${OBJECTDIR}/MCAL/Timer/Timer.o: MCAL/Timer/Timer.c  .generated_files/flags/default/aa3c3e0ddbb1ff1459802f826f7bb8e99895ceb3 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/Timer" 
	@${RM} ${OBJECTDIR}/MCAL/Timer/Timer.o.d 
	@${RM} ${OBJECTDIR}/MCAL/Timer/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/Timer/Timer.o.d" -MT "${OBJECTDIR}/MCAL/Timer/Timer.o.d" -MT ${OBJECTDIR}/MCAL/Timer/Timer.o -o ${OBJECTDIR}/MCAL/Timer/Timer.o MCAL/Timer/Timer.c 
	
${OBJECTDIR}/Services/Timer_Services/Timer_Services.o: Services/Timer_Services/Timer_Services.c  .generated_files/flags/default/378593918bfc0d9895b4325afaed145df5d18aa3 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/Services/Timer_Services" 
	@${RM} ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d 
	@${RM} ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d" -MT "${OBJECTDIR}/Services/Timer_Services/Timer_Services.o.d" -MT ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o -o ${OBJECTDIR}/Services/Timer_Services/Timer_Services.o Services/Timer_Services/Timer_Services.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/3378bbe4d64869d0c3da6808826bda6c5712c578 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/ECUAL/LED/LED.o: ECUAL/LED/LED.c  .generated_files/flags/default/86fccb9aa6fcb00788d461d96da93bd7f69c3b05 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.o.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ECUAL/LED/LED.o.d" -MT "${OBJECTDIR}/ECUAL/LED/LED.o.d" -MT ${OBJECTDIR}/ECUAL/LED/LED.o -o ${OBJECTDIR}/ECUAL/LED/LED.o ECUAL/LED/LED.c 
	
${OBJECTDIR}/ECUAL/LCD/LCD.o: ECUAL/LCD/LCD.c  .generated_files/flags/default/f415fa2acc712157da4b9b6c917da2008f72d48f .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/ECUAL/LCD" 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/LCD.o.d 
	@${RM} ${OBJECTDIR}/ECUAL/LCD/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ECUAL/LCD/LCD.o.d" -MT "${OBJECTDIR}/ECUAL/LCD/LCD.o.d" -MT ${OBJECTDIR}/ECUAL/LCD/LCD.o -o ${OBJECTDIR}/ECUAL/LCD/LCD.o ECUAL/LCD/LCD.c 
	
${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o: MCAL/GPIO/GPIO_Lcfg.c  .generated_files/flags/default/6f86616aca7d34effbc8d48d43dfcaf1e3115625 .generated_files/flags/default/2ebadb7499da65fc4c278afdfab593bf9d1d26cd
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d" -MT "${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o.d" -MT ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o -o ${OBJECTDIR}/MCAL/GPIO/GPIO_Lcfg.o MCAL/GPIO/GPIO_Lcfg.c 
	
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
${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/UltraSonic.X.${IMAGE_TYPE}.hex"
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
