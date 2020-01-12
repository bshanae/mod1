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

	./)

set(LIBRARIES
	./libraries/FastNoise/FastNoise.cpp)

set(MAIN
	mod1_main/main.cpp

	mod1_main/mod1_main/mod1_main.cpp)

set(ALGORITHM
	./algorithm/mod1_plane/mod1_plane.cpp
	./algorithm/mod1_plane/get_x.cpp
	./algorithm/mod1_plane/set.cpp
	./algorithm/mod1_plane/build.cpp
	./algorithm/mod1_plane/update_x.cpp
	./algorithm/mod1_plane/model.cpp
	./algorithm/mod1_plane/is_x.cpp
	./algorithm/mod1_plane/read_x.cpp
	./algorithm/mod1_plane/write_x.cpp

	./algorithm/mod1_terrain/mod1_terrain.cpp
	./algorithm/mod1_terrain/parse_x.cpp
	./algorithm/mod1_terrain/build.cpp
	./algorithm/mod1_terrain/generate_hill.cpp
	./algorithm/mod1_terrain/prepare.cpp
	./algorithm/mod1_terrain/info.cpp
	./algorithm/mod1_terrain/x_delta.cpp
	./algorithm/mod1_terrain/find_ptr.cpp
	./algorithm/mod1_terrain/interpolate_x.cpp
	./algorithm/mod1_plane/x_color.cpp
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
	./mod1_engine/core/core.cpp

	./mod1_engine/shader/shader.cpp

	./mod1_engine/renderer/renderer.cpp
	./mod1_engine/renderer/glfw_callback.cpp
	./mod1_engine/renderer/loop.cpp
	./mod1_engine/renderer/render_x.cpp
	./mod1_engine/renderer/load_model.cpp
	./mod1_engine/renderer/cube.cpp

	./mod1_engine/program/program.cpp

	./mod1_engine/buffer/buffer.h

	./mod1_engine/model/model.cpp
	./mod1_engine/model/model_data.cpp

	./mod1_engine/loader/eab_x.cpp
	./mod1_engine/loader/vao_x.cpp
	./mod1_engine/loader/vbo_x.cpp

	./mod1_engine/loader/loader.cpp
	./mod1_engine/camera/camera.cpp)

add_executable(21_mod1
	${LIBRARIES}
	${MAIN}
	${ENGINE}
	${ALGORITHM})