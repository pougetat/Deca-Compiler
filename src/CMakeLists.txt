cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(lexer)
add_subdirectory(syntax)
add_subdirectory(context)
add_subdirectory(generator)

set(SRCS
	main.cpp
	)
	
add_executable(main ${SRCS})

target_link_libraries(main lexer syntax AST context generator)