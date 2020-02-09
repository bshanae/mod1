#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	MOD1_INTERNAL(ambient_receptivity) = MOD1_WATER_AMBIENT_RECEPTIVITY;
	MOD1_INTERNAL(diffuse_receptivity) = MOD1_WATER_DIFFUSE_RECEPTIVITY;
	MOD1_INTERNAL(specular_receptivity) = MOD1_WATER_SPECULAR_RECEPTIVITY;

	set(terrain->min(), terrain->max(), terrain->delta());
	plane::build();

	data_prepare();

	update_model();
	update_normal();
	update_color(false);

	cl_build();
	cl_set();
	cl_link();
	cl_write();
}