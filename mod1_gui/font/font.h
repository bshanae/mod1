#pragma once

#include "mod1_gui/namespace.h"

class				mod1_gui::font
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_freetype, "Mod1 GUI, Font : Can't initialize Freetype library")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_font, "Mod1 GUI, Font : Can't create font")

	explicit		font(const std::string &source, const int &width);
					~font();

private :

	FT_Library		library;
	FT_Face			face;
};


