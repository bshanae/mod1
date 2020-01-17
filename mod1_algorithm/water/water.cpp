#include "water.h"

using namespace			mod1_algorithm;

MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_unknown_flow_type)

						water::water(mod1_algorithm::terrain const *terrain) :
						terrain(terrain)
{
	mod1_engine_cl::kernel kernel;

	kernel = cl_core.generate_kernel("source_cl/kernel.cl", "test", 10);

	int A[] = {0, 1, 2, 3, 4};
	int B[] = {1, 1, 1, 1, 1};

	auto arg_a = kernel.generate_argument(A, sizeof(A), mod1_engine_cl::argument_type::read_only);
	auto arg_b = kernel.generate_argument(B, sizeof(B), mod1_engine_cl::argument_type::read_only);

	arg_a.write();
	arg_b.write();

	int C[5];

	auto arg_c = kernel.generate_argument(C, sizeof(C), mod1_engine_cl::argument_type::read_only);

	kernel.run();

	arg_c.read();

	for (auto &i : C)
		printf("%d ", i);
	printf("\n");
}