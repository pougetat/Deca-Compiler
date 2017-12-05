cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(AST)

set(SRCS
	SyntaxParser.cpp
	)
	
set(HEADERS
	SyntaxParser.h
	)

add_library(parser ${SRCS} ${HEADERS})
