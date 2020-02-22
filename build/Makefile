#						FUNCTIONS

define INFO
${info ${PREFIX} : $1}
endef

#						VARIABLES

COMMA = ,

OBJECT_FOLDER = .object
DEPEND_FOLDER = .depend

COMPILER = clang++
PREFIX = mod1
EXECUTABLE = mod1

INCLUDE = -I ../mod1_extern/freetype/2.10.1/include/freetype2 -I ../mod1_extern/glew/2.1.0/include/GL -I ../mod1_extern/glfw/3.3/include/GLFW -I ../mod1_extern/glm/0.9.9.5/include/glm -I ../mod1_extern/OpenCL -I ../
OBJECT = ${OBJECT_FOLDER}/FastNoise.cpp.o ${OBJECT_FOLDER}/core.cpp.o ${OBJECT_FOLDER}/show_polygon_back.cpp.o ${OBJECT_FOLDER}/x_callback.cpp.o ${OBJECT_FOLDER}/clear.cpp.o ${OBJECT_FOLDER}/draw.cpp.o ${OBJECT_FOLDER}/glfw_callback_x.cpp.o ${OBJECT_FOLDER}/start.cpp.o ${OBJECT_FOLDER}/finish.cpp.o ${OBJECT_FOLDER}/swap_buffers.cpp.o ${OBJECT_FOLDER}/x_signal.cpp.o ${OBJECT_FOLDER}/x_timer.cpp.o ${OBJECT_FOLDER}/time.cpp.o ${OBJECT_FOLDER}/use_depth_test.cpp.o ${OBJECT_FOLDER}/shader.cpp.o ${OBJECT_FOLDER}/renderer.cpp.o ${OBJECT_FOLDER}/functor_x.cpp.o ${OBJECT_FOLDER}/add_model.cpp.o ${OBJECT_FOLDER}/request_render.cpp.o ${OBJECT_FOLDER}/texture.cpp.o ${OBJECT_FOLDER}/framebuffer.cpp.o ${OBJECT_FOLDER}/program.cpp.o ${OBJECT_FOLDER}/model.cpp.o ${OBJECT_FOLDER}/draw_1.cpp.o ${OBJECT_FOLDER}/load.cpp.o ${OBJECT_FOLDER}/pointer.cpp.o ${OBJECT_FOLDER}/is_valid.cpp.o ${OBJECT_FOLDER}/set_as_x.cpp.o ${OBJECT_FOLDER}/start_1.cpp.o ${OBJECT_FOLDER}/stop.cpp.o ${OBJECT_FOLDER}/save.cpp.o ${OBJECT_FOLDER}/vbo.cpp.o ${OBJECT_FOLDER}/vao.cpp.o ${OBJECT_FOLDER}/eab.cpp.o ${OBJECT_FOLDER}/camera.cpp.o ${OBJECT_FOLDER}/event.cpp.o ${OBJECT_FOLDER}/callback.cpp.o ${OBJECT_FOLDER}/timer.cpp.o ${OBJECT_FOLDER}/uniform.cpp.o ${OBJECT_FOLDER}/core_1.cpp.o ${OBJECT_FOLDER}/kernel.cpp.o ${OBJECT_FOLDER}/argument.cpp.o ${OBJECT_FOLDER}/symbol.cpp.o ${OBJECT_FOLDER}/font.cpp.o ${OBJECT_FOLDER}/label.cpp.o ${OBJECT_FOLDER}/button.cpp.o ${OBJECT_FOLDER}/layout.cpp.o ${OBJECT_FOLDER}/system.cpp.o ${OBJECT_FOLDER}/program_1.cpp.o ${OBJECT_FOLDER}/square.cpp.o ${OBJECT_FOLDER}/write.cpp.o ${OBJECT_FOLDER}/generate_x.cpp.o ${OBJECT_FOLDER}/render.cpp.o ${OBJECT_FOLDER}/callback_1.cpp.o ${OBJECT_FOLDER}/terrain.cpp.o ${OBJECT_FOLDER}/parse_map_x.cpp.o ${OBJECT_FOLDER}/parse_noise_x.cpp.o ${OBJECT_FOLDER}/build.cpp.o ${OBJECT_FOLDER}/generate_hill.cpp.o ${OBJECT_FOLDER}/prepare.cpp.o ${OBJECT_FOLDER}/normalize.cpp.o ${OBJECT_FOLDER}/resize.cpp.o ${OBJECT_FOLDER}/find_iter.cpp.o ${OBJECT_FOLDER}/interpolate_x.cpp.o ${OBJECT_FOLDER}/model_1.cpp.o ${OBJECT_FOLDER}/x_noise.cpp.o ${OBJECT_FOLDER}/x_color.cpp.o ${OBJECT_FOLDER}/check_file_extension.cpp.o ${OBJECT_FOLDER}/water.cpp.o ${OBJECT_FOLDER}/build_1.cpp.o ${OBJECT_FOLDER}/model_2.cpp.o ${OBJECT_FOLDER}/x_x_height.cpp.o ${OBJECT_FOLDER}/x_water_depth.cpp.o ${OBJECT_FOLDER}/update_x.cpp.o ${OBJECT_FOLDER}/gravity_x.cpp.o ${OBJECT_FOLDER}/data_x.cpp.o ${OBJECT_FOLDER}/cl_build.cpp.o ${OBJECT_FOLDER}/cl_set_x.cpp.o ${OBJECT_FOLDER}/cl_link_x.cpp.o ${OBJECT_FOLDER}/cl_write.cpp.o ${OBJECT_FOLDER}/x_color_1.cpp.o ${OBJECT_FOLDER}/x_alpha.cpp.o ${OBJECT_FOLDER}/blur.cpp.o ${OBJECT_FOLDER}/general.cpp.o ${OBJECT_FOLDER}/render_1.cpp.o ${OBJECT_FOLDER}/functor_x_1.cpp.o ${OBJECT_FOLDER}/scenario_x.cpp.o ${OBJECT_FOLDER}/program_2.cpp.o ${OBJECT_FOLDER}/build_2.cpp.o ${OBJECT_FOLDER}/script_x.cpp.o ${OBJECT_FOLDER}/hint_x.cpp.o ${OBJECT_FOLDER}/main.cpp.o
DEPEND = ${DEPEND_FOLDER}/FastNoise.cpp.d ${DEPEND_FOLDER}/core.cpp.d ${DEPEND_FOLDER}/show_polygon_back.cpp.d ${DEPEND_FOLDER}/x_callback.cpp.d ${DEPEND_FOLDER}/clear.cpp.d ${DEPEND_FOLDER}/draw.cpp.d ${DEPEND_FOLDER}/glfw_callback_x.cpp.d ${DEPEND_FOLDER}/start.cpp.d ${DEPEND_FOLDER}/finish.cpp.d ${DEPEND_FOLDER}/swap_buffers.cpp.d ${DEPEND_FOLDER}/x_signal.cpp.d ${DEPEND_FOLDER}/x_timer.cpp.d ${DEPEND_FOLDER}/time.cpp.d ${DEPEND_FOLDER}/use_depth_test.cpp.d ${DEPEND_FOLDER}/shader.cpp.d ${DEPEND_FOLDER}/renderer.cpp.d ${DEPEND_FOLDER}/functor_x.cpp.d ${DEPEND_FOLDER}/add_model.cpp.d ${DEPEND_FOLDER}/request_render.cpp.d ${DEPEND_FOLDER}/texture.cpp.d ${DEPEND_FOLDER}/framebuffer.cpp.d ${DEPEND_FOLDER}/program.cpp.d ${DEPEND_FOLDER}/model.cpp.d ${DEPEND_FOLDER}/draw_1.cpp.d ${DEPEND_FOLDER}/load.cpp.d ${DEPEND_FOLDER}/pointer.cpp.d ${DEPEND_FOLDER}/is_valid.cpp.d ${DEPEND_FOLDER}/set_as_x.cpp.d ${DEPEND_FOLDER}/start_1.cpp.d ${DEPEND_FOLDER}/stop.cpp.d ${DEPEND_FOLDER}/save.cpp.d ${DEPEND_FOLDER}/vbo.cpp.d ${DEPEND_FOLDER}/vao.cpp.d ${DEPEND_FOLDER}/eab.cpp.d ${DEPEND_FOLDER}/camera.cpp.d ${DEPEND_FOLDER}/event.cpp.d ${DEPEND_FOLDER}/callback.cpp.d ${DEPEND_FOLDER}/timer.cpp.d ${DEPEND_FOLDER}/uniform.cpp.d ${DEPEND_FOLDER}/core_1.cpp.d ${DEPEND_FOLDER}/kernel.cpp.d ${DEPEND_FOLDER}/argument.cpp.d ${DEPEND_FOLDER}/symbol.cpp.d ${DEPEND_FOLDER}/font.cpp.d ${DEPEND_FOLDER}/label.cpp.d ${DEPEND_FOLDER}/button.cpp.d ${DEPEND_FOLDER}/layout.cpp.d ${DEPEND_FOLDER}/system.cpp.d ${DEPEND_FOLDER}/program_1.cpp.d ${DEPEND_FOLDER}/square.cpp.d ${DEPEND_FOLDER}/write.cpp.d ${DEPEND_FOLDER}/generate_x.cpp.d ${DEPEND_FOLDER}/render.cpp.d ${DEPEND_FOLDER}/callback_1.cpp.d ${DEPEND_FOLDER}/terrain.cpp.d ${DEPEND_FOLDER}/parse_map_x.cpp.d ${DEPEND_FOLDER}/parse_noise_x.cpp.d ${DEPEND_FOLDER}/build.cpp.d ${DEPEND_FOLDER}/generate_hill.cpp.d ${DEPEND_FOLDER}/prepare.cpp.d ${DEPEND_FOLDER}/normalize.cpp.d ${DEPEND_FOLDER}/resize.cpp.d ${DEPEND_FOLDER}/find_iter.cpp.d ${DEPEND_FOLDER}/interpolate_x.cpp.d ${DEPEND_FOLDER}/model_1.cpp.d ${DEPEND_FOLDER}/x_noise.cpp.d ${DEPEND_FOLDER}/x_color.cpp.d ${DEPEND_FOLDER}/check_file_extension.cpp.d ${DEPEND_FOLDER}/water.cpp.d ${DEPEND_FOLDER}/build_1.cpp.d ${DEPEND_FOLDER}/model_2.cpp.d ${DEPEND_FOLDER}/x_x_height.cpp.d ${DEPEND_FOLDER}/x_water_depth.cpp.d ${DEPEND_FOLDER}/update_x.cpp.d ${DEPEND_FOLDER}/gravity_x.cpp.d ${DEPEND_FOLDER}/data_x.cpp.d ${DEPEND_FOLDER}/cl_build.cpp.d ${DEPEND_FOLDER}/cl_set_x.cpp.d ${DEPEND_FOLDER}/cl_link_x.cpp.d ${DEPEND_FOLDER}/cl_write.cpp.d ${DEPEND_FOLDER}/x_color_1.cpp.d ${DEPEND_FOLDER}/x_alpha.cpp.d ${DEPEND_FOLDER}/blur.cpp.d ${DEPEND_FOLDER}/general.cpp.d ${DEPEND_FOLDER}/render_1.cpp.d ${DEPEND_FOLDER}/functor_x_1.cpp.d ${DEPEND_FOLDER}/scenario_x.cpp.d ${DEPEND_FOLDER}/program_2.cpp.d ${DEPEND_FOLDER}/build_2.cpp.d ${DEPEND_FOLDER}/script_x.cpp.d ${DEPEND_FOLDER}/hint_x.cpp.d ${DEPEND_FOLDER}/main.cpp.d
LINK_DIRECTORY = -L ../mod1_extern/freetype/2.10.1/lib -L ../mod1_extern/glew/2.1.0/lib -L ../mod1_extern/glfw/3.3/lib
LINK_LIBRARY = -l freetype -l glfw.3 -l glew -framework OpenGL -framework OpenCL

FLAG = -std=c++17

#						BASIC RULES	

all : ${EXECUTABLE}

${EXECUTABLE} : ${OBJECT}
	${call INFO,Linking in executable ${EXECUTABLE}}
	@${COMPILER} ${FLAG} ${LINK_DIRECTORY} ${LINK_LIBRARY} ${OBJECT} -o ${EXECUTABLE}

clean :
	${call INFO,Deleting objects' folder}
	@rm -rf ${OBJECT_FOLDER}
	${call INFO,Deleting dependencies' folder}
	@rm -rf ${DEPEND_FOLDER}

fclean : clean
	${call INFO,Deleting executable}
	@rm -rf ${EXECUTABLE}

re : fclean ${EXECUTABLE}

info :
	@echo "Objects :"
	@echo ${OBJECT}
	@echo "Depends :"
	@echo ${DEPEND}

.PHONY : clean fclean re info

#						OBJECTS
	
${OBJECT_FOLDER} :
	${call INFO,Creating objects' folder}
	@mkdir ${OBJECT_FOLDER}

${OBJECT_FOLDER}/FastNoise.cpp.o : ${DEPEND_FOLDER}/FastNoise.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,1%${COMMA} compiling object ../mod1_extern/FastNoise/FastNoise.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/FastNoise.cpp.o -MF ${DEPEND_FOLDER}/FastNoise.cpp.d -c ../mod1_extern/FastNoise/FastNoise.cpp -o ${OBJECT_FOLDER}/FastNoise.cpp.o

${OBJECT_FOLDER}/core.cpp.o : ${DEPEND_FOLDER}/core.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,2%${COMMA} compiling object ../mod1_engine_gl/core/core.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/core.cpp.o -MF ${DEPEND_FOLDER}/core.cpp.d -c ../mod1_engine_gl/core/core.cpp -o ${OBJECT_FOLDER}/core.cpp.o

${OBJECT_FOLDER}/show_polygon_back.cpp.o : ${DEPEND_FOLDER}/show_polygon_back.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,3%${COMMA} compiling object ../mod1_engine_gl/core/show_polygon_back.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/show_polygon_back.cpp.o -MF ${DEPEND_FOLDER}/show_polygon_back.cpp.d -c ../mod1_engine_gl/core/show_polygon_back.cpp -o ${OBJECT_FOLDER}/show_polygon_back.cpp.o

${OBJECT_FOLDER}/x_callback.cpp.o : ${DEPEND_FOLDER}/x_callback.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,4%${COMMA} compiling object ../mod1_engine_gl/core/x_callback.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_callback.cpp.o -MF ${DEPEND_FOLDER}/x_callback.cpp.d -c ../mod1_engine_gl/core/x_callback.cpp -o ${OBJECT_FOLDER}/x_callback.cpp.o

${OBJECT_FOLDER}/clear.cpp.o : ${DEPEND_FOLDER}/clear.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,5%${COMMA} compiling object ../mod1_engine_gl/core/clear.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/clear.cpp.o -MF ${DEPEND_FOLDER}/clear.cpp.d -c ../mod1_engine_gl/core/clear.cpp -o ${OBJECT_FOLDER}/clear.cpp.o

${OBJECT_FOLDER}/draw.cpp.o : ${DEPEND_FOLDER}/draw.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,6%${COMMA} compiling object ../mod1_engine_gl/core/draw.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/draw.cpp.o -MF ${DEPEND_FOLDER}/draw.cpp.d -c ../mod1_engine_gl/core/draw.cpp -o ${OBJECT_FOLDER}/draw.cpp.o

${OBJECT_FOLDER}/glfw_callback_x.cpp.o : ${DEPEND_FOLDER}/glfw_callback_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,7%${COMMA} compiling object ../mod1_engine_gl/core/glfw_callback_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/glfw_callback_x.cpp.o -MF ${DEPEND_FOLDER}/glfw_callback_x.cpp.d -c ../mod1_engine_gl/core/glfw_callback_x.cpp -o ${OBJECT_FOLDER}/glfw_callback_x.cpp.o

${OBJECT_FOLDER}/start.cpp.o : ${DEPEND_FOLDER}/start.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,8%${COMMA} compiling object ../mod1_engine_gl/core/start.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/start.cpp.o -MF ${DEPEND_FOLDER}/start.cpp.d -c ../mod1_engine_gl/core/start.cpp -o ${OBJECT_FOLDER}/start.cpp.o

${OBJECT_FOLDER}/finish.cpp.o : ${DEPEND_FOLDER}/finish.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,9%${COMMA} compiling object ../mod1_engine_gl/core/finish.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/finish.cpp.o -MF ${DEPEND_FOLDER}/finish.cpp.d -c ../mod1_engine_gl/core/finish.cpp -o ${OBJECT_FOLDER}/finish.cpp.o

${OBJECT_FOLDER}/swap_buffers.cpp.o : ${DEPEND_FOLDER}/swap_buffers.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,10%${COMMA} compiling object ../mod1_engine_gl/core/swap_buffers.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/swap_buffers.cpp.o -MF ${DEPEND_FOLDER}/swap_buffers.cpp.d -c ../mod1_engine_gl/core/swap_buffers.cpp -o ${OBJECT_FOLDER}/swap_buffers.cpp.o

${OBJECT_FOLDER}/x_signal.cpp.o : ${DEPEND_FOLDER}/x_signal.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,11%${COMMA} compiling object ../mod1_engine_gl/core/x_signal.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_signal.cpp.o -MF ${DEPEND_FOLDER}/x_signal.cpp.d -c ../mod1_engine_gl/core/x_signal.cpp -o ${OBJECT_FOLDER}/x_signal.cpp.o

${OBJECT_FOLDER}/x_timer.cpp.o : ${DEPEND_FOLDER}/x_timer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,13%${COMMA} compiling object ../mod1_engine_gl/core/x_timer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_timer.cpp.o -MF ${DEPEND_FOLDER}/x_timer.cpp.d -c ../mod1_engine_gl/core/x_timer.cpp -o ${OBJECT_FOLDER}/x_timer.cpp.o

${OBJECT_FOLDER}/time.cpp.o : ${DEPEND_FOLDER}/time.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,14%${COMMA} compiling object ../mod1_engine_gl/core/time.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/time.cpp.o -MF ${DEPEND_FOLDER}/time.cpp.d -c ../mod1_engine_gl/core/time.cpp -o ${OBJECT_FOLDER}/time.cpp.o

${OBJECT_FOLDER}/use_depth_test.cpp.o : ${DEPEND_FOLDER}/use_depth_test.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,15%${COMMA} compiling object ../mod1_engine_gl/core/use_depth_test.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/use_depth_test.cpp.o -MF ${DEPEND_FOLDER}/use_depth_test.cpp.d -c ../mod1_engine_gl/core/use_depth_test.cpp -o ${OBJECT_FOLDER}/use_depth_test.cpp.o

${OBJECT_FOLDER}/shader.cpp.o : ${DEPEND_FOLDER}/shader.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,16%${COMMA} compiling object ../mod1_engine_gl/shader/shader.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/shader.cpp.o -MF ${DEPEND_FOLDER}/shader.cpp.d -c ../mod1_engine_gl/shader/shader.cpp -o ${OBJECT_FOLDER}/shader.cpp.o

${OBJECT_FOLDER}/renderer.cpp.o : ${DEPEND_FOLDER}/renderer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,17%${COMMA} compiling object ../mod1_engine_gl/renderer/renderer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/renderer.cpp.o -MF ${DEPEND_FOLDER}/renderer.cpp.d -c ../mod1_engine_gl/renderer/renderer.cpp -o ${OBJECT_FOLDER}/renderer.cpp.o

${OBJECT_FOLDER}/functor_x.cpp.o : ${DEPEND_FOLDER}/functor_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,18%${COMMA} compiling object ../mod1_engine_gl/renderer/functor_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/functor_x.cpp.o -MF ${DEPEND_FOLDER}/functor_x.cpp.d -c ../mod1_engine_gl/renderer/functor_x.cpp -o ${OBJECT_FOLDER}/functor_x.cpp.o

${OBJECT_FOLDER}/add_model.cpp.o : ${DEPEND_FOLDER}/add_model.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,19%${COMMA} compiling object ../mod1_engine_gl/renderer/add_model.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/add_model.cpp.o -MF ${DEPEND_FOLDER}/add_model.cpp.d -c ../mod1_engine_gl/renderer/add_model.cpp -o ${OBJECT_FOLDER}/add_model.cpp.o

${OBJECT_FOLDER}/request_render.cpp.o : ${DEPEND_FOLDER}/request_render.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,20%${COMMA} compiling object ../mod1_engine_gl/renderer/request_render.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/request_render.cpp.o -MF ${DEPEND_FOLDER}/request_render.cpp.d -c ../mod1_engine_gl/renderer/request_render.cpp -o ${OBJECT_FOLDER}/request_render.cpp.o

${OBJECT_FOLDER}/texture.cpp.o : ${DEPEND_FOLDER}/texture.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,21%${COMMA} compiling object ../mod1_engine_gl/texture/texture.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/texture.cpp.o -MF ${DEPEND_FOLDER}/texture.cpp.d -c ../mod1_engine_gl/texture/texture.cpp -o ${OBJECT_FOLDER}/texture.cpp.o

${OBJECT_FOLDER}/framebuffer.cpp.o : ${DEPEND_FOLDER}/framebuffer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,22%${COMMA} compiling object ../mod1_engine_gl/framebuffer/framebuffer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/framebuffer.cpp.o -MF ${DEPEND_FOLDER}/framebuffer.cpp.d -c ../mod1_engine_gl/framebuffer/framebuffer.cpp -o ${OBJECT_FOLDER}/framebuffer.cpp.o

${OBJECT_FOLDER}/program.cpp.o : ${DEPEND_FOLDER}/program.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,23%${COMMA} compiling object ../mod1_engine_gl/program/program.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/program.cpp.o -MF ${DEPEND_FOLDER}/program.cpp.d -c ../mod1_engine_gl/program/program.cpp -o ${OBJECT_FOLDER}/program.cpp.o

${OBJECT_FOLDER}/model.cpp.o : ${DEPEND_FOLDER}/model.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,25%${COMMA} compiling object ../mod1_engine_gl/model/model.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/model.cpp.o -MF ${DEPEND_FOLDER}/model.cpp.d -c ../mod1_engine_gl/model/model.cpp -o ${OBJECT_FOLDER}/model.cpp.o

${OBJECT_FOLDER}/draw_1.cpp.o : ${DEPEND_FOLDER}/draw_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,26%${COMMA} compiling object ../mod1_engine_gl/model/draw.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/draw_1.cpp.o -MF ${DEPEND_FOLDER}/draw_1.cpp.d -c ../mod1_engine_gl/model/draw.cpp -o ${OBJECT_FOLDER}/draw_1.cpp.o

${OBJECT_FOLDER}/load.cpp.o : ${DEPEND_FOLDER}/load.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,27%${COMMA} compiling object ../mod1_engine_gl/model/load.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/load.cpp.o -MF ${DEPEND_FOLDER}/load.cpp.d -c ../mod1_engine_gl/model/load.cpp -o ${OBJECT_FOLDER}/load.cpp.o

${OBJECT_FOLDER}/pointer.cpp.o : ${DEPEND_FOLDER}/pointer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,28%${COMMA} compiling object ../mod1_engine_gl/model/pointer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/pointer.cpp.o -MF ${DEPEND_FOLDER}/pointer.cpp.d -c ../mod1_engine_gl/model/pointer.cpp -o ${OBJECT_FOLDER}/pointer.cpp.o

${OBJECT_FOLDER}/is_valid.cpp.o : ${DEPEND_FOLDER}/is_valid.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,29%${COMMA} compiling object ../mod1_engine_gl/model/is_valid.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/is_valid.cpp.o -MF ${DEPEND_FOLDER}/is_valid.cpp.d -c ../mod1_engine_gl/model/is_valid.cpp -o ${OBJECT_FOLDER}/is_valid.cpp.o

${OBJECT_FOLDER}/set_as_x.cpp.o : ${DEPEND_FOLDER}/set_as_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,30%${COMMA} compiling object ../mod1_engine_gl/model/set_as_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/set_as_x.cpp.o -MF ${DEPEND_FOLDER}/set_as_x.cpp.d -c ../mod1_engine_gl/model/set_as_x.cpp -o ${OBJECT_FOLDER}/set_as_x.cpp.o

${OBJECT_FOLDER}/start_1.cpp.o : ${DEPEND_FOLDER}/start_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,31%${COMMA} compiling object ../mod1_engine_gl/model/start.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/start_1.cpp.o -MF ${DEPEND_FOLDER}/start_1.cpp.d -c ../mod1_engine_gl/model/start.cpp -o ${OBJECT_FOLDER}/start_1.cpp.o

${OBJECT_FOLDER}/stop.cpp.o : ${DEPEND_FOLDER}/stop.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,32%${COMMA} compiling object ../mod1_engine_gl/model/stop.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/stop.cpp.o -MF ${DEPEND_FOLDER}/stop.cpp.d -c ../mod1_engine_gl/model/stop.cpp -o ${OBJECT_FOLDER}/stop.cpp.o

${OBJECT_FOLDER}/save.cpp.o : ${DEPEND_FOLDER}/save.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,33%${COMMA} compiling object ../mod1_engine_gl/model/save.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/save.cpp.o -MF ${DEPEND_FOLDER}/save.cpp.d -c ../mod1_engine_gl/model/save.cpp -o ${OBJECT_FOLDER}/save.cpp.o

${OBJECT_FOLDER}/vbo.cpp.o : ${DEPEND_FOLDER}/vbo.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,34%${COMMA} compiling object ../mod1_engine_gl/vbo/vbo.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/vbo.cpp.o -MF ${DEPEND_FOLDER}/vbo.cpp.d -c ../mod1_engine_gl/vbo/vbo.cpp -o ${OBJECT_FOLDER}/vbo.cpp.o

${OBJECT_FOLDER}/vao.cpp.o : ${DEPEND_FOLDER}/vao.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,35%${COMMA} compiling object ../mod1_engine_gl/vao/vao.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/vao.cpp.o -MF ${DEPEND_FOLDER}/vao.cpp.d -c ../mod1_engine_gl/vao/vao.cpp -o ${OBJECT_FOLDER}/vao.cpp.o

${OBJECT_FOLDER}/eab.cpp.o : ${DEPEND_FOLDER}/eab.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,36%${COMMA} compiling object ../mod1_engine_gl/eab/eab.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/eab.cpp.o -MF ${DEPEND_FOLDER}/eab.cpp.d -c ../mod1_engine_gl/eab/eab.cpp -o ${OBJECT_FOLDER}/eab.cpp.o

${OBJECT_FOLDER}/camera.cpp.o : ${DEPEND_FOLDER}/camera.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,38%${COMMA} compiling object ../mod1_engine_gl/camera/camera.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/camera.cpp.o -MF ${DEPEND_FOLDER}/camera.cpp.d -c ../mod1_engine_gl/camera/camera.cpp -o ${OBJECT_FOLDER}/camera.cpp.o

${OBJECT_FOLDER}/event.cpp.o : ${DEPEND_FOLDER}/event.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,39%${COMMA} compiling object ../mod1_engine_gl/event/event.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/event.cpp.o -MF ${DEPEND_FOLDER}/event.cpp.d -c ../mod1_engine_gl/event/event.cpp -o ${OBJECT_FOLDER}/event.cpp.o

${OBJECT_FOLDER}/callback.cpp.o : ${DEPEND_FOLDER}/callback.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,40%${COMMA} compiling object ../mod1_engine_gl/callback/callback.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/callback.cpp.o -MF ${DEPEND_FOLDER}/callback.cpp.d -c ../mod1_engine_gl/callback/callback.cpp -o ${OBJECT_FOLDER}/callback.cpp.o

${OBJECT_FOLDER}/timer.cpp.o : ${DEPEND_FOLDER}/timer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,41%${COMMA} compiling object ../mod1_engine_gl/timer/timer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/timer.cpp.o -MF ${DEPEND_FOLDER}/timer.cpp.d -c ../mod1_engine_gl/timer/timer.cpp -o ${OBJECT_FOLDER}/timer.cpp.o

${OBJECT_FOLDER}/uniform.cpp.o : ${DEPEND_FOLDER}/uniform.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,42%${COMMA} compiling object ../mod1_engine_gl/uniform/uniform.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/uniform.cpp.o -MF ${DEPEND_FOLDER}/uniform.cpp.d -c ../mod1_engine_gl/uniform/uniform.cpp -o ${OBJECT_FOLDER}/uniform.cpp.o

${OBJECT_FOLDER}/core_1.cpp.o : ${DEPEND_FOLDER}/core_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,43%${COMMA} compiling object ../mod1_engine_cl/core/core.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/core_1.cpp.o -MF ${DEPEND_FOLDER}/core_1.cpp.d -c ../mod1_engine_cl/core/core.cpp -o ${OBJECT_FOLDER}/core_1.cpp.o

${OBJECT_FOLDER}/kernel.cpp.o : ${DEPEND_FOLDER}/kernel.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,44%${COMMA} compiling object ../mod1_engine_cl/kernel/kernel.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/kernel.cpp.o -MF ${DEPEND_FOLDER}/kernel.cpp.d -c ../mod1_engine_cl/kernel/kernel.cpp -o ${OBJECT_FOLDER}/kernel.cpp.o

${OBJECT_FOLDER}/argument.cpp.o : ${DEPEND_FOLDER}/argument.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,45%${COMMA} compiling object ../mod1_engine_cl/argument/argument.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/argument.cpp.o -MF ${DEPEND_FOLDER}/argument.cpp.d -c ../mod1_engine_cl/argument/argument.cpp -o ${OBJECT_FOLDER}/argument.cpp.o

${OBJECT_FOLDER}/symbol.cpp.o : ${DEPEND_FOLDER}/symbol.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,46%${COMMA} compiling object ../mod1_gui/symbol/symbol.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/symbol.cpp.o -MF ${DEPEND_FOLDER}/symbol.cpp.d -c ../mod1_gui/symbol/symbol.cpp -o ${OBJECT_FOLDER}/symbol.cpp.o

${OBJECT_FOLDER}/font.cpp.o : ${DEPEND_FOLDER}/font.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,47%${COMMA} compiling object ../mod1_gui/font/font.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/font.cpp.o -MF ${DEPEND_FOLDER}/font.cpp.d -c ../mod1_gui/font/font.cpp -o ${OBJECT_FOLDER}/font.cpp.o

${OBJECT_FOLDER}/label.cpp.o : ${DEPEND_FOLDER}/label.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,48%${COMMA} compiling object ../mod1_gui/label/label.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/label.cpp.o -MF ${DEPEND_FOLDER}/label.cpp.d -c ../mod1_gui/label/label.cpp -o ${OBJECT_FOLDER}/label.cpp.o

${OBJECT_FOLDER}/button.cpp.o : ${DEPEND_FOLDER}/button.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,50%${COMMA} compiling object ../mod1_gui/button/button.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/button.cpp.o -MF ${DEPEND_FOLDER}/button.cpp.d -c ../mod1_gui/button/button.cpp -o ${OBJECT_FOLDER}/button.cpp.o

${OBJECT_FOLDER}/layout.cpp.o : ${DEPEND_FOLDER}/layout.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,51%${COMMA} compiling object ../mod1_gui/layout/layout.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/layout.cpp.o -MF ${DEPEND_FOLDER}/layout.cpp.d -c ../mod1_gui/layout/layout.cpp -o ${OBJECT_FOLDER}/layout.cpp.o

${OBJECT_FOLDER}/system.cpp.o : ${DEPEND_FOLDER}/system.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,52%${COMMA} compiling object ../mod1_gui/system/system.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/system.cpp.o -MF ${DEPEND_FOLDER}/system.cpp.d -c ../mod1_gui/system/system.cpp -o ${OBJECT_FOLDER}/system.cpp.o

${OBJECT_FOLDER}/program_1.cpp.o : ${DEPEND_FOLDER}/program_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,53%${COMMA} compiling object ../mod1_gui/system/program.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/program_1.cpp.o -MF ${DEPEND_FOLDER}/program_1.cpp.d -c ../mod1_gui/system/program.cpp -o ${OBJECT_FOLDER}/program_1.cpp.o

${OBJECT_FOLDER}/square.cpp.o : ${DEPEND_FOLDER}/square.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,54%${COMMA} compiling object ../mod1_gui/system/square.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/square.cpp.o -MF ${DEPEND_FOLDER}/square.cpp.d -c ../mod1_gui/system/square.cpp -o ${OBJECT_FOLDER}/square.cpp.o

${OBJECT_FOLDER}/write.cpp.o : ${DEPEND_FOLDER}/write.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,55%${COMMA} compiling object ../mod1_gui/system/write.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/write.cpp.o -MF ${DEPEND_FOLDER}/write.cpp.d -c ../mod1_gui/system/write.cpp -o ${OBJECT_FOLDER}/write.cpp.o

${OBJECT_FOLDER}/generate_x.cpp.o : ${DEPEND_FOLDER}/generate_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,56%${COMMA} compiling object ../mod1_gui/system/generate_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/generate_x.cpp.o -MF ${DEPEND_FOLDER}/generate_x.cpp.d -c ../mod1_gui/system/generate_x.cpp -o ${OBJECT_FOLDER}/generate_x.cpp.o

${OBJECT_FOLDER}/render.cpp.o : ${DEPEND_FOLDER}/render.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,57%${COMMA} compiling object ../mod1_gui/system/render.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/render.cpp.o -MF ${DEPEND_FOLDER}/render.cpp.d -c ../mod1_gui/system/render.cpp -o ${OBJECT_FOLDER}/render.cpp.o

${OBJECT_FOLDER}/callback_1.cpp.o : ${DEPEND_FOLDER}/callback_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,58%${COMMA} compiling object ../mod1_gui/system/callback.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/callback_1.cpp.o -MF ${DEPEND_FOLDER}/callback_1.cpp.d -c ../mod1_gui/system/callback.cpp -o ${OBJECT_FOLDER}/callback_1.cpp.o

${OBJECT_FOLDER}/terrain.cpp.o : ${DEPEND_FOLDER}/terrain.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,59%${COMMA} compiling object ../mod1_algorithm/terrain/terrain.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/terrain.cpp.o -MF ${DEPEND_FOLDER}/terrain.cpp.d -c ../mod1_algorithm/terrain/terrain.cpp -o ${OBJECT_FOLDER}/terrain.cpp.o

${OBJECT_FOLDER}/parse_map_x.cpp.o : ${DEPEND_FOLDER}/parse_map_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,60%${COMMA} compiling object ../mod1_algorithm/terrain/parse_map_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/parse_map_x.cpp.o -MF ${DEPEND_FOLDER}/parse_map_x.cpp.d -c ../mod1_algorithm/terrain/parse_map_x.cpp -o ${OBJECT_FOLDER}/parse_map_x.cpp.o

${OBJECT_FOLDER}/parse_noise_x.cpp.o : ${DEPEND_FOLDER}/parse_noise_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,61%${COMMA} compiling object ../mod1_algorithm/terrain/parse_noise_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/parse_noise_x.cpp.o -MF ${DEPEND_FOLDER}/parse_noise_x.cpp.d -c ../mod1_algorithm/terrain/parse_noise_x.cpp -o ${OBJECT_FOLDER}/parse_noise_x.cpp.o

${OBJECT_FOLDER}/build.cpp.o : ${DEPEND_FOLDER}/build.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,63%${COMMA} compiling object ../mod1_algorithm/terrain/build.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/build.cpp.o -MF ${DEPEND_FOLDER}/build.cpp.d -c ../mod1_algorithm/terrain/build.cpp -o ${OBJECT_FOLDER}/build.cpp.o

${OBJECT_FOLDER}/generate_hill.cpp.o : ${DEPEND_FOLDER}/generate_hill.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,64%${COMMA} compiling object ../mod1_algorithm/terrain/generate_hill.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/generate_hill.cpp.o -MF ${DEPEND_FOLDER}/generate_hill.cpp.d -c ../mod1_algorithm/terrain/generate_hill.cpp -o ${OBJECT_FOLDER}/generate_hill.cpp.o

${OBJECT_FOLDER}/prepare.cpp.o : ${DEPEND_FOLDER}/prepare.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,65%${COMMA} compiling object ../mod1_algorithm/terrain/prepare.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/prepare.cpp.o -MF ${DEPEND_FOLDER}/prepare.cpp.d -c ../mod1_algorithm/terrain/prepare.cpp -o ${OBJECT_FOLDER}/prepare.cpp.o

${OBJECT_FOLDER}/normalize.cpp.o : ${DEPEND_FOLDER}/normalize.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,66%${COMMA} compiling object ../mod1_algorithm/terrain/normalize.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/normalize.cpp.o -MF ${DEPEND_FOLDER}/normalize.cpp.d -c ../mod1_algorithm/terrain/normalize.cpp -o ${OBJECT_FOLDER}/normalize.cpp.o

${OBJECT_FOLDER}/resize.cpp.o : ${DEPEND_FOLDER}/resize.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,67%${COMMA} compiling object ../mod1_algorithm/terrain/resize.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/resize.cpp.o -MF ${DEPEND_FOLDER}/resize.cpp.d -c ../mod1_algorithm/terrain/resize.cpp -o ${OBJECT_FOLDER}/resize.cpp.o

${OBJECT_FOLDER}/find_iter.cpp.o : ${DEPEND_FOLDER}/find_iter.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,68%${COMMA} compiling object ../mod1_algorithm/terrain/find_iter.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/find_iter.cpp.o -MF ${DEPEND_FOLDER}/find_iter.cpp.d -c ../mod1_algorithm/terrain/find_iter.cpp -o ${OBJECT_FOLDER}/find_iter.cpp.o

${OBJECT_FOLDER}/interpolate_x.cpp.o : ${DEPEND_FOLDER}/interpolate_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,69%${COMMA} compiling object ../mod1_algorithm/terrain/interpolate_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/interpolate_x.cpp.o -MF ${DEPEND_FOLDER}/interpolate_x.cpp.d -c ../mod1_algorithm/terrain/interpolate_x.cpp -o ${OBJECT_FOLDER}/interpolate_x.cpp.o

${OBJECT_FOLDER}/model_1.cpp.o : ${DEPEND_FOLDER}/model_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,70%${COMMA} compiling object ../mod1_algorithm/terrain/model.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/model_1.cpp.o -MF ${DEPEND_FOLDER}/model_1.cpp.d -c ../mod1_algorithm/terrain/model.cpp -o ${OBJECT_FOLDER}/model_1.cpp.o

${OBJECT_FOLDER}/x_noise.cpp.o : ${DEPEND_FOLDER}/x_noise.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,71%${COMMA} compiling object ../mod1_algorithm/terrain/x_noise.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_noise.cpp.o -MF ${DEPEND_FOLDER}/x_noise.cpp.d -c ../mod1_algorithm/terrain/x_noise.cpp -o ${OBJECT_FOLDER}/x_noise.cpp.o

${OBJECT_FOLDER}/x_color.cpp.o : ${DEPEND_FOLDER}/x_color.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,72%${COMMA} compiling object ../mod1_algorithm/terrain/x_color.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_color.cpp.o -MF ${DEPEND_FOLDER}/x_color.cpp.d -c ../mod1_algorithm/terrain/x_color.cpp -o ${OBJECT_FOLDER}/x_color.cpp.o

${OBJECT_FOLDER}/check_file_extension.cpp.o : ${DEPEND_FOLDER}/check_file_extension.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,73%${COMMA} compiling object ../mod1_algorithm/terrain/check_file_extension.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/check_file_extension.cpp.o -MF ${DEPEND_FOLDER}/check_file_extension.cpp.d -c ../mod1_algorithm/terrain/check_file_extension.cpp -o ${OBJECT_FOLDER}/check_file_extension.cpp.o

${OBJECT_FOLDER}/water.cpp.o : ${DEPEND_FOLDER}/water.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,75%${COMMA} compiling object ../mod1_algorithm/water/water.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/water.cpp.o -MF ${DEPEND_FOLDER}/water.cpp.d -c ../mod1_algorithm/water/water.cpp -o ${OBJECT_FOLDER}/water.cpp.o

${OBJECT_FOLDER}/build_1.cpp.o : ${DEPEND_FOLDER}/build_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,76%${COMMA} compiling object ../mod1_algorithm/water/build.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/build_1.cpp.o -MF ${DEPEND_FOLDER}/build_1.cpp.d -c ../mod1_algorithm/water/build.cpp -o ${OBJECT_FOLDER}/build_1.cpp.o

${OBJECT_FOLDER}/model_2.cpp.o : ${DEPEND_FOLDER}/model_2.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,77%${COMMA} compiling object ../mod1_algorithm/water/model.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/model_2.cpp.o -MF ${DEPEND_FOLDER}/model_2.cpp.d -c ../mod1_algorithm/water/model.cpp -o ${OBJECT_FOLDER}/model_2.cpp.o

${OBJECT_FOLDER}/x_x_height.cpp.o : ${DEPEND_FOLDER}/x_x_height.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,78%${COMMA} compiling object ../mod1_algorithm/water/x_x_height.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_x_height.cpp.o -MF ${DEPEND_FOLDER}/x_x_height.cpp.d -c ../mod1_algorithm/water/x_x_height.cpp -o ${OBJECT_FOLDER}/x_x_height.cpp.o

${OBJECT_FOLDER}/x_water_depth.cpp.o : ${DEPEND_FOLDER}/x_water_depth.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,79%${COMMA} compiling object ../mod1_algorithm/water/x_water_depth.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_water_depth.cpp.o -MF ${DEPEND_FOLDER}/x_water_depth.cpp.d -c ../mod1_algorithm/water/x_water_depth.cpp -o ${OBJECT_FOLDER}/x_water_depth.cpp.o

${OBJECT_FOLDER}/update_x.cpp.o : ${DEPEND_FOLDER}/update_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,80%${COMMA} compiling object ../mod1_algorithm/water/update_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/update_x.cpp.o -MF ${DEPEND_FOLDER}/update_x.cpp.d -c ../mod1_algorithm/water/update_x.cpp -o ${OBJECT_FOLDER}/update_x.cpp.o

${OBJECT_FOLDER}/gravity_x.cpp.o : ${DEPEND_FOLDER}/gravity_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,81%${COMMA} compiling object ../mod1_algorithm/water/gravity_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/gravity_x.cpp.o -MF ${DEPEND_FOLDER}/gravity_x.cpp.d -c ../mod1_algorithm/water/gravity_x.cpp -o ${OBJECT_FOLDER}/gravity_x.cpp.o

${OBJECT_FOLDER}/data_x.cpp.o : ${DEPEND_FOLDER}/data_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,82%${COMMA} compiling object ../mod1_algorithm/water/data_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/data_x.cpp.o -MF ${DEPEND_FOLDER}/data_x.cpp.d -c ../mod1_algorithm/water/data_x.cpp -o ${OBJECT_FOLDER}/data_x.cpp.o

${OBJECT_FOLDER}/cl_build.cpp.o : ${DEPEND_FOLDER}/cl_build.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,83%${COMMA} compiling object ../mod1_algorithm/water/cl_build.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/cl_build.cpp.o -MF ${DEPEND_FOLDER}/cl_build.cpp.d -c ../mod1_algorithm/water/cl_build.cpp -o ${OBJECT_FOLDER}/cl_build.cpp.o

${OBJECT_FOLDER}/cl_set_x.cpp.o : ${DEPEND_FOLDER}/cl_set_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,84%${COMMA} compiling object ../mod1_algorithm/water/cl_set_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/cl_set_x.cpp.o -MF ${DEPEND_FOLDER}/cl_set_x.cpp.d -c ../mod1_algorithm/water/cl_set_x.cpp -o ${OBJECT_FOLDER}/cl_set_x.cpp.o

${OBJECT_FOLDER}/cl_link_x.cpp.o : ${DEPEND_FOLDER}/cl_link_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,85%${COMMA} compiling object ../mod1_algorithm/water/cl_link_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/cl_link_x.cpp.o -MF ${DEPEND_FOLDER}/cl_link_x.cpp.d -c ../mod1_algorithm/water/cl_link_x.cpp -o ${OBJECT_FOLDER}/cl_link_x.cpp.o

${OBJECT_FOLDER}/cl_write.cpp.o : ${DEPEND_FOLDER}/cl_write.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,86%${COMMA} compiling object ../mod1_algorithm/water/cl_write.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/cl_write.cpp.o -MF ${DEPEND_FOLDER}/cl_write.cpp.d -c ../mod1_algorithm/water/cl_write.cpp -o ${OBJECT_FOLDER}/cl_write.cpp.o

${OBJECT_FOLDER}/x_color_1.cpp.o : ${DEPEND_FOLDER}/x_color_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,88%${COMMA} compiling object ../mod1_algorithm/water/x_color.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_color_1.cpp.o -MF ${DEPEND_FOLDER}/x_color_1.cpp.d -c ../mod1_algorithm/water/x_color.cpp -o ${OBJECT_FOLDER}/x_color_1.cpp.o

${OBJECT_FOLDER}/x_alpha.cpp.o : ${DEPEND_FOLDER}/x_alpha.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,89%${COMMA} compiling object ../mod1_algorithm/water/x_alpha.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/x_alpha.cpp.o -MF ${DEPEND_FOLDER}/x_alpha.cpp.d -c ../mod1_algorithm/water/x_alpha.cpp -o ${OBJECT_FOLDER}/x_alpha.cpp.o

${OBJECT_FOLDER}/blur.cpp.o : ${DEPEND_FOLDER}/blur.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,90%${COMMA} compiling object ../mod1_general/blur/blur.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/blur.cpp.o -MF ${DEPEND_FOLDER}/blur.cpp.d -c ../mod1_general/blur/blur.cpp -o ${OBJECT_FOLDER}/blur.cpp.o

${OBJECT_FOLDER}/general.cpp.o : ${DEPEND_FOLDER}/general.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,91%${COMMA} compiling object ../mod1_general/general/general.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/general.cpp.o -MF ${DEPEND_FOLDER}/general.cpp.d -c ../mod1_general/general/general.cpp -o ${OBJECT_FOLDER}/general.cpp.o

${OBJECT_FOLDER}/render_1.cpp.o : ${DEPEND_FOLDER}/render_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,92%${COMMA} compiling object ../mod1_general/general/render.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/render_1.cpp.o -MF ${DEPEND_FOLDER}/render_1.cpp.d -c ../mod1_general/general/render.cpp -o ${OBJECT_FOLDER}/render_1.cpp.o

${OBJECT_FOLDER}/functor_x_1.cpp.o : ${DEPEND_FOLDER}/functor_x_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,93%${COMMA} compiling object ../mod1_general/general/functor_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/functor_x_1.cpp.o -MF ${DEPEND_FOLDER}/functor_x_1.cpp.d -c ../mod1_general/general/functor_x.cpp -o ${OBJECT_FOLDER}/functor_x_1.cpp.o

${OBJECT_FOLDER}/scenario_x.cpp.o : ${DEPEND_FOLDER}/scenario_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,94%${COMMA} compiling object ../mod1_general/general/scenario_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/scenario_x.cpp.o -MF ${DEPEND_FOLDER}/scenario_x.cpp.d -c ../mod1_general/general/scenario_x.cpp -o ${OBJECT_FOLDER}/scenario_x.cpp.o

${OBJECT_FOLDER}/program_2.cpp.o : ${DEPEND_FOLDER}/program_2.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,95%${COMMA} compiling object ../mod1_general/general/program.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/program_2.cpp.o -MF ${DEPEND_FOLDER}/program_2.cpp.d -c ../mod1_general/general/program.cpp -o ${OBJECT_FOLDER}/program_2.cpp.o

${OBJECT_FOLDER}/build_2.cpp.o : ${DEPEND_FOLDER}/build_2.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,96%${COMMA} compiling object ../mod1_general/general/build.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/build_2.cpp.o -MF ${DEPEND_FOLDER}/build_2.cpp.d -c ../mod1_general/general/build.cpp -o ${OBJECT_FOLDER}/build_2.cpp.o

${OBJECT_FOLDER}/script_x.cpp.o : ${DEPEND_FOLDER}/script_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,97%${COMMA} compiling object ../mod1_general/general/script_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/script_x.cpp.o -MF ${DEPEND_FOLDER}/script_x.cpp.d -c ../mod1_general/general/script_x.cpp -o ${OBJECT_FOLDER}/script_x.cpp.o

${OBJECT_FOLDER}/hint_x.cpp.o : ${DEPEND_FOLDER}/hint_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,98%${COMMA} compiling object ../mod1_general/general/hint_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/hint_x.cpp.o -MF ${DEPEND_FOLDER}/hint_x.cpp.d -c ../mod1_general/general/hint_x.cpp -o ${OBJECT_FOLDER}/hint_x.cpp.o

${OBJECT_FOLDER}/main.cpp.o : ${DEPEND_FOLDER}/main.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,100%${COMMA} compiling object ../mod1_general/main.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG} -MMD -MP -MT ${OBJECT_FOLDER}/main.cpp.o -MF ${DEPEND_FOLDER}/main.cpp.d -c ../mod1_general/main.cpp -o ${OBJECT_FOLDER}/main.cpp.o
	

#						DEPENDENCIES

${DEPEND_FOLDER} :
	${call INFO,Creating dependencies' folder}
	@mkdir ${DEPEND_FOLDER}
	
${DEPEND} :

include ${wildcard ${DEPEND}}	
