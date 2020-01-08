#include "mod1_water.h"



void 					mod1_water::build()
{
	set_as_dynamic();

	set(
		terrain->min - mod1_point2<float>(terrain->delta / 2),
		terrain->max + mod1_point2<float>(terrain->delta / 2),
		terrain->delta);
	mod1_plane::build();

	flow_constant = MOD1_WATER_CONST_A * MOD1_WATER_CONST_g * (1.f / terrain->delta) * MOD1_WATER_CONST_dt;
	water_depth_constant = MOD1_WATER_CONST_dt / (terrain->delta * terrain->delta);

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			ptr[1] = -10;
		}

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			ptr[0] = 0;
			ptr[1] = 0;
			ptr[2] = 1;
		}

	water_depth_copy.allocate(size.x, size.y);
	water_depth.allocate(size.x, size.y);
	water_depth.set(0);

	flow_horizontal.allocate(size.x - 1, size.y);
	flow_horizontal.set(0);

	flow_vertical.allocate(size.x, size.y - 1);
	flow_vertical.set(0);

	update_model();
	update_color();
}
