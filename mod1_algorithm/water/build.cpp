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

	data_prepare();

	water_data[1] = 1;

	cl_build();
	cl_set();
	cl_link();
	cl_write();

	cl_kernel_debug.run();
	cl_kernel_flow_update.run();

	printf("\n\n");
	cl_kernel_debug.run();

	update_model();
	update_color();
}
