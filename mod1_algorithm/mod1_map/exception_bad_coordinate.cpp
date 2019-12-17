#include "mod1_map.h"

const char *		mod1_map::exception_bad_coordinate::what() const throw()
{
	return "Mod1 Map : Bad coordinate";
}