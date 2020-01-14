#include "mod1_terrain.h"

float					mod1_terrain::generate_noise(
						const mod1_point2<int> &iter,
						const float &frequency,
						const float &range,
						const mod1_point2<float> &offset,
						const float &power) const
{
	float				value;

#if MOD1_DISABLED(MOD1_TERRAIN_NOISE)
	return (0);
#else

	// todo test

	value = noise_generator.GetNoise(
		offset.x + iter.x * frequency,
		offset.y + iter.y * frequency);

	value = pow(abs(value), power) * (value > 0 ? 1.f : -1.f);
	value *= range;
	return (value);
#endif
}

void					mod1_terrain::apply_noise(
						const float &frequency,
						const float &range,
						const mod1_point2<float> &offset,
						const float &power)
{

	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
			apply_noise(iter, frequency, range, offset, power);
}

void					mod1_terrain::apply_noise(
						const mod1_point2<int> &iter,
						const float &frequency,
						const float &range,
						const mod1_point2<float> &offset,
						const float &power)
{
	write_height(iter, read_height(iter) + generate_noise(iter, frequency, range, offset, power));
}