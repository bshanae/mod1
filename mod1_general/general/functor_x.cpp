#include "general.h"

void				general::functor_key(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	const int 		key = event.read_key();

	if (key == GLFW_KEY_ESCAPE && general->gui_level == level::render)
		general->script_esc(true);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_a)
		general->script_esc(false);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_b)
		general->script_gui_front();
}

void				general::functor_rotate_start(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	float			angle;

	angle = -1 * (event.read_diff().x / (float)general->window_width()) * general->rotation_speed;
	general->rotation = glm::rotate(general->rotation, glm::radians(angle), general->rotation_axis);

	if (general->hint_drag)
		general->hint_mod = false;

	general->request_render();
	general->timer_gravity->block(true);
	if (general->timer_scenario)
		general->timer_scenario->block(true);
}

void				general::functor_rotate_finish(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->request_render();
	general->timer_gravity->block(false);
	if (general->timer_scenario)
		general->timer_scenario->block(false);
}

void 				general::functor_default_render(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->request_render();
}

//					GUI

void				general::functor_continue(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->script_esc(false);
}

void				general::functor_scenarios(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->script_blur();
	general->script_gui_scenarios();
}

void				general::functor_light_control(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->callback_light_a->block(false);
	general->callback_light_b->block(false);

	general->hint_init(
		general->window_width() / 2, general->window_height() * 8 / 10,
		"Use W/A/S/D keys to control light direction", general->font_gill_sans, 4);
	general->hint_light = true;
	general->script_esc(false);
}

void				general::functor_exit(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->finish();
}

//					LIGHT

void				general::functor_light_rotate(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	const int 		key = event.read_key();

	if (key == GLFW_KEY_J)
		general->camera.rotate(general->light.direct_direction, mod1_engine_gl::axis::y, mod1_engine_gl::sign::positive);
	else if (key == GLFW_KEY_L)
		general->camera.rotate(general->light.direct_direction, mod1_engine_gl::axis::y, mod1_engine_gl::sign::negative);
	else if (key == GLFW_KEY_I)
		general->camera.rotate(general->light.direct_direction, mod1_engine_gl::axis::x, mod1_engine_gl::sign::positive);
	else if (key == GLFW_KEY_K)
		general->camera.rotate(general->light.direct_direction, mod1_engine_gl::axis::x, mod1_engine_gl::sign::negative);
	else
		return ;

	if (general->hint_light)
		general->hint_mod = false;

	general->request_render();
}


//					WATER

void				general::functor_gravity(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);

	water->gravity();
	general->request_render();
}

void				general::functor_well(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);

	point2<int>		iter;

	for (iter.y = 0; iter.y < MOD1_GENERAL_WELL_SIZE.y; iter.y++)
		for (iter.x = 0; iter.x < MOD1_GENERAL_WELL_SIZE.x; iter.x++)
			water->increment_water_depth(general->well_position + iter, MOD1_GENERAL_WELL_VOLUME);

	water->update_data();
}

void				general::functor_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);
	point2<int>		point;

	point.x = general->rain_distribution_x(general->generator);
	point.y = general->rain_distribution_y(general->generator);

	water->increment_water_depth(point, MOD1_GENERAL_RAINDROP_VOLUME);

	water->update_data();
}

void				general::functor_flood(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);
	point2<int>		iter;

	general->flood_level += 0.1;

	for (iter.y = 0; iter.y < water->size().y; iter.y++)
		for (iter.x = 0; iter.x < water->size().x; iter.x++)
			if (water->read_total_height(iter) < general->flood_level)
				water->write_water_depth(iter,  general->flood_level - water->read_terrain_height(iter));

	water->update_data();
	water->update_model(true);
}

