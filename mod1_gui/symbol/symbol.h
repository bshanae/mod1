#pragma once

#include "mod1_gui/namespace.h"

class				mod1_gui::symbol
{
public :

					symbol();
					~symbol();

private :

	texture			*texture = nullptr;
	glm::ivec2		size;
	glm::ivec2		bearing;
	int				advance;
};


