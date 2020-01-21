cmake_minimum_required(VERSION 3.15)
project(21_mod1)

set(CMAKE_CXX_STANDARD 14)

link_directories(
	/usr/local/lib

	/Users/bshanae/.brew/Cellar/glfw/3.3/lib
	/Users/bshanae/.brew/Cellar/glew/2.1.0_1/lib)

link_libraries(
	"-framework OpenGL"
	"-framework OpenCL"
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
	./mod1_libraries/FastNoise/FastNoise.cpp)

set(ENGINE_GL
	./mod1_engine_gl/core/core.cpp

	./mod1_engine_gl/shader/shader.cpp

	./mod1_engine_gl/renderer/renderer.cpp
	./mod1_engine_gl/renderer/glfw_callback.cpp
	./mod1_engine_gl/renderer/add_callback.cpp
	./mod1_engine_gl/renderer/load_model.cpp
	./mod1_engine_gl/renderer/loop.cpp
	./mod1_engine_gl/renderer/render_x.cpp
	./mod1_engine_gl/renderer/cube/cube.cpp

	./mod1_engine_gl/program/program.cpp

	./mod1_engine_gl/buffer/buffer.h

	./mod1_engine_gl/model/model.cpp
	./mod1_engine_gl/model/model_data.cpp
	./mod1_engine_gl/model/model_reader.cpp

	./mod1_engine_gl/loader/eab_x.cpp
	./mod1_engine_gl/loader/vao_x.cpp
	./mod1_engine_gl/loader/vbo_x.cpp

	./mod1_engine_gl/loader/loader.cpp
	./mod1_engine_gl/camera/camera.cpp

	./mod1_engine_gl/callback/callback.cpp

	./mod1_engine_gl/uniform/uniform.cpp)

set(ENGINE_CL
	./mod1_engine_cl/core/core.cpp
	./mod1_engine_cl/kenrel/kernel.cpp
	./mod1_engine_cl/argument/argument.cpp)

set(ALGORITHM
	./mod1_algorithm/plane/plane.cpp
	./mod1_algorithm/plane/get_x.cpp
	./mod1_algorithm/plane/set.cpp
	./mod1_algorithm/plane/build.cpp
	./mod1_algorithm/plane/update_x.cpp
	./mod1_algorithm/plane/model.cpp
	./mod1_algorithm/plane/is_x.cpp
	./mod1_algorithm/plane/read_x.cpp
	./mod1_algorithm/plane/write_x.cpp
	mod1_algorithm/plane/x_index_style.cpp

	./mod1_algorithm/terrain/terrain.cpp
	./mod1_algorithm/terrain/parse_x.cpp
	./mod1_algorithm/terrain/build.cpp
	./mod1_algorithm/terrain/generate_hill.cpp
	./mod1_algorithm/terrain/prepare.cpp
	./mod1_algorithm/terrain/info.cpp
	./mod1_algorithm/terrain/x_delta.cpp
	./mod1_algorithm/terrain/find_ptr.cpp
	./mod1_algorithm/terrain/interpolate_x.cpp
	./mod1_algorithm/plane/x_color.cpp
	./mod1_algorithm/terrain/model.cpp
	./mod1_algorithm/terrain/x_noise.cpp

	./mod1_algorithm/water/water.cpp
	./mod1_algorithm/water/build.cpp
	./mod1_algorithm/water/model.cpp
	./mod1_algorithm/water/get_x.cpp
	./mod1_algorithm/water/set_x.cpp
	./mod1_algorithm/water/x_model.cpp
	./mod1_algorithm/water/gravity_x.cpp
	./mod1_algorithm/water/x_color.cpp
	./mod1_algorithm/water/callback.cpp
	./mod1_algorithm/water/data_x.cpp
	./mod1_algorithm/water/cl_build.cpp
	./mod1_algorithm/water/cl_set_x.cpp
	./mod1_algorithm/water/cl_link_x.cpp
	./mod1_algorithm/water/cl_write.cpp)


set(MAIN
	./mod1_main/main.cpp

	./mod1_main/mod1_main/mod1_main.cpp)

add_executable(21_mod1
	${LIBRARIES}
	${MAIN}
	${ENGINE_GL}
	${ENGINE_CL}
	${ALGORITHM})