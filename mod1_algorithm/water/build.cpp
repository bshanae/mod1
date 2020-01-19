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

	water_data[1] = 10;
	water_data[2] = 100;

	cl_build();
	cl_set();
	cl_link();
	cl_write();

#define DEBUG	1

	cl_kernel_flow_update.run();

#if DEBUG
	printf("\n\n");
	cl_kernel_debug.run();
#endif

	cl_kernel_flow_limit.run();

#if DEBUG
	printf("Limited : \n\n");
	cl_kernel_debug.run();
#endif

	update_model();
	update_color();

	exit(1);
}
