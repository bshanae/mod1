#include "core.h"

using namespace		mod1_engine_gl;

void				core::add_callback(const event_type &type, callback_functor functor, void *ptr)
{
	callback_map[type].emplace_back(functor, ptr);
}