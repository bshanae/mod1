#include "system.h"

					mod1_gui::system::square::square()
{
	set_as_dynamic();
	mod1_gui::system::square::build();
}

void				mod1_gui::system::square::build()
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
		+1, 0,
		+1, +1
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

	load();
}