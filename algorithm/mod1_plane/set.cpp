#include "mod1_plane.h"

void					mod1_plane::set(
						const mod1_point2<float> &min,
						const mod1_point2<float> &max,
						const float &delta)
{
	is_set = true;
	this->size = (max - min) / delta;
	this->min = min;
	this->max = max;
	this->delta = delta;
}
