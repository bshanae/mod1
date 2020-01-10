#include "mod1_terrain.h"

void					mod1_terrain::build()
{
	prepare();

	set((mod1_point2<float>)min_i, (mod1_point2<float>)max_i, (float)delta_i);
	mod1_plane::build();

	//					Hills

	noise_generator.SetNoiseType(FastNoise::Perlin);

//	for (auto const &iter_source : data_raw)
//		generate_hill(iter_source);

#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_A)
	apply_noise(MOD1_TERRAIN_NOISE_A_FREQUENCY, MOD1_TERRAIN_NOISE_A_RANGE, 2.5);
#endif

#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_B)
	apply_noise(MOD1_TERRAIN_NOISE_B_FREQUENCY, MOD1_TERRAIN_NOISE_B_RANGE);
#endif

	update_normal();
	update_final();

	return ;

	//					Colors

	mod1_point2<int>	iter;
	float				*ptr;
	mod1_point3<float>	color;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			color = compute_color(ptr[1]);
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color, mod1_plane::convention_single);
			ptr[0] = color.x;
			ptr[1] = color.y;
			ptr[2] = color.z;
		}


}