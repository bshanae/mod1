#include "water.h"

using namespace			mod1_algorithm;

MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_unknown_flow_type)

						water::water(mod1_algorithm::terrain const *terrain) :
						terrain(terrain)
{
	mod1_engine_cl::kernel minus;
	mod1_engine_cl::kernel plus;

	minus = cl_core.generate_kernel("source_cl/kernel.cl", "minus", 10);
	plus = cl_core.generate_kernel("source_cl/kernel.cl", "plus", 10);

	int A[] = {0, 1, 2, 3, 4};
	int B[] = {1, 1, 1, 1, 1};

	auto arg_a = minus.generate_argument(A, sizeof(A), mod1_engine_cl::argument_type::read_only);
	auto arg_b = minus.generate_argument(B, sizeof(B), mod1_engine_cl::argument_type::read_only);

	plus.link_argument(arg_a);
	plus.link_argument(arg_b);

	arg_a.write();
	arg_b.write();

	int C[5];

	auto arg_c = minus.generate_argument(C, sizeof(C), mod1_engine_cl::argument_type::read_only);
	plus.link_argument(arg_c);

	minus.run();
	arg_c.read();
	printf("Minus : ");
	for (auto &i : C)
		printf("%d ", i);
	printf("\n");

	plus.run();
	arg_c.read();
	printf("Plus : ");
	for (auto &i : C)
		printf("%d ", i);
	printf("\n");
}