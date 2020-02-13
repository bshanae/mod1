#include "timer.h"

using namespace		mod1_engine_gl;

					timer::timer(const double &period, functor_ptr_event functor, void *ptr) :
					period(period),
					callback(functor, ptr),
					last_timestamp(core::time())
{}

void				timer::test()
{
	double			current_timestamp = core::time();

	if (current_timestamp - last_timestamp >= period)
	{
//		callback.run()
		last_timestamp = current_timestamp;
	}
}