#include "mod1_terrain.h"

const char			*mod1_terrain::exception_source::what() const noexcept
{
	return ("Mod1 Terrain : Invalid source file");
}

const char			*mod1_terrain::exception_pattern::what() const noexcept
{
	return ("Mod1 Terrain : Invalid pattern");
}

const char			*mod1_terrain::exception_search::what() const noexcept
{
	return ("Mod1 Terrain : Can't find given point");
}

const char			*mod1_terrain::exception_color::what() const noexcept
{
	return ("Mod1 Terrain : Too few colors defined");
}