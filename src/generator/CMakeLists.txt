cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set(SRCS
    Generator.cpp
)
	
set(HEADERS
    Generator.h
)

add_library(generator ${SRCS} ${HEADERS})