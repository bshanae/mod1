#include "renderer.h"

using namespace			mod1_engine_gl;

void 					renderer::request_render(const bool &task)
{
	render_request = task;
}