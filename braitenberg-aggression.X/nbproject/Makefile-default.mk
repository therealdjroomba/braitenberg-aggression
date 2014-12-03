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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../e_init_port.c ../robot_main.c ../e_motors.c ../e_prox.c ../e_ad_conv.c ../utils.c ../braitenberg.c ../navigation.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/e_init_port.o ${OBJECTDIR}/_ext/1472/robot_main.o ${OBJECTDIR}/_ext/1472/e_motors.o ${OBJECTDIR}/_ext/1472/e_prox.o ${OBJECTDIR}/_ext/1472/e_ad_conv.o ${OBJECTDIR}/_ext/1472/utils.o ${OBJECTDIR}/_ext/1472/braitenberg.o ${OBJECTDIR}/_ext/1472/navigation.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/e_init_port.o.d ${OBJECTDIR}/_ext/1472/robot_main.o.d ${OBJECTDIR}/_ext/1472/e_motors.o.d ${OBJECTDIR}/_ext/1472/e_prox.o.d ${OBJECTDIR}/_ext/1472/e_ad_conv.o.d ${OBJECTDIR}/_ext/1472/utils.o.d ${OBJECTDIR}/_ext/1472/braitenberg.o.d ${OBJECTDIR}/_ext/1472/navigation.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/e_init_port.o ${OBJECTDIR}/_ext/1472/robot_main.o ${OBJECTDIR}/_ext/1472/e_motors.o ${OBJECTDIR}/_ext/1472/e_prox.o ${OBJECTDIR}/_ext/1472/e_ad_conv.o ${OBJECTDIR}/_ext/1472/utils.o ${OBJECTDIR}/_ext/1472/braitenberg.o ${OBJECTDIR}/_ext/1472/navigation.o

# Source Files
SOURCEFILES=../e_init_port.c ../robot_main.c ../e_motors.c ../e_prox.c ../e_ad_conv.c ../utils.c ../braitenberg.c ../navigation.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F6014A
MP_LINKER_FILE_OPTION=,--script=p30F6014A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/e_init_port.o: ../e_init_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_init_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_init_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_init_port.c  -o ${OBJECTDIR}/_ext/1472/e_init_port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_init_port.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_init_port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/robot_main.o: ../robot_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/robot_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/robot_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../robot_main.c  -o ${OBJECTDIR}/_ext/1472/robot_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/robot_main.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/robot_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_motors.o: ../e_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_motors.c  -o ${OBJECTDIR}/_ext/1472/e_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_motors.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_prox.o: ../e_prox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_prox.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_prox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_prox.c  -o ${OBJECTDIR}/_ext/1472/e_prox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_prox.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_prox.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_ad_conv.o: ../e_ad_conv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_ad_conv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_ad_conv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_ad_conv.c  -o ${OBJECTDIR}/_ext/1472/e_ad_conv.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_ad_conv.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_ad_conv.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/utils.o: ../utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utils.c  -o ${OBJECTDIR}/_ext/1472/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/utils.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/braitenberg.o: ../braitenberg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/braitenberg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/braitenberg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../braitenberg.c  -o ${OBJECTDIR}/_ext/1472/braitenberg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/braitenberg.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/braitenberg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/navigation.o: ../navigation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/navigation.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/navigation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../navigation.c  -o ${OBJECTDIR}/_ext/1472/navigation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/navigation.o.d"      -g -D__DEBUG     -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/navigation.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1472/e_init_port.o: ../e_init_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_init_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_init_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_init_port.c  -o ${OBJECTDIR}/_ext/1472/e_init_port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_init_port.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_init_port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/robot_main.o: ../robot_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/robot_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/robot_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../robot_main.c  -o ${OBJECTDIR}/_ext/1472/robot_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/robot_main.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/robot_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_motors.o: ../e_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_motors.c  -o ${OBJECTDIR}/_ext/1472/e_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_motors.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_prox.o: ../e_prox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_prox.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_prox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_prox.c  -o ${OBJECTDIR}/_ext/1472/e_prox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_prox.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_prox.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/e_ad_conv.o: ../e_ad_conv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/e_ad_conv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/e_ad_conv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../e_ad_conv.c  -o ${OBJECTDIR}/_ext/1472/e_ad_conv.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/e_ad_conv.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/e_ad_conv.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/utils.o: ../utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utils.c  -o ${OBJECTDIR}/_ext/1472/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/utils.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/braitenberg.o: ../braitenberg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/braitenberg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/braitenberg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../braitenberg.c  -o ${OBJECTDIR}/_ext/1472/braitenberg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/braitenberg.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/braitenberg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/navigation.o: ../navigation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/navigation.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/navigation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../navigation.c  -o ${OBJECTDIR}/_ext/1472/navigation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/navigation.o.d"        -g -omf=elf -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/navigation.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG   -omf=elf     -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files (x86)/Microchip/MPLAB C30/lib",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/braitenberg-aggression.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files (x86)/Microchip/MPLAB C30/lib",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/braitenberg-aggression.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/braitenberg-aggression.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
