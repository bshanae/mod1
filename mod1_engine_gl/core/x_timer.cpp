#include "core.h"

using namespace		mod1_engine_gl;

timer				*core::add_timer(
					const double &period,
					functor_ptr functor,
					void *ptr)
{
	timer_vector.push_back(new timer(period, functor, ptr));
	return (timer_vector.back());
}

void 				core::test_timer()
{
	for (auto *timer : timer_vector)
		timer->test(glfwGetTime());
}