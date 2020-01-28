#include "plane.h"

using namespace			mod1_algorithm;

void					plane::set(
						const point2<float> &min,
						const point2<float> &max,
						const float &delta)
{
	MOD1_INTERNAL(size) = (max - min) / delta;
	MOD1_INTERNAL(real_size) = MOD1_PLANE_REAL_SIZE(MOD1_INTERNAL(size));
	MOD1_INTERNAL(min) = min;
	MOD1_INTERNAL(max) = max;
	MOD1_INTERNAL(delta) = delta;

	is_set = true;
}
