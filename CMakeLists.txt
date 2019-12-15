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
	/usr/local/include/glm
	./mod1_main/mod1_error
	./mod1_main
	./mod1_main/mod1_main
	./mod1_algorithm/mod1_map
	./mod1_engine/mod1_core
	./mod1_engine/mod1_shader
	./mod1_engine/mod1_program
	./mod1_engine/mod1_renderer
	./mod1_engine/mod1_loader
	./mod1_engine/mod1_model
	./mod1_engine/mod1_terrain)

set(MOD1_MAIN
	./mod1_main/mod1_error/mod1_error.cpp
	./mod1_main/main.cpp
	./mod1_main/mod1_main/mod1_main.cpp)

set(MOD1_ALGORITHM
	./mod1_algorithm/mod1_map/mod1_map.cpp)

set(MOD1_ENGINE
	./mod1_engine/mod1_core/mod1_core.cpp
	./mod1_engine/mod1_shader/mod1_shader.cpp
	./mod1_engine/mod1_renderer/mod1_renderer.cpp
	./mod1_engine/mod1_program/mod1_program.cpp
	./mod1_engine/mod1_model/mod1_model_data.cpp
	./mod1_engine/mod1_model/mod1_model.cpp
	./mod1_engine/mod1_loader/eab_x.cpp
	./mod1_engine/mod1_loader/vao_x.cpp
	./mod1_engine/mod1_loader/vbo_x.cpp
	./mod1_engine/mod1_loader/mod1_loader.cpp
	./mod1_engine/mod1_terrain/mod1_terrain.cpp)

add_executable(21_mod1
	${MOD1_MAIN}
	${MOD1_ENGINE}
	${MOD1_ALGORITHM})