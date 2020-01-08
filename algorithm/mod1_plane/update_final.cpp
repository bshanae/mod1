#include "mod1_plane.h"

void 					mod1_plane::update_final()
{
	mod1_point2<int>	iter;
	float				*ptr;
	mod1_point3<float>	point;


	final_min = mod1_point3<float>(std::numeric_limits<float>::max());
	final_max = mod1_point3<float>(std::numeric_limits<float>::min());
	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			point = mod1_point3<float>(ptr[0], ptr[2], ptr[1]);
			final_min = mod1_point3<float>::min(final_min, point);
			final_max = mod1_point3<float>::max(final_max, point);
		}
}