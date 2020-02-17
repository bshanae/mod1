#include "general.h"

void				general::functor_key(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	const int 		key = event.read_key();

	if (key == GLFW_KEY_ESCAPE && general->gui_level == level::render)
		general->render_block(true);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_a)
		general->render_block(false);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_b)
		general->run_gui_front();
}

void				general::functor_rotate_start(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	float			angle;

	angle = -1 * (event.read_diff().x / (float)general->window_width()) * general->rotation_speed;
	general->rotation = glm::rotate(general->rotation, glm::radians(angle), general->rotation_axis);

	general->request_render();
	general->timer_gravity->block(true);
}

void				general::functor_rotate_finish(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;

	general->request_render();
	general->timer_gravity->block(false);
}

//					WATER

void				general::functor_gravity(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->gravity();
	general->request_render();
}

void				general::functor_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;
	point2<int>		point;

	point.x = general->distribution_water_x(general->generator);
	point.x = general->distribution_water_y(general->generator);
}



//					GUI

void				general::functor_continue(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->render_block(false);
}

void				general::functor_scenarios(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->run_blur();
	general->run_gui_scenarios();
}

void				general::functor_exit(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->finish();
}