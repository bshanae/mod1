#pragma once

#include "mod1_gui/namespace.h"

class					mod1_gui::button
{
public :

						button(
							const point2<int> &center,
							const point2<int> &size,
							const std::string &text,
							functor_ptr functor,
							void *ptr);
						~button() = default;

	void				test(const mod1_engine_gl::event &event) const;

private :

MOD1_GENERATE_INTERNAL(const point2<int>, center)
MOD1_GENERATE_INTERNAL(const point2<int>, size)
MOD1_GENERATE_INTERNAL(const std::string, text)
MOD1_GENERATE_INTERNAL(const callback, callback)

	point2<int>			min;
	point2<int>			max;

	bool 				is_inside(const point2<int> &point) const;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(center)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(text)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(callback)
};


