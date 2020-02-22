cmake_minimum_required(VERSION 3.15)
project(21_mod1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(EXTERN
	mod1_extern/FastNoise/FastNoise.cpp)

set(ENGINE_GL
	mod1_engine_gl/core/core.cpp
	mod1_engine_gl/core/show_polygon_back.cpp
	mod1_engine_gl/core/x_callback.cpp
	mod1_engine_gl/core/clear.cpp
	mod1_engine_gl/core/draw.cpp
	mod1_engine_gl/core/glfw_callback_x.cpp
	mod1_engine_gl/core/start.cpp
	mod1_engine_gl/core/finish.cpp
	mod1_engine_gl/core/swap_buffers.cpp
	mod1_engine_gl/core/x_signal.cpp
	mod1_engine_gl/core/x_timer.cpp
	mod1_engine_gl/core/time.cpp
	mod1_engine_gl/core/use_depth_test.cpp

	mod1_engine_gl/shader/shader.cpp

	mod1_engine_gl/renderer/renderer.cpp
	mod1_engine_gl/renderer/functor_x.cpp
	mod1_engine_gl/renderer/add_model.cpp
	mod1_engine_gl/renderer/request_render.cpp

	mod1_engine_gl/texture/texture.cpp

	mod1_engine_gl/framebuffer/framebuffer.cpp

	mod1_engine_gl/program/program.cpp

	mod1_engine_gl/buffer/buffer.h

	mod1_engine_gl/model/model.cpp
	mod1_engine_gl/model/draw.cpp
	mod1_engine_gl/model/load.cpp
	mod1_engine_gl/model/model.cpp
	mod1_engine_gl/model/pointer.cpp
	mod1_engine_gl/model/is_valid.cpp
	mod1_engine_gl/model/set_as_x.cpp
	mod1_engine_gl/model/start.cpp
	mod1_engine_gl/model/stop.cpp
	mod1_engine_gl/model/save.cpp

	mod1_engine_gl/vbo/vbo.cpp
	mod1_engine_gl/vao/vao.cpp
	mod1_engine_gl/eab/eab.cpp

	mod1_engine_gl/camera/camera.cpp

	mod1_engine_gl/event/event.cpp

	mod1_engine_gl/callback/callback.cpp

	mod1_engine_gl/timer/timer.cpp

	mod1_engine_gl/uniform/uniform.cpp)

set(ENGINE_CL
	mod1_engine_cl/core/core.cpp
	mod1_engine_cl/kernel/kernel.cpp
	mod1_engine_cl/argument/argument.cpp)

set(GUI
	mod1_gui/symbol/symbol.cpp

	mod1_gui/font/font.cpp

	mod1_gui/label/label.cpp

	mod1_gui/button/button.cpp

	mod1_gui/layout/layout.cpp

	mod1_gui/system/system.cpp
	mod1_gui/system/program.cpp
	mod1_gui/system/square.cpp
	mod1_gui/system/write.cpp
	mod1_gui/system/generate_x.cpp
	mod1_gui/system/render.cpp
	mod1_gui/system/callback.cpp)

set(ALGORITHM
	mod1_algorithm/terrain/terrain.cpp
	mod1_algorithm/terrain/parse_map_x.cpp
	mod1_algorithm/terrain/parse_noise_x.cpp
	mod1_algorithm/terrain/build.cpp
	mod1_algorithm/terrain/generate_hill.cpp
	mod1_algorithm/terrain/prepare.cpp
	mod1_algorithm/terrain/normalize.cpp
	mod1_algorithm/terrain/resize.cpp
	mod1_algorithm/terrain/find_iter.cpp
	mod1_algorithm/terrain/interpolate_x.cpp
	mod1_algorithm/terrain/model.cpp
	mod1_algorithm/terrain/x_noise.cpp
	mod1_algorithm/terrain/x_color.cpp
	mod1_algorithm/terrain/check_file_extension.cpp

	mod1_algorithm/water/water.cpp
	mod1_algorithm/water/build.cpp
	mod1_algorithm/water/model.cpp
	mod1_algorithm/water/x_x_height.cpp
	mod1_algorithm/water/x_water_depth.cpp
	mod1_algorithm/water/update_x.cpp
	mod1_algorithm/water/gravity_x.cpp
	mod1_algorithm/water/data_x.cpp
	mod1_algorithm/water/cl_build.cpp
	mod1_algorithm/water/cl_set_x.cpp
	mod1_algorithm/water/cl_link_x.cpp
	mod1_algorithm/water/cl_write.cpp
	mod1_algorithm/water/x_color.cpp
	mod1_algorithm/water/x_alpha.cpp)


set(GENERAL
	mod1_general/blur/blur.cpp

	mod1_general/general/general.cpp
	mod1_general/general/render.cpp
	mod1_general/general/functor_x.cpp
	mod1_general/general/scenario_x.cpp
	mod1_general/general/program.cpp
	mod1_general/general/build.cpp
	mod1_general/general/script_x.cpp
	mod1_general/general/hint_x.cpp

	mod1_general/main.cpp)

find_package(PkgConfig REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED STATIC)
find_package(Freetype REQUIRED)

add_executable(21_mod1
	${EXTERN}
	${ENGINE_GL}
	${ENGINE_CL}
	${GUI}
	${ALGORITHM}
	${GENERAL})

target_link_libraries(21_mod1
	glfw
	OpenGL::GL
	OpenCL::OpenCL
	GLEW::GLEW
	${FREETYPE_LIBRARIES})

target_include_directories(21_mod1
	PRIVATE ${GLEW_INCLUDE_DIRS}
	PRIVATE ${FREETYPE_INCLUDE_DIRS}
	PRIVATE mod1_extern/OpenCL
	PRIVATE .)