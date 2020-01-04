#include "mod1_terrain.h"

void					mod1_terrain::apply_noise(const float &frequency, const float &range, const float &power)
{

	mod1_point2<int>	iter;
	float				*ptr;
	FastNoise			noise;
	float				value;

	noise.SetNoiseType(FastNoise::Perlin);

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			value = noise.GetNoise(ptr[0] * frequency, ptr[2] * frequency);
			value *= range;
			value = pow(abs(value), power) * (value > 0 ? 1.f : -1.f);
			ptr[1] += value;
		}
}