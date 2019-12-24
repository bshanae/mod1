#include "mod1_map.h"

void					mod1_map::model_prepare()
{
	model_compute_delta();
	model_optimize_delta();
	printf("model delta = %d\n", model_delta);

	model_min = source_min;
	model_max = source_max;

	mod1_point2<int>	test;

	for (auto const &iter : source_data)
	{
		test = mod1_point2<int>(iter.x - iter.z, iter.y - iter.z);
		model_min = mod1_point2<int>::min(model_min, test);
		test = mod1_point2<int>(iter.x + iter.z, iter.y + iter.z);
		model_max = mod1_point2<int>::max(model_max, test);
	}

	mod1_point2<int>	indent = (model_max - model_min) * MOD1_MAP_INDENT;
	model_min -= indent;
	model_max += indent;

	model_min = (model_min / model_delta - mod1_point2<int>(1)) * model_delta;
	model_max = (model_max / model_delta + mod1_point2<int>(1)) * model_delta;

	model_size = (model_max - model_min) / model_delta + mod1_point2<int>(1);

	printf("Model min = %d, %d\n", model_min.x, model_min.y);
	printf("Model max = %d, %d\n", model_max.x, model_max.y);
	printf("Model size = %d, %d\n", model_size.x, model_size.y);
}