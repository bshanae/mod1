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
}
