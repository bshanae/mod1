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

	constant_flow = MOD1_WATER_CONST_A * MOD1_WATER_CONST_g * (1.f / terrain->delta()) * MOD1_WATER_CONST_dt;
	constant_water_depth = MOD1_WATER_CONST_dt / (terrain->delta() * terrain->delta());

	water_depth.allocate(size().x * size().y);
	water_depth.set(0);

	update_model();
	update_color();

	cl_kernel_flow_update = cl_core.generate_kernel("source_cl/kernel.cl", "update_flow", 1);

	int 							terrain_size[2];
	buffer<float>					terrain_data;

	terrain_size[0] = terrain->size()[0];
	terrain_size[1] = terrain->size()[1];

	terrain_data.allocate(terrain_size[0] * terrain_size[1]);

	point2<int>						iter;

	for (iter.y = 0; iter.y < terrain_size[1]; iter.y++)
		for (iter.x = 0; iter.x < terrain_size[0]; iter.x++)
			terrain_data[terrain_size[0] * iter.y + iter.x] = terrain->read_height(iter);

	printf("Host : \n");
	for (iter.y = 0; iter.y < terrain_size[1]; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain_size[0]; iter.x++)
			printf("%f ", terrain_data[terrain_size[0] * iter.y + iter.x]);
		printf("\n");
	}
	printf("\n");

	cl_arg_terrain_data = cl_kernel_flow_update.generate_argument(
		terrain_data.data(), terrain_data.size_in_bytes(),
		mod1_engine_cl::argument_type::read_only);
	cl_arg_terrain_size = cl_kernel_flow_update.generate_argument(
		terrain_size, sizeof(terrain_size),
		mod1_engine_cl::argument_type::read_only);

	cl_arg_terrain_data.write();
	cl_arg_terrain_size.write();

	cl_kernel_flow_update.run();
}
