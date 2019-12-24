#include "mod1_map.h"

float				mod1_map::model_interpolate_linear(int min, int max, float ratio)
{
	return ((float)min + ratio * (float)(max - min));
}

float				mod1_map::model_interpolate_cosine(int min, int max, float ratio)
{
	return (model_interpolate_linear(min, max, -cosf(M_PI * ratio) / 2 + 0.5f));
}

float				mod1_map::model_interpolate_smooth(int min, int max, float ratio)
{
	return (model_interpolate_linear(min, max, ratio * ratio  * (3.f - 2.f * ratio)));
}