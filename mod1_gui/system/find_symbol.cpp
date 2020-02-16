#include "system.h"

using namespace		mod1_gui;

mod1_gui::symbol	*system::find_symbol(const char &task)
{
	auto			result = symbol_map.find(task);

	if (result == symbol_map.end())
		throw (exception_symbol());
	return (result->second);
}