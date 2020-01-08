#include "mod1_terrain.h"

float					mod1_terrain::generate_noise(
						const mod1_point2<int> &iter,
						const float &frequency,
						const float &range,
						const float &power) const
{
	float				*ptr;
	float				value;

#if MOD1_DISABLED(MOD1_TERRAIN_NOISE)
	return (0);
#endif

	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	value = noise_generator.GetNoise(ptr[0] * frequency, ptr[2] * frequency);
	value = pow(abs(value), power) * (value > 0 ? 1.f : -1.f);
	value *= range;
	return (value);
}

void					mod1_terrain::apply_noise(
						const float &frequency,
						const float &range,
						const float &power)
{

	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
			apply_noise(iter, frequency, range, power);
}

void					mod1_terrain::apply_noise(
						const mod1_point2<int> &iter,
						const float &frequency,
						const float &range,
						const float &power)
{
	float				*ptr;

	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] += generate_noise(iter, frequency, range, power);
}