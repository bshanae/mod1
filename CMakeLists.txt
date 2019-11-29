cmake_minimum_required(VERSION 3.15)
project(21_mod1)

set(CMAKE_CXX_STANDARD 14)

include_directories(
	./mod1_error
	./mod1_map
)

set(MOD1_ERROR
	./mod1_error/mod1_error.cpp)

set(MOD1_MAP
	mod1_map/mod1_map.cpp)

set(MOD1_MAIN
	./main.cpp)

add_executable(21_mod1
	${MOD1_ERROR}
	${MOD1_MAP}
	${MOD1_MAIN})