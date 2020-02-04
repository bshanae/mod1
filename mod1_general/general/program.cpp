#include "general.h"

					general::program::program()
{
	add_shader(mod1_engine_gl::shader_type::vertex, MOD1_PROGRAM_MAIN_VERTEX);
	add_shader(mod1_engine_gl::shader_type::fragment, MOD1_PROGRAM_MAIN_FRAGMENT);
	link();

	MOD1_CONNECT_UNIFORM(*this, object_transformation)
	MOD1_CONNECT_UNIFORM(*this, camera_view)
	MOD1_CONNECT_UNIFORM(*this, camera_projection)
	MOD1_CONNECT_UNIFORM(*this, light_ambient_intensity)
	MOD1_CONNECT_UNIFORM(*this, light_direct_direction)
	MOD1_CONNECT_UNIFORM(*this, light_direct_intensity)
}