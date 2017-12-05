cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set(SRCS
	ContextChecker.cpp
	)
	
set(HEADERS
	ContextChecker.h
	)

add_library(context ${SRCS} ${HEADERS})