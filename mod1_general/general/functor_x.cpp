#include "general.h"

void				general::functor_key(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;

	if (event.read_key() == GLFW_KEY_ESCAPE)
	{
		general->timer->block(true);
		general->render_blur();
		general->render_gui();
	}
	else if (event.read_key() == GLFW_KEY_5)
	{
		general->timer->block(false);
	}
	else if (event.read_key() == GLFW_KEY_7)
		general->stop();
}

void				general::functor_drag(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	float			angle;

	angle = -1 * (event.read_diff().x / (float)general->window_width()) * general->rotation_speed;
	general->rotation = glm::rotate(general->rotation, glm::radians(angle), general->rotation_axis);

	general->render();
}

void				general::functor_timer(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->gravity();
	general->render();
}

void				general::functor_stop(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->stop();
}