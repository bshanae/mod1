#include "event.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(event, exception_type)

void				event::set(const int &key, const int &code, const int &action, const int &mode)
{
	switch (action)
	{
		case GLFW_PRESS :
			type = event_type::press;
			break ;
		case GLFW_RELEASE :
			type = event_type::release;
			break ;
		default :
			type = event_type::none;
	}

	this->key = 0;
	mouse = point2<int>();

	if (type == event_type::press or type == event_type::release)
		this->key = key;
}

const event_type	&event::read_type() const
{
	return (type);
}

const int			&event::read_key() const
{
	if (type != event_type::press and type != event_type::release)
		throw (exception_type());

	return (key);
}

const point2<int>	&event::read_mouse() const
{
	if (type != event_type::mouse)
		throw (exception_type());

	return (mouse);
}
