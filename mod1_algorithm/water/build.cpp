#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	model::MOD1_INTERNAL(ambient_receptivity) = 1.5;
	model::MOD1_INTERNAL(diffuse_receptivity) = 0.5;
	model::MOD1_INTERNAL(specular_receptivity) = 0.1;//MOD1_WATER_SPECULAR;

	set(
		terrain->min() - point2<float>(terrain->delta() / 2),
		terrain->max() + point2<float>(terrain->delta() / 2),
		terrain->delta());
	plane::build();

	data_prepare();

	update_model();
	update_normal();
	update_color();

	cl_build();
	cl_set();
	cl_link();
	cl_write();
}
