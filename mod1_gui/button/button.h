#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/label/label.h"

class					mod1_gui::button : public mod1_gui::label
{
public :
						button(
						const point2<int> &center,
						const std::string &text,
						const class font *font,
						functor_ptr functor,
						void *ptr);
						~button() = default;

	bool				test(const mod1_engine_gl::event &event);

	void				activate();
	void				deactivate();

private :

MOD1_GENERATE_INTERNAL(callback, callback)
MOD1_GENERATE_INTERNAL_WITH_VALUE(bool, is_active, false)

	point2<int>			min;
	point2<int>			max;
	bool 				is_inside(const point2<int> &point) const;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(callback)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(is_active)
};


