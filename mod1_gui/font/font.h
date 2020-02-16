#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/symbol/symbol.h"


class									mod1_gui::font
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_library, "Mod1 GUI, Font : Can't initialize Freetype library")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_font, "Mod1 GUI, Font : Can't create font")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol_build, "Mod1 GUI, Font : Can't build symbol")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol_search, "Mod1 GUI, System : Symbol not found")


										font(const std::string &source, const int &width);
										~font();

	const symbol						*find_symbol(const char &task) const;

private :

	FT_Library							library;
	FT_Face								face;
	std::map<char, mod1_gui::symbol *>	map;

	symbol								*build_symbol(const char &task);
};


