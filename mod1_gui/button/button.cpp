#include "button.h"

using namespace		mod1_gui;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, center)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, size)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, text)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, callback)

					button::button(
						const point2<int> &center,
						const point2<int> &size,
						const std::string &text,
						functor_ptr_event functor,
						void *ptr) :
					MOD1_INTERNAL(center)(center),
					MOD1_INTERNAL(size)(size),
					MOD1_INTERNAL(text)(text),
					MOD1_INTERNAL(callback)(functor, ptr)
{
	min = center - size / 2;
	max = center + size / 2;
}

void				button::test(const mod1_engine_gl::event &event) const
{
	if (is_inside(event.read_mouse()))
		MOD1_INTERNAL(callback).run(event);
}

bool 				button::is_inside(const point2<int> &point) const
{
	return (point > min and point < max);
}