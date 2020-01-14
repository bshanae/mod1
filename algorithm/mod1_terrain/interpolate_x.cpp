#include "mod1_terrain.h"

float				mod1_terrain::interpolate_linear(float min, float max, float ratio)
{
	return ((float)min + ratio * (float)(max - min));
}

float				mod1_terrain::interpolate_cosine(float min, float max, float ratio)
{
	return (interpolate_linear(min, max, -cosf(M_PI * ratio) / 2 + 0.5f));
}

float				mod1_terrain::interpolate_smooth(float min, float max, float ratio)
{
	return (interpolate_linear(min, max, ratio * ratio * (3.f - 2.f * ratio)));
}