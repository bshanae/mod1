#pragma once

#include "mod1_model.h"

class				mod1_cube : private mod1_model
{
public :

					mod1_cube() = default;
					~mod1_cube() = default;

	void			build() final;
	mod1_model		*model();
};


