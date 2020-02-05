#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::build()
{
	prepare();
	normalize();
	resize();

	set(point2<float>(), point2<float>(MOD1_TERRAIN_SIZE), MOD1_TERRAIN_DELTA);
	plane::build();

	noise_generator.SetNoiseType(FastNoise::Perlin);

#if MOD1_ENABLED(MOD1_TERRAIN_HILLS)
	for (auto const &point : data_raw)
		if (point.z < 0)
			generate_hill(point);

	for (auto const &point : data_raw)
		if (point.z > 0)
			generate_hill(point);
#endif



#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_A)
	apply_noise(
		MOD1_TERRAIN_NOISE_A_FREQUENCY,
		MOD1_TERRAIN_NOISE_A_RANGE,
		MOD1_TERRAIN_NOISE_A_OFFSET,
		2.5);
#endif

#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_B)
	apply_noise(
		MOD1_TERRAIN_NOISE_B_FREQUENCY,
		MOD1_TERRAIN_NOISE_B_RANGE,
		MOD1_TERRAIN_NOISE_B_OFFSET);
#endif

	update_final();
	update_normal();
	update_color();
}