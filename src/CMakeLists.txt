cmake_minimum_required(VERSION 3.0)

add_subdirectory(lexer)

set(SRCS
	main.cpp
	)
	
add_executable(main ${SRCS})

target_link_libraries(main lexer)
