#include "core.h"

using namespace		mod1_engine_gl;

callback			*core::add_callback(
					const event_type &type,
					functor_ptr_event functor,
					void *ptr)
{
	callback_map[type].push_back(new callback(functor, ptr));
	return (callback_map[type].back());
}