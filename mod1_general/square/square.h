#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"

class				square : public mod1_engine_gl::model
{
public :

	void			build() override;

	using			model::update;

	using			model::buffer_point;
	using			model::buffer_color;
	using			model::buffer_normal;
	using			model::buffer_texture;

	using			model::set_as_dynamic;
};


