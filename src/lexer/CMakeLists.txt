cmake_minimum_required(VERSION 3.0)

project(lexer)

set(SRCS
	lexer.cpp
	)
	
set(HEADERS
	lexer.h
	)

add_library(lexer ${SRCS} ${HEADERS})
