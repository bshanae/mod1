#include "mod1_map.h"

float				mod1_map::model_interpolate_linear(float min, float max, float ratio)
{
	return ((float)min + ratio * (float)(max - min));
}

float				mod1_map::model_interpolate_cosine(float min, float max, float ratio)
{
	return (model_interpolate_linear(min, max, -cosf(M_PI * ratio) / 2 + 0.5f));
}

float				mod1_map::model_interpolate_smooth(float min, float max, float ratio)
{
	return (model_interpolate_linear(min, max, ratio * ratio  * (3.f - 2.f * ratio)));
}