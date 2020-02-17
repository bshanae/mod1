#include "button.h"

using namespace		mod1_gui;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, center)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, size)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, text)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, callback)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, font)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(button, is_active)

//					PUBLIC

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

bool				button::test(const mod1_engine_gl::event &event)
{
	if (MOD1_INTERNAL(is_active) and is_inside(event.read_mouse()))
		MOD1_INTERNAL(callback).run();
	else
		return (false);
	return (true);
}

void				button::activate()
{
	MOD1_INTERNAL(is_active) = true;
}

void				button::deactivate()
{
	MOD1_INTERNAL(is_active) = false;
}


//					PRIVATE

bool 				button::is_inside(const point2<int> &point) const
{
	return (point > min and point < max);
}