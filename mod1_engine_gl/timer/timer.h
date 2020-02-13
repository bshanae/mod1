#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/callback/callback.h"

class				mod1_engine_gl::timer
{
public :

					timer(const double &period, functor_ptr_event functor, void *ptr);
					~timer() = default;

	void			test();

private :

	const double	period;
	const callback	callback;

	double			last_timestamp;

};