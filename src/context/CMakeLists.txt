cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set(SRCS
	AbstractDefinition.cpp
	AbstractExpNature.cpp
	AbstractType.cpp
	AbstractTypeNature.cpp
	BooleanType.cpp
	ClassType.cpp
	ClassTypeNature.cpp
	ContextChecker.cpp
	EnvironmentExp.cpp
	EnvironmentType.cpp
	ExpDefinition.cpp
	FieldExpNature.cpp
	FloatType.cpp
	IntType.cpp
	MethodExpNature.cpp
	NullType.cpp
	ParamExpNature.cpp
	StringType.cpp
	TypeDefinition.cpp
	TypeTypeNature.cpp
	VarExpNature.cpp
	VoidType.cpp
	)
	
set(HEADERS
	AbstractDefinition.h
	AbstractExpNature.h
	AbstractType.h
	AbstractTypeNature.h	
	BooleanType.h
	ClassType.h
	ClassTypeNature.h
	ContextChecker.h
	EnvironmentExp.h
	EnvironmentType.h
	ExpDefinition.h
	FieldExpNature.h
	FloatType.h
	IntType.h
	MethodExpNature.h
	NullType.h
	ParamExpNature.h
	StringType.h
	TypeDefinition.h
	TypeTypeNature.h
	VarExpNature.h
	VoidType.h
	)

add_library(context ${SRCS} ${HEADERS})