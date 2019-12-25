#include "mod1_water.h"

						mod1_water::mod1_water(const mod1_terrain &terrain) :
						terrain(terrain)
{}

void 					mod1_water::build()
{
	//					Points

	data.point_buffer.allocate(3 * terrain.model_size.x * terrain.model_size.y);

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < terrain.model_size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain.model_size.x; iter.x++)
		{
//			ptr = model_get_ptr(iter, mod1_map_slot_point);
//			ptr[0] = (float)(terrain.model_min.x + terrain.model_delta * iter.x);
//			ptr[1] = 0;
//			ptr[2] = (float)(terrain.model_min.y + terrain.model_delta * iter.y);
//		}
}