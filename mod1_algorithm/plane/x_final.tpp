#pragma once

using namespace		mod1_algorithm;

template			<typename color_type>
void 				plane<color_type>::update_final()
{
	point2<int>		iter;
	point3<float>	point;

	MOD1_INTERNAL(final_min) = point3<float>(std::numeric_limits<float>::max());
	MOD1_INTERNAL(final_max) = point3<float>(std::numeric_limits<float>::min());
	for (iter.y = 0; iter.y < MOD1_INTERNAL(size).y - 1; iter.y++)
		for (iter.x = 0; iter.x < MOD1_INTERNAL(size).x - 1; iter.x++)
		{
			point = read_point(iter);
			MOD1_INTERNAL(final_min) = point3<float>::min(MOD1_INTERNAL(final_min), point);
			MOD1_INTERNAL(final_max) = point3<float>::max(MOD1_INTERNAL(final_max), point);
		}
}