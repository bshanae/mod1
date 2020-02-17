#include "general.h"

void				general::scenario_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->remove_timer(general->timer_scenario);
	general->timer_scenario = general->add_timer(1. / 20., functor_rain, general);

	general->MOD1_INTERNAL(water)->update_time_constant(0.1);
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}

void				general::scenario_heavy_rain(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->remove_timer(general->timer_scenario);
	general->timer_scenario = general->add_timer(1. / 160., functor_rain, general);

	general->MOD1_INTERNAL(water)->update_time_constant(0.15);
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}

void				general::scenario_wave(void *ptr)
{
	auto 			*general = (::general *)ptr;
	point2<int>		iter;

	general->MOD1_INTERNAL(water)->water_data.set(0);

	general->remove_timer(general->timer_scenario);

	for (iter.y = 0; iter.y < general->MOD1_INTERNAL(water)->data_size.y; iter.y++)
		for (iter.x = 0; iter.x < MOD1_GENERAL_WAVE_WIDTH; iter.x++)
			general->MOD1_INTERNAL(water)->write_water_depth(iter, MOD1_GENERAL_WAVE_HEIGHT);

	general->MOD1_INTERNAL(water)->update_time_constant();
	general->MOD1_INTERNAL(water)->update_data();
	general->MOD1_INTERNAL(water)->update_model(true);
	general->render_block(false);
}