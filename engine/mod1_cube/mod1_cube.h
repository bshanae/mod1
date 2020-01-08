#pragma once

#include "mod1_preference.h"

#include "mod1_model.h"

class				mod1_cube : private mod1_model
{
public :

					mod1_cube() = default;
					~mod1_cube() = default;

	void			build() final;
	mod1_model		*model();
	using			mod1_model::transformation;
};


