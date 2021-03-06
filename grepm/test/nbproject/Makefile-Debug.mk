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
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/TestCircBuffer.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/MultiGrep.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/Grep.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/CircBuffer.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/LineNumber.o \
	${OBJECTDIR}/src/TestChain.o \
	${OBJECTDIR}/src/TestMultiGrep.o \
	${OBJECTDIR}/src/TestLineNumber.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/TestBoostGrep.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/BoostGrep.o

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
LDLIBSOPTIONS=-lgtest_main -lboost_regex

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/test

dist/Debug/GNU-Linux-x86/test: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/TestCircBuffer.o: nbproject/Makefile-${CND_CONF}.mk src/TestCircBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/TestCircBuffer.o src/TestCircBuffer.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/MultiGrep.o: nbproject/Makefile-${CND_CONF}.mk ../src/MultiGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/MultiGrep.o ../src/MultiGrep.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/Grep.o: nbproject/Makefile-${CND_CONF}.mk ../src/Grep.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/Grep.o ../src/Grep.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/CircBuffer.o: nbproject/Makefile-${CND_CONF}.mk ../src/CircBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/CircBuffer.o ../src/CircBuffer.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/LineNumber.o: nbproject/Makefile-${CND_CONF}.mk ../src/LineNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/LineNumber.o ../src/LineNumber.cpp

${OBJECTDIR}/src/TestChain.o: nbproject/Makefile-${CND_CONF}.mk src/TestChain.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/TestChain.o src/TestChain.cpp

${OBJECTDIR}/src/TestMultiGrep.o: nbproject/Makefile-${CND_CONF}.mk src/TestMultiGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/TestMultiGrep.o src/TestMultiGrep.cpp

${OBJECTDIR}/src/TestLineNumber.o: nbproject/Makefile-${CND_CONF}.mk src/TestLineNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/TestLineNumber.o src/TestLineNumber.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/TestBoostGrep.o: nbproject/Makefile-${CND_CONF}.mk ../src/TestBoostGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/TestBoostGrep.o ../src/TestBoostGrep.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/BoostGrep.o: nbproject/Makefile-${CND_CONF}.mk ../src/BoostGrep.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src
	${RM} $@.d
	$(COMPILE.cc) -g -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/BoostGrep.o ../src/BoostGrep.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/test

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
