#pragma once

#include "mod1_gui/namespace.h"

class							mod1_gui::symbol
{
	friend class				font;

public :

								~symbol();

private :

	explicit					symbol(FT_Face &face);

MOD1_GENERATE_INTERNAL_WITH_VALUE(mod1_engine_gl::texture *, texture, nullptr)
MOD1_GENERATE_INTERNAL(mod1_engine_gl::point2<int>, size)
MOD1_GENERATE_INTERNAL(mod1_engine_gl::point2<int>, bearing)
MOD1_GENERATE_INTERNAL(int, advance)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(texture)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(bearing)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(advance)
};


