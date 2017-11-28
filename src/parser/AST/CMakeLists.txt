cmake_minimum_required(VERSION 3.0)

set(SRCS
    AbstractBinaryExpr.cpp
    AbstractExpr.cpp
    AbstractInst.cpp
	AbstractMain.cpp
    AbstractReadExpr.cpp
    AbstractTreeNode.cpp
    AndExpr.cpp
    BooleanLiteral.cpp
    DeclClass.cpp
    DeclVar.cpp
    EmptyMain.cpp
    EqualityExpr.cpp
    Identifier.cpp
    InequalityExpr.cpp
    Initialization.cpp
    IntLiteral.cpp
    NonEmptyMain.cpp
    Null.cpp
    OrExpr.cpp
    Print.cpp
    Program.cpp
    ReadFloat.cpp
    ReadInt.cpp
    This.cpp
	)
	
set(HEADERS
    AbstractBinaryExpr.h
    AbstractExpr.h
    AbstractInst.h
	AbstractMain.h
    AbstractReadExpr.h
    AbstractTreeNode.h
    AndExpr.h
    BooleanLiteral.h
    DeclClass.h
    DeclVar.h
	EmptyMain.h
    EqualityExpr.h
    Identifier.h
    InequalityExpr.h
    Initialization.h
    IntLiteral.h
	NonEmptyMain.h
    Null.h
    OrExpr.h
    Print.h
    Program.h
    ReadFloat.h
    ReadInt.h
    This.h
    )

add_library(AST ${SRCS} ${HEADERS})