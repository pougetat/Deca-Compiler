cmake_minimum_required(VERSION 3.0)

add_subdirectory(AST)

set(SRCS
	syntax_parser.cpp
	semantics_analyzer.cpp
	)
	
set(HEADERS
	syntax_parser.h
	semantics_analyzer.h
	)

add_library(parser ${SRCS} ${HEADERS})
