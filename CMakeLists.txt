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

	main
	main/mod1_main

	./libraries/FastNoise

	./engine/
	./engine/mod1_point
	./engine/mod1_core
	./engine/mod1_shader
	./engine/mod1_program
	./engine/mod1_renderer
	./engine/mod1_buffer
	./engine/mod1_loader
	./engine/mod1_model
	./engine/mod1_cube
	./engine/mod1_camera
	./engine/mod1_callback

	./algorithm/mod1_plane
	./algorithm/mod1_terrain
	./algorithm/mod1_water)

set(LIBRARIES
	./libraries/FastNoise/FastNoise.cpp)

set(MAIN
	main/main.cpp

	main/mod1_main/mod1_main.cpp
	)

set(ALGORITHM
	./algorithm/mod1_plane/mod1_plane.cpp
	./algorithm/mod1_plane/get_index.cpp
	./algorithm/mod1_plane/get_ptr.cpp
	./algorithm/mod1_plane/set.cpp
	./algorithm/mod1_plane/build.cpp
	./algorithm/mod1_plane/update_normal.cpp
	./algorithm/mod1_plane/model.cpp
	./algorithm/mod1_plane/is_valid.cpp

	./algorithm/mod1_terrain/mod1_terrain.cpp
	./algorithm/mod1_terrain/parse_x.cpp
	./algorithm/mod1_terrain/build.cpp
	./algorithm/mod1_terrain/generate_hill.cpp
	./algorithm/mod1_terrain/prepare.cpp
	./algorithm/mod1_terrain/info.cpp
	./algorithm/mod1_terrain/x_delta.cpp
	./algorithm/mod1_terrain/find_ptr.cpp
	./algorithm/mod1_terrain/interpolate_x.cpp
	./algorithm/mod1_terrain/x_color.cpp
	./algorithm/mod1_terrain/model.cpp
	./algorithm/mod1_terrain/x_noise.cpp

	./algorithm/mod1_water/mod1_water.cpp
	./algorithm/mod1_water/build.cpp
	./algorithm/mod1_water/model.cpp
	./algorithm/mod1_water/get_x.cpp
	./algorithm/mod1_water/set_x.cpp
	./algorithm/mod1_water/x_model.cpp
	./algorithm/mod1_water/gravity_x.cpp
	./algorithm/mod1_water/x_flow.cpp
	./algorithm/mod1_water/x_depth.cpp
	./algorithm/mod1_water/x_color.cpp
	./algorithm/mod1_water/callback.cpp)

set(ENGINE
	./engine/mod1_core/mod1_core.cpp

	./engine/mod1_shader/mod1_shader.cpp

	./engine/mod1_renderer/mod1_renderer.cpp

	./engine/mod1_program/mod1_program.cpp

	./engine/mod1_buffer/mod1_buffer.h

	./engine/mod1_model/mod1_model.cpp
	./engine/mod1_model/mod1_model_data.cpp

	./engine/mod1_cube/mod1_cube.cpp

	./engine/mod1_loader/eab_x.cpp
	./engine/mod1_loader/vao_x.cpp
	./engine/mod1_loader/vbo_x.cpp

	./engine/mod1_loader/mod1_loader.cpp
	./engine/mod1_camera/mod1_camera.cpp

	./engine/mod1_callback/mod1_callback.cpp)

add_executable(21_mod1
	${LIBRARIES}
	${MAIN}
	${ENGINE}
	${ALGORITHM})