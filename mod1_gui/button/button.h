#pragma once

#include "mod1_gui/namespace.h"

class				mod1_gui::button
{
public :

					button(
					const point2<int> &position,
					const point2<int> &size,
					const std::string &text,
					callback_functor functor,
					void *ptr);
					~button() = default;

private :

	const point2<int>	position;
	const point2<int>	size;
	const std::string	text;
	const callback		callback;
};


