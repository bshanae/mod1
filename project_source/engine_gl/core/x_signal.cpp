#include "core.h"

using namespace		mod1_engine_gl;

void 				core::launch_signal()
{
	global_signal_block = false;
	for (auto *callback : callback_map[event.type])
	{
		if (global_signal_block)
			break ;
		callback->run(event);
	}
	event.reset();
}