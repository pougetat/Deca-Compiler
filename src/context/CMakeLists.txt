cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set(SRCS
	AbstractDefinition.cpp
	AbstractType.cpp
	AbstractTypeNature.cpp
	BooleanType.cpp
	ClassTypeNature.cpp
	ContextChecker.cpp
	EnvironmentExp.cpp
	EnvironmentType.cpp
	ExpDefinition.cpp
	FloatType.cpp
	IntType.cpp
	NullType.cpp
	StringType.cpp
	TypeDefinition.cpp
	TypeTypeNature.cpp
	VoidType.cpp
	)
	
set(HEADERS
	AbstractDefinition.h
	AbstractType.h
	AbstractTypeNature.h	
	BooleanType.h
	ClassTypeNature.h
	ContextChecker.h
	EnvironmentExp.h
	EnvironmentType.h
	ExpDefinition.h
	FloatType.h
	IntType.h
	NullType.h
	StringType.h
	TypeDefinition.h
	TypeTypeNature.h
	VoidType.h
	)

add_library(context ${SRCS} ${HEADERS})