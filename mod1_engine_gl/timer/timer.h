#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/callback/callback.h"

class				mod1_engine_gl::timer
{
public :

					timer(const double &period, functor_ptr functor, void *ptr);
					~timer() = default;

	void			test(const double &current_timestamp);
	void			block(const bool &state);

private :

	const double	period;
	callback		callback;
	double			last_timestamp = 0;
};