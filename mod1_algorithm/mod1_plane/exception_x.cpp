#include "mod1_plane.h"

const char			*mod1_plane::exception_bad_coordinate::what() const noexcept
{
	return ("Mod1 Plane : Bad coordinate");
}

const char			*mod1_plane::exception_not_set::what() const noexcept
{
	return ("Mod1 Plane : Not set");
}