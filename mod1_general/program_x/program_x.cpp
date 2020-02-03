#include "mod1_general/program_x/program_x.h"

					program_main::program_main() :
					program()
{
	add_shader(shader_type::vertex, MOD1_PROGRAM_MAIN_VERTEX);
	add_shader(shader_type::fragment, MOD1_PROGRAM_MAIN_FRAGMENT);
	link();

MOD1_CONNECT_UNIFORM(*this, object_transformation)
MOD1_CONNECT_UNIFORM(*this, camera_view)
MOD1_CONNECT_UNIFORM(*this, camera_projection)
MOD1_CONNECT_UNIFORM(*this, light_ambient_intensity)
MOD1_CONNECT_UNIFORM(*this, light_direct_direction)
MOD1_CONNECT_UNIFORM(*this, light_direct_intensity)
}

					program_blur::program_blur() :
					program()
{
	add_shader(shader_type::vertex, MOD1_PROGRAM_BLUR_VERTEX);
	add_shader(shader_type::fragment, MOD1_PROGRAM_BLUR_FRAGMENT);
	link();

MOD1_CONNECT_UNIFORM(*this, texture)
}

					program_text::program_text()
{
	add_shader(shader_type::vertex, MOD1_PROGRAM_TEXT_VERTEX);
	add_shader(shader_type::fragment, MOD1_PROGRAM_TEXT_FRAGMENT);
	link();

MOD1_CONNECT_UNIFORM(*this, texture)
MOD1_CONNECT_UNIFORM(*this, color)
MOD1_CONNECT_UNIFORM(*this, projection)
}