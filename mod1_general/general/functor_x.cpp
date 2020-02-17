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
	if (general->timer_scenario)
		general->timer_scenario->block(true);
}

void				general::functor_rotate_finish(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;

	general->request_render();
	general->timer_gravity->block(false);
	if (general->timer_scenario)
		general->timer_scenario->block(false);
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
	point.y = general->distribution_water_y(general->generator);

	point2<int>		neighbors[] =
	{
		point2<int>(0, 0),
		point2<int>(1, 0),
		point2<int>(0, 1),
		point2<int>(1, 1)
	};

	for (auto neighbor : neighbors)
		general->MOD1_INTERNAL(water)->increment_water_depth(point + neighbor, 10);

	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);

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