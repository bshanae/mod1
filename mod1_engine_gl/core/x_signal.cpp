#include "core.h"

using namespace		mod1_engine_gl;

void 				core::launch_signal()
{
	global_signal_block = false;
	for (auto *callback : callback_map[event.type])
	{
		callback->run(event);
		if (global_signal_block)
			break ;
	}
	event.reset();
}

void				core::terminate_signal()
{
	global_signal_block = true;
}