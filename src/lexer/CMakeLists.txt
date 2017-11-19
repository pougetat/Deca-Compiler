cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set(SRCS
	lexer.cpp
	token.cpp
	)
	
set(HEADERS
	lexer.h
	token.h
	)

add_library(lexer ${SRCS} ${HEADERS})