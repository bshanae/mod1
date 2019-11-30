cmake_minimum_required(VERSION 3.15)
project(21_mod1)

set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)

link_libraries(
	"-framework OpenGL"
	"glfw.3"
	"glew")

include_directories(
	/usr/local/include/GL
	/usr/local/include/GLFW
	./mod1_error
	./mod1_main
	./mod1_map
	./mod1_core
	./mod1_shader
	./mod1_program
	./mod1_drawer)

set(MOD1_ERROR
	./mod1_error/mod1_error.cpp)

set(MOD1_MAIN
	mod1_main/main.cpp)

set(MOD1_MAP
	./mod1_map/mod1_map.cpp)

set(MOD1_CORE
	./mod1_core/mod1_core.cpp)

set(MOD1_SHADER
	./mod1_shader/mod1_shader.cpp)

set(MOD1_PROGRAM
	./mod1_program/mod1_program.cpp)

set(MOD1_DRAWER
	mod1_drawer/mod1_drawer.cpp
	)

add_executable(21_mod1
	${MOD1_ERROR}
	${MOD1_MAIN}
	${MOD1_MAP}
	${MOD1_CORE}
	${MOD1_SHADER}
	${MOD1_PROGRAM}
	${MOD1_DRAWER})