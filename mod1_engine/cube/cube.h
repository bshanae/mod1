#pragma once

#include "mod1_main/mod1_control.h"

#include "mod1_engine/model/model.h"

class				cube : private mod1_engine::model
{
public :

					cube() = default;
					~cube() = default;

	void			build() final;
	model		*model();
	using			model::transformation;
};


