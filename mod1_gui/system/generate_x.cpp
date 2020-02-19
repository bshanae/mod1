#include "system.h"

using namespace		mod1_gui;

//					LABEL

label 				*system::generate_label(
					const int &center_x,
					const int &center_y,
					const std::string &text,
					const font *font)
{
	return (generate_label(point2<int>(center_x, center_y), text, font));
}

label				*system::generate_label(
					const point2<int> &center,
					const std::string &text,
					const font *font)
{
	label_vector.push_back(new label(center, text, font));
	return (label_vector.back());
}

//					BUTTON

button 				*system::generate_button(
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

button				*system::generate_button(
					const point2<int> &center,
					const std::string &text,
					const font *font,
					functor_ptr functor,
					void *ptr)
{
	button_vector.push_back(new button(center, text, font, functor, ptr));
	return (button_vector.back());
}