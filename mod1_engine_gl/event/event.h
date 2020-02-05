#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point2.h"

enum class				mod1_engine_gl::event_type
{
	none,
	key_press,
	key_release,
	key_hold,
	mouse_move,
	mouse_press,
	mouse_release
};

class					mod1_engine_gl::event
{
	friend class		core;

public :

						~event() = default;

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_type, "Mod1 Engine GL, Event : Can't read event, incorrect request type")

	const event_type	&read_type() const;

	const int			&read_key() const;
	const point2<int>	&read_mouse() const;

private :

	event_type			type = event_type::none;
	int 				key = 0;
	point2<int> 		mouse;

						event() = default;

	void				reset();
};


