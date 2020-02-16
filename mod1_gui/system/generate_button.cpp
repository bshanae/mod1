#include "system.h"

using namespace			mod1_gui;

const button 			*system::generate_button(
						const int &center_x,
						const int &center_y,
						const std::string &text,
						functor_ptr functor,
						void *ptr)
{
	return (generate_button(
		point2<int>(center_x, center_y),
		text,
		functor,
		ptr));
}

const button			*system::generate_button(
						const point2<int> &center,
						const std::string &text,
						functor_ptr functor,
						void *ptr)
{
	point2<int>			size;

	for (const char &iter : text)
	{
		size.x += symbol_map[iter]->advance();
		size.y = MOD1_MAX(size.y, symbol_map[iter]->size().y);
	}
	button_vector.push_back(new button(center, size, text, functor, ptr));
	return (button_vector.back());
}