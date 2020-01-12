#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	set(
		terrain->min() - point2<float>(terrain->delta() / 2),
		terrain->max() + point2<float>(terrain->delta() / 2),
		terrain->delta());
	plane::build();

	flow_constant = MOD1_WATER_CONST_A * MOD1_WATER_CONST_g * (1.f / terrain->delta()) * MOD1_WATER_CONST_dt;
	water_depth_constant = MOD1_WATER_CONST_dt / (terrain->delta() * terrain->delta());

	water_depth_copy.allocate(size().x, size().y);
	water_depth.allocate(size().x, size().y);
	water_depth.set(0);

	flow_horizontal.allocate(size().x - 1, size().y);
	flow_horizontal.set(0);

	flow_vertical.allocate(size().x, size().y - 1);
	flow_vertical.set(0);

	update_model();
	update_color();
}
