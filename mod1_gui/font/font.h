#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/symbol/symbol.h"

class									mod1_gui::font
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_library, "Mod1 GUI, Font : Can't initialize FreeType library")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_font, "Mod1 GUI, Font : Can't create font")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol_build, "Mod1 GUI, Font : Can't build symbol")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol_search, "Mod1 GUI, System : Symbol not found")


	explicit							font(const std::string &source, const int &width, const point3<float> &color);
	explicit							font(const std::string &source, const int &width, const point3<int> &color);
										~font();

	const symbol						*find_symbol(const char &task) const;

private :

	FT_Library							library;
	FT_Face								face;
	std::map<char, mod1_gui::symbol *>	map;

MOD1_GENERATE_INTERNAL(const point3<float>, color)

	symbol								*build_symbol(const char &task);

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(color)
};


