#include "renderer.h"

using namespace			mod1_engine;

void 					renderer::loop()
{
	while(!core.is_working())
	{
		core.update();
		if (render_request)
			render_internal();
	}
}