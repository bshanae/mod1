#include "renderer.h"

using namespace		mod1_engine;

					renderer::renderer() :
					core(),
					camera(core.window_width(), core.window_height(), MOD1_CAMERA_POSITION),
					light_info(),
					core_ptr(&core),
					program_ptr(&program),
					loader_ptr(&loader),
					camera_ptr(&camera)
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.point_position = glm::vec3(MOD1_LIGHT_POINT_POSITION);
	light_info.point_intensity = MOD1_LIGHT_POINT_INTENSITY;
	light_info.point_power = 2.;

#if MOD1_ENABLED(MOD1_LIGHT_CUBE)
	light_cube.build();
	load_model(light_cube.model());
#endif

	program.add_shader(program::vertex, MOD1_SOURCE_SHADER_VERTEX);
	program.add_shader(program::fragment, MOD1_SOURCE_SHADER_FRAGMENT);

	program.link();

	program.object_transformation.set(program.object());
	program.camera_view.set(program.object());
	program.camera_projection.set(program.object());
	program.light_ambient_intensity.set(program.object());
	program.light_point_position.set(program.object());
	program.light_point_intensity.set(program.object());
	program.light_point_power.set(program.object());
}
