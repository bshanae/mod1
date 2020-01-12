#include "plane.h"

using namespace			mod1_algorithm;

void					plane::set(
						const point2<float> &min,
						const point2<float> &max,
						const float &delta)
{
	this->size_internal = (max - min) / delta;
	this->real_size_internal = MOD1_PLANE_REAL_SIZE(this->size_internal);
	this->min_internal = min;
	this->max_internal = max;
	this->delta_internal = delta;

	is_set = true;
}
