#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/font/font.h"

class					mod1_gui::button
{
public :

						button(
							const point2<int> &center,
							const std::string &text,
							const font *font,
							functor_ptr functor,
							void *ptr);
						~button() = default;

	void				test(const mod1_engine_gl::event &event);

	void				activate();
	void				deactivate();

private :

MOD1_GENERATE_INTERNAL(point2<int>, center)
MOD1_GENERATE_INTERNAL(point2<int>, size)
MOD1_GENERATE_INTERNAL(std::string, text)
MOD1_GENERATE_INTERNAL(callback, callback)
MOD1_GENERATE_INTERNAL(const font *, font)
MOD1_GENERATE_INTERNAL_WITH_VALUE(bool, is_active, false)

	point2<int>			min;
	point2<int>			max;
	bool 				is_inside(const point2<int> &point) const;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(center)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(text)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(callback)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(font)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(is_active)
};


