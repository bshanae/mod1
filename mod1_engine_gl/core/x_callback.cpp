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

void 				core::remove_callback(callback *callback)
{
	for (auto [key, value] : callback_map)
		for (auto iter = value.begin(); iter < value.end(); iter++)
			if (*iter == callback)
			{
				value.erase(iter);
				return ;
			}
}
