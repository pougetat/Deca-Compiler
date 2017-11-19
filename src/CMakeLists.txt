cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(lexer)
add_subdirectory(parser)

set(SRCS
	main.cpp
	)
	
add_executable(main ${SRCS})

target_link_libraries(main lexer)
