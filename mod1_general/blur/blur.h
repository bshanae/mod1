#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"

class				blur
{
public :

					blur() = default;
					~blur() = default;

	class			square : public mod1_engine_gl::model
	{
	public :
					square();

		void		build() override;
	}				square;

	class			program : public mod1_engine_gl::program
	{
	public :
					program();

	MOD1_GENERATE_UNIFORM(texture, "uniform_texture")
	}				program;
};


