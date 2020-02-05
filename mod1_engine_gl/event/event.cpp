#include "event.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(event, exception_type)

void				event::reset()
{
	type = event_type::none;
	key = 0;
}

const event_type	&event::read_type() const
{
	return (type);
}

const int			&event::read_key() const
{
	if (type < event_type::key_press and type > event_type::key_hold)
		throw (exception_type());

	return (key);
}

const point2<int>	&event::read_mouse() const
{
	return (mouse);
}

const point2<int>	&event::read_diff() const
{
	if (type != event_type::mouse_drag)
		throw (exception_type());

	return (mouse_diff);
}
