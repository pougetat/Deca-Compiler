cmake_minimum_required(VERSION 3.0)

set(SRCS
    AbstractInst.cpp
	AbstractMain.cpp
    AbstractPrint.cpp
    DeclClass.cpp
    EmptyMain.cpp
    NonEmptyMain.cpp
    Print.cpp
    Program.cpp
	)
	
set(HEADERS
    AbstractInst.h
	AbstractMain.h
    AbstractPrint.h
    DeclClass.h
	EmptyMain.h
	NonEmptyMain.h
    Print.h
    Program.h
    )

add_library(AST ${SRCS} ${HEADERS})