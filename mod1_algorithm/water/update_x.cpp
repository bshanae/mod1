#include "water.h"

using namespace			mod1_algorithm;

void 					water::update_time_constant(const float &multiplier)
{
	constant_depth = MOD1_WATER_CONST_dt * multiplier / (terrain->delta() * terrain->delta());
	cl_arg_const_depth.write();
}

void 					water::update_data()
{
	cl_arg_water_data.write();
}

void					water::update_model(const bool &save)
{
	point2<int>			iter;
	float				new_height;

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
		{
			if ((new_height = read_water_depth(iter)) <= (low_volume_optimization ? 0.0001 : 0.05))//MOD1_WATER_MINIMUM)
				new_height = MOD1_WATER_HIDDEN_REAL;
			else
				new_height += read_terrain_height(iter);
			write_height(iter, new_height);
		}

	if (save)
		model::save(model_slot::point);

	update_normal(save);
	update_color(save);
}