#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/event/event.h"

class					mod1_engine_gl::callback
{
public :
						callback(callback_functor functor, void *ptr);
						~callback() = default;

	void				run(const event &event) const;

private :

	callback_functor	functor;
	void 				*ptr;
};
