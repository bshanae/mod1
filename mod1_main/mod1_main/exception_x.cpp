#include "mod1_main.h"

const char			*mod1_main::exception_invalid_arguments::what() const noexcept
{
	return ("Mod1 Main : Invalid number of arguments");
}