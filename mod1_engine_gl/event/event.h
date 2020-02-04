#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point2.h"

enum class				mod1_engine_gl::event_type
{
	none,
	press,
	release,
	mouse
};

class					mod1_engine_gl::event
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_type, "Mod1 Engine GL, Event : Can't read event, incorrect request type")

						event() = default;
						~event() = default;

	void				set(const int &key, const int &code, const int &action, const int &mode);

	const event_type	&read_type() const;

	const int			&read_key() const;
	const point2<int>	&read_mouse() const;

private :

	event_type			type = event_type::none;
	int 				key = 0;
	point2<int> 		mouse;
};


