#include "terrain.h"

using namespace			mod1_algorithm;

//						GENERATE

float					terrain::generate_noise(
						const point2<int> &iter,
						const float &frequency,
						const float &range,
						const point2<float> &offset,
						const float &power) const
{
	float				value;

	value = noise_generator.GetNoise(
		offset.x + iter.x * frequency,
		offset.y + iter.y * frequency);

	value = pow(abs(value), power) * (value > 0 ? 1.f : -1.f);
	value *= range;
	return (value);
}

float					terrain::generate_noise(
						const point2<int> &iter,
						const noise_config &config)
{
	return (generate_noise(
		iter,
		config.frequency,
		config.range,
		config.offset,
		config.power));
}

//						APPLY

void					terrain::apply_noise(
						const float &frequency,
						const float &range,
						const point2<float> &offset,
						const float &power)
{

	point2<int>			iter;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
			apply_noise(iter, frequency, range, offset, power);
}

void					terrain::apply_noise(
						const point2<int> &iter,
						const float &frequency,
						const float &range,
						const point2<float> &offset,
						const float &power)
{
	write_height(iter, read_height(iter) + generate_noise(iter, frequency, range, offset, power));
}

void					terrain::apply_noise(const noise_config &config)
{

	point2<int>			iter;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
			apply_noise(iter, config);
}

void					terrain::apply_noise(
						const point2<int> &iter,
						const noise_config &config)
{
	write_height(iter, read_height(iter) + generate_noise(iter, config));
}