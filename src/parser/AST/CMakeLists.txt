cmake_minimum_required(VERSION 3.0)

set(SRCS
    AbstractExpr.cpp
    AbstractInst.cpp
	AbstractMain.cpp
    AbstractTreeNode.cpp
    DeclClass.cpp
    DeclVar.cpp
    EmptyMain.cpp
    Identifier.cpp
    Initialization.cpp
    NonEmptyMain.cpp
    Print.cpp
    Program.cpp
	)
	
set(HEADERS
    AbstractExpr.h
    AbstractInst.h
	AbstractMain.h
    AbstractTreeNode.h
    DeclClass.h
    DeclVar.h
	EmptyMain.h
    Identifier.h
    Initialization.h
	NonEmptyMain.h
    Print.h
    Program.h
    )

add_library(AST ${SRCS} ${HEADERS})