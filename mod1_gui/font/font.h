#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/symbol/symbol.h"

#include <map>

class									mod1_gui::font
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_library, "Mod1 GUI, Font : Can't initialize Freetype library")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_font, "Mod1 GUI, Font : Can't create font")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol, "Mod1 GUI, Font : Can't create symbol")

	explicit							font(const std::string &source, const int &width);
										~font();

	void								write(const std::string &text);

private :

	FT_Library							library;
	FT_Face								face;

	std::map<char, mod1_gui::symbol *>	symbol_map;

	symbol								*generate_symbol(const char &task);

};


