#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::build()
{
	prepare();
	normalize();
	resize();

	set(MOD1_TERRAIN_START, MOD1_TERRAIN_END, MOD1_TERRAIN_DELTA);
	plane::build();

	noise_generator.SetNoiseType(FastNoise::Perlin);

	for (auto const &point : data_raw)
		if (point.z < 0)
			generate_hill(point);

	for (auto const &point : data_raw)
		if (point.z > 0)
			generate_hill(point);

	for (const auto &config : noise_general)
		apply_noise(config);

	update_final();
	update_normal();
	update_color(false);
}