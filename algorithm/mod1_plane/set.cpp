#include "mod1_plane.h"

void					mod1_plane::set(
						const mod1_point2<float> &min,
						const mod1_point2<float> &max,
						const float &delta)
{
	this->size_internal = (max - min) / delta;
	this->real_size_internal = MOD1_PLANE_REAL_SIZE(this->size_internal);
	this->min_internal = min;
	this->max_internal = max;
	this->delta_internal = delta;

	is_set = true;
}
