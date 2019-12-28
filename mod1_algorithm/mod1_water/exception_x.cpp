#include "mod1_water.h"

const char			*mod1_water::exception_no_water::what() const noexcept
{
	return ("Mod1 Water : Water level is 0, can't replace water");
}