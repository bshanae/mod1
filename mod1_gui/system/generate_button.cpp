#include "system.h"

using namespace			mod1_gui;

const button 			*system::generate_button(
						const int &center_x,
						const int &center_y,
						const std::string &text,
						const font *font,
						functor_ptr functor,
						void *ptr)
{
	return (generate_button(
		point2<int>(center_x, center_y),
		text,
		font,
		functor,
		ptr));
}

const button			*system::generate_button(
						const point2<int> &center,
						const std::string &text,
						const font *font,
						functor_ptr functor,
						void *ptr)
{
	button_vector.push_back(new button(center, text, font, functor, ptr));
	return (button_vector.back());
}