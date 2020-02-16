#include "renderer.h"

using namespace		mod1_engine_gl;

void				renderer::functor_key(void *ptr, const class event &event)
{
#if MOD1_ENABLED(MOD1_DEVELOPER_MODE)
	static bool		line_mod = false;
#endif

	const int 		key = event.read_key();

	auto			renderer = (mod1_engine_gl::renderer *)ptr;

#if MOD1_ENABLED(MOD1_DEVELOPER_MODE)
	if (key == GLFW_KEY_A)
		renderer->camera.move(axis::x, sign::negative);
	else if (key == GLFW_KEY_D)
		renderer->camera.move(axis::x, sign::positive);
	else if (key == GLFW_KEY_W)
		renderer->camera.move(axis::z, sign::negative);
	else if (key == GLFW_KEY_S)
		renderer->camera.move(axis::z, sign::positive);
	else if (key == GLFW_KEY_Q)
		renderer->camera.move(axis::y, sign::positive);
	else if (key == GLFW_KEY_E)
		renderer->camera.move(axis::y, sign::negative);
	else if (key == GLFW_KEY_LEFT)
		renderer->camera.rotate(axis::y, sign::positive);
	else if (key == GLFW_KEY_RIGHT)
		renderer->camera.rotate(axis::y, sign::negative);
	else if (key == GLFW_KEY_UP)
		renderer->camera.rotate(axis::x, sign::positive);
	else if (key == GLFW_KEY_DOWN)
		renderer->camera.rotate(axis::x, sign::negative);
	else if (key == GLFW_KEY_P)
		renderer->camera.switch_projection();
	else if (key == GLFW_KEY_R)
	{
		line_mod = !line_mod;
		if (line_mod)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
#endif
	else
		return ;
	renderer->request_render();
}

void				renderer::functor_render(void *ptr)
{
	auto			renderer = (mod1_engine_gl::renderer *)ptr;

	if (renderer->render_request)
		renderer->render();
	renderer->render_request = false;
}