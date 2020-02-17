#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	MOD1_INTERNAL(ambient_receptivity) = MOD1_WATER_AMBIENT_RECEPTIVITY;
	MOD1_INTERNAL(diffuse_receptivity) = MOD1_WATER_DIFFUSE_RECEPTIVITY;
	MOD1_INTERNAL(specular_receptivity) = MOD1_WATER_SPECULAR_RECEPTIVITY;

	terrain_range = terrain->final_max().z - terrain->final_min().z;
	terrain_range *= MOD1_WATER_RANGE_MULTIPLIER;

	set(terrain->min(), terrain->max(), terrain->delta());
	plane::build();

	data_prepare();

	update_model(false);

	cl_build();
	cl_set();
	cl_link();
	cl_write_const();
	cl_write();
}