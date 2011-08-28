#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/LineNumber.o \
	${OBJECTDIR}/src/CircBuffer.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/MultiGrep.o \
	${OBJECTDIR}/src/Grep.o \
	${OBJECTDIR}/src/BoostGrep.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lboost_regex -lboost_program_options

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/grepm

dist/Release/GNU-Linux-x86/grepm: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/grepm ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/LineNumber.o: nbproject/Makefile-${CND_CONF}.mk src/LineNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/LineNumber.o src/LineNumber.cpp

${OBJECTDIR}/src/CircBuffer.o: nbproject/Makefile-${CND_CONF}.mk src/CircBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CircBuffer.o src/CircBuffer.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/MultiGrep.o: nbproject/Makefile-${CND_CONF}.mk src/MultiGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MultiGrep.o src/MultiGrep.cpp

${OBJECTDIR}/src/Grep.o: nbproject/Makefile-${CND_CONF}.mk src/Grep.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Grep.o src/Grep.cpp

${OBJECTDIR}/src/BoostGrep.o: nbproject/Makefile-${CND_CONF}.mk src/BoostGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/BoostGrep.o src/BoostGrep.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/grepm

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
