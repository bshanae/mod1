#include "button.h"

using namespace		mod1_gui;

					button::button(
					const point2<int> &position,
					const point2<int> &size,
					const std::string &text,
					callback_functor functor,
					void *ptr) :
					position(position),
					size(size),
					text(text),
					callback(functor, ptr)
{}