#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	MOD1_INTERNAL(ambient_receptivity) = 1.2;
	MOD1_INTERNAL(diffuse_receptivity) = 0.8;
	MOD1_INTERNAL(specular_receptivity) = 0.2;

	set(
		terrain->min() - point2<float>(terrain->delta() / 2),
		terrain->max() + point2<float>(terrain->delta() / 2),
		terrain->delta());
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