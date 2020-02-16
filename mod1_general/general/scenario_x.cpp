#include "general.h"

void				general::scenario_wave(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->water_data.set(0);

#define	HEIGHT		100
#define WIDTH		10

	point2<int>		iter;

	for (iter.y = 0; iter.y < general->MOD1_INTERNAL(water)->data_size.y; iter.y++)
		for (iter.x = 0; iter.x < WIDTH; iter.x++)
			general->MOD1_INTERNAL(water)->write_water_depth(iter, HEIGHT);

	general->MOD1_INTERNAL(water)->cl_arg_water_data.write();

	general->render_block(false);

	std::cerr << "Wave" << std::endl;
}