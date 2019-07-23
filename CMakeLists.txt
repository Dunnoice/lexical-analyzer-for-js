cmake_minimum_required (VERSION 3.8)

set(TRANSLATOR_SRC
	lexer.cpp
	main.cpp)

add_executable(main ${TRANSLATOR_SRC})