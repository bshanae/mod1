#include "blur.h"

					blur::square::square()
{
	blur::square::build();
	blur::square::load();
}

void 				blur::square::build()
{

	float			vertices[] = {
		-1, -1, 0,
		-1, +1, 0,
		+1, -1, 0,
		+1, +1, 0
	};

	float			texture[] = {
		0, 0,
		0, 1,
		1, 0,
		1, 1
	};

	int				indices[] =
	{
		2, 1, 0,
		2, 3, 1
	};

	buffer_point.allocate(3 * 4);
	buffer_point.copy(vertices);

	buffer_index.allocate(3 * 2);
	buffer_index.copy(indices);

	buffer_texture.allocate(2 * 4);
	buffer_texture.copy(texture);

	set_as_built();
}

					blur::program::program()
{
	add_shader(mod1_engine_gl::shader_type::vertex, MOD1_GENERAL_PROGRAM_BLUR_VERTEX);
	add_shader(mod1_engine_gl::shader_type::fragment, MOD1_GENERAL_PROGRAM_BLUR_FRAGMENT);
	link();

	MOD1_CONNECT_UNIFORM(*this, texture)
}