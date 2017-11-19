cmake_minimum_required(VERSION 3.0)

set(SRCS
	AbstractMain.cpp
    DeclClass.cpp
    EmptyMain.cpp
    NonEmptyMain.cpp
    Program.cpp
	)
	
set(HEADERS
	AbstractMain.h
    DeclClass.h
	EmptyMain.h
	NonEmptyMain.h
    Program.h
    )

add_library(AST ${SRCS} ${HEADERS})