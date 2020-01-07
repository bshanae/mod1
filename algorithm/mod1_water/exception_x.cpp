#include "mod1_water.h"

const char			*mod1_water::exception_unknown_flow_type::what() const noexcept
{
	return ("Mod1 Water : Unknown flow type");
}