#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/symbol/symbol.h"


class									mod1_gui::font
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_library, "Mod1 GUI, Font : Can't initialize Freetype library")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_font, "Mod1 GUI, Font : Can't create font")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol, "Mod1 GUI, Font : Can't create symbol")

										font(const std::string &source, const int &width);
										~font();

	symbol								*generate_symbol(const char &task);

private :

	FT_Library							library;
	FT_Face								face;
};


