#include "mod1_terrain.h"

const char *		mod1_terrain::exception_bad_coordinate::what() const throw()
{
	return ("Mod1 Map : Bad coordinate");
}