#include "timer.h"

using namespace		mod1_engine_gl;

					timer::timer(const double &period, functor_ptr functor, void *ptr) :
					period(period),
					callback(functor, ptr)
{}

void				timer::test(const double &current_timestamp)
{
	if (is_blocked)
		return ;
	if (current_timestamp - last_timestamp >= period)
	{
		callback.run();
		last_timestamp = current_timestamp;
	}
}

void				timer::block(const bool &state)
{
	is_blocked = state;
}