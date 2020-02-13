#include "system.h"

using namespace			mod1_gui;

void 					system::add_button(
	const int &center_x,
	const int &center_y,
	const std::string &text,
	functor_ptr_event functor,
	void *ptr)
{
	add_button(point2<int>(center_x, center_y), text, functor, ptr);
}

void					system::add_button(
	const point2<int> &center,
	const std::string &text,
	functor_ptr_event functor,
	void *ptr)
{
	point2<int>			size;

	for (const char &iter : text)
	{
		size.x += symbol_map[iter]->advance();
		size.y = MOD1_MAX(size.y, symbol_map[iter]->size().y);
	}
	button_vector.emplace_back(center, size, text, functor, ptr);
}