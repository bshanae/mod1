#include "button.h"

using namespace		mod1_gui;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, center)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, size)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, text)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, callback)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, font)

					button::button(
					const point2<int> &center,
					const std::string &text,
					const class font *font,
					functor_ptr functor,
					void *ptr) :
					MOD1_INTERNAL(center)(center),
					MOD1_INTERNAL(text)(text),
					MOD1_INTERNAL(callback)(functor, ptr),
					MOD1_INTERNAL(font)(font)
{
	const symbol	*symbol;

	for (const char &iter : text)
	{
		symbol = font->find_symbol(iter);

		MOD1_INTERNAL(size).x += symbol->advance();
		MOD1_INTERNAL(size).y = MOD1_MAX(MOD1_INTERNAL(size).y, symbol->size().y);
	}

	min = center - MOD1_INTERNAL(size) / 2;
	max = center + MOD1_INTERNAL(size) / 2;
}

void				button::test(const mod1_engine_gl::event &event)
{
	if (is_inside(event.read_mouse()))
		MOD1_INTERNAL(callback).run();
}

bool 				button::is_inside(const point2<int> &point) const
{
	return (point > min and point < max);
}