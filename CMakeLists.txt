cmake_minimum_required(VERSION 3.15)
project(21_mod1)

set(CMAKE_CXX_STANDARD 14)

link_directories(
	/usr/local/lib

	/Users/bshanae/.brew/Cellar/glfw/3.3/lib
	/Users/bshanae/.brew/Cellar/glew/2.1.0_1/lib)

link_libraries(
	"-framework OpenGL"
	"glfw.3"
	"glew")

include_directories(
	/usr/local/include/GL
	/usr/local/include/GLFW
	/usr/local/include/glm

	/Users/bshanae/.brew/Cellar/glew/2.1.0_1/include/GL
	/Users/bshanae/.brew/Cellar/glfw/3.3/include/GLFW
	/Users/bshanae/.brew/Cellar/glm/0.9.9.5/include/glm

	./mod1_main
	./mod1_main/mod1_main

	./third_party/FastNoise

	./mod1_engine/
	./mod1_engine/mod1_point
	./mod1_engine/mod1_core
	./mod1_engine/mod1_shader
	./mod1_engine/mod1_program
	./mod1_engine/mod1_renderer
	./mod1_engine/mod1_buffer
	./mod1_engine/mod1_loader
	./mod1_engine/mod1_model
	./mod1_engine/mod1_cube
	./mod1_engine/mod1_camera
	./mod1_engine/mod1_callback

	./mod1_algorithm/mod1_plane
	./mod1_algorithm/mod1_terrain
	./mod1_algorithm/mod1_water)

set(MOD1_MAIN
	./third_party/FastNoise/FastNoise.cpp

	./mod1_main/main.cpp

	./mod1_main/mod1_main/mod1_main.cpp
	./mod1_main/mod1_main/exception_x.cpp)

set(MOD1_ALGORITHM
	./mod1_algorithm/mod1_plane/exception_x.cpp
	./mod1_algorithm/mod1_plane/get_index.cpp
	./mod1_algorithm/mod1_plane/get_ptr.cpp
	./mod1_algorithm/mod1_plane/set.cpp
	./mod1_algorithm/mod1_plane/build.cpp
	./mod1_algorithm/mod1_plane/update_normal.cpp
	./mod1_algorithm/mod1_plane/model.cpp
	./mod1_algorithm/mod1_plane/is_valid.cpp

	./mod1_algorithm/mod1_terrain/parse_x.cpp
	./mod1_algorithm/mod1_terrain/build.cpp
	./mod1_algorithm/mod1_terrain/generate_hill.cpp
	./mod1_algorithm/mod1_terrain/prepare.cpp
	./mod1_algorithm/mod1_terrain/info.cpp
	./mod1_algorithm/mod1_terrain/x_delta.cpp
	./mod1_algorithm/mod1_terrain/find_ptr.cpp
	./mod1_algorithm/mod1_terrain/interpolate_x.cpp
	./mod1_algorithm/mod1_terrain/x_color.cpp
	./mod1_algorithm/mod1_terrain/model.cpp
	./mod1_algorithm/mod1_terrain/exception_x.cpp
	mod1_algorithm/mod1_terrain/x_noise.cpp

	./mod1_algorithm/mod1_water/mod1_water.cpp
	./mod1_algorithm/mod1_water/build.cpp
	./mod1_algorithm/mod1_water/model.cpp
	./mod1_algorithm/mod1_water/get_x.cpp
	./mod1_algorithm/mod1_water/set_x.cpp
	./mod1_algorithm/mod1_water/x_model.cpp
	./mod1_algorithm/mod1_water/gravity_x.cpp
	./mod1_algorithm/mod1_water/exception_x.cpp
	./mod1_algorithm/mod1_water/x_flow.cpp
	mod1_algorithm/mod1_water/x_depth.cpp)

set(MOD1_ENGINE
	./mod1_engine/mod1_core/mod1_core.cpp

	./mod1_engine/mod1_shader/mod1_shader.cpp

	./mod1_engine/mod1_renderer/mod1_renderer.cpp

	./mod1_engine/mod1_program/mod1_program.cpp

	./mod1_engine/mod1_buffer/mod1_buffer.h

	./mod1_engine/mod1_model/mod1_model.cpp
	./mod1_engine/mod1_model/mod1_model_data.cpp

	./mod1_engine/mod1_cube/mod1_cube.cpp

	./mod1_engine/mod1_loader/eab_x.cpp
	./mod1_engine/mod1_loader/vao_x.cpp
	./mod1_engine/mod1_loader/vbo_x.cpp

	./mod1_engine/mod1_loader/mod1_loader.cpp
	./mod1_engine/mod1_camera/mod1_camera.cpp

	./mod1_engine/mod1_callback/mod1_callback.cpp)

add_executable(21_mod1
	${MOD1_MAIN}
	${MOD1_ENGINE}
	${MOD1_ALGORITHM})