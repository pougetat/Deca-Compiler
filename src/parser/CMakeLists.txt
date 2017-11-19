cmake_minimum_required(VERSION 3.0)

add_subdirectory(AST)

set(SRCS
	SyntaxParser.cpp
	SemanticsAnalyzer.cpp
	)
	
set(HEADERS
	SyntaxParser.h
	SemanticsAnalyzer.h
	)

add_library(parser ${SRCS} ${HEADERS})
