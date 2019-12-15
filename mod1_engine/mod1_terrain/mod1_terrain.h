#pragma once

#include "mod1_model.h"

class				mod1_terrain : public mod1_model
{

public :

	explicit		mod1_terrain(float position_z, float size = 10, int vertex_number = 8);

					~mod1_terrain() = default;

private :

	const float 	size;
	const float		position_z;

};
