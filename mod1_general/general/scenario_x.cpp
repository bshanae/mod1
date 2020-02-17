#include "general.h"

void				general::scenario_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->remove_timer(general->timer_scenario);
	general->timer_scenario = general->add_timer(1. / 20., functor_rain, general);
	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->MOD1_INTERNAL(water)->update_time_constant(0.1);
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}

void				general::scenario_heavy_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->remove_timer(general->timer_scenario);
	general->timer_scenario = general->add_timer(1. / 160., functor_rain, general);
	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->MOD1_INTERNAL(water)->update_time_constant(0.15);
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}

void				general::scenario_well(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->remove_timer(general->timer_scenario);
	general->timer_scenario = general->add_timer(1. / 35., functor_well, general);
	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->well_position.x = general->well_distribution_x(general->generator);
	general->well_position.y = general->well_distribution_y(general->generator);

	general->MOD1_INTERNAL(water)->update_time_constant();
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}


void				general::scenario_wave(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);

	point2<int>		iter;

	general->remove_timer(general->timer_scenario);
	general->MOD1_INTERNAL(water)->water_data.set(0);

	for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
		for (iter.x = 0; iter.x < MOD1_GENERAL_BIG_WAVE_WIDTH; iter.x++)
			water->write_water_depth(iter, MOD1_GENERAL_BIG_WAVE_HEIGHT);

	general->MOD1_INTERNAL(water)->update_time_constant();
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}

void				general::scenario_4_waves(void *ptr)
{
	auto 			*general = (::general *)ptr;
	auto 			*water = general->MOD1_INTERNAL(water);

	point2<int>		iter;

	general->remove_timer(general->timer_scenario);
	general->MOD1_INTERNAL(water)->water_data.set(0);

	for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
		for (iter.x = 0; iter.x < MOD1_GENERAL_LITTLE_WAVE_WIDTH; iter.x++)
			water->write_water_depth(iter, MOD1_GENERAL_LITTLE_WAVE_HEIGHT);
	for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
		for (iter.x = water->data_size.x - MOD1_GENERAL_LITTLE_WAVE_WIDTH; iter.x < water->data_size.x; iter.x++)
			water->write_water_depth(iter, MOD1_GENERAL_LITTLE_WAVE_HEIGHT);

	for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
		for (iter.y = 0; iter.y < MOD1_GENERAL_LITTLE_WAVE_WIDTH; iter.y++)
			water->write_water_depth(iter, MOD1_GENERAL_LITTLE_WAVE_HEIGHT);
	for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
		for (iter.y = water->data_size.y - MOD1_GENERAL_LITTLE_WAVE_WIDTH; iter.y < water->data_size.y; iter.y++)
			water->write_water_depth(iter, MOD1_GENERAL_LITTLE_WAVE_HEIGHT);

	general->MOD1_INTERNAL(water)->update_time_constant();
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}