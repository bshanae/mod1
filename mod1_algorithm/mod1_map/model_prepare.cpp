#include "mod1_map.h"

void					mod1_map::model_prepare()
{
	mod1_point3<int>	model_diff = source_max - source_min;

	model_delta = 0;

	if (model_diff == mod1_point3<int>())
	{
		model_delta = MOD1_MAP_DEF_DELTA;
		model_diff = MOD1_MAP_DEF_SIZE;
	}
	else
		for (int i = 0; i < source_data.size(); i++)
			for (int j = 0; j < source_data.size(); j++)
			{
				if (j == i)
					continue ;
				model_update_delta(i, j, 0);
				model_update_delta(i, j, 1);
			}

	model_optimize_delta(model_diff);

	printf("model delta = %d\n", model_delta);

	model_min = source_min - model_diff * MOD1_MAP_INDENT;
	model_max = source_max + model_diff * MOD1_MAP_INDENT;

	model_min = (model_min / model_delta - mod1_point2<int>(1)) * model_delta;
	model_max = (model_max / model_delta + mod1_point2<int>(1)) * model_delta;

	model_size = (model_max - model_min) / model_delta + mod1_point2<int>(1);

	printf("Model min = %d, %d\n", model_min.x, model_min.y);
	printf("Model max = %d, %d\n", model_max.x, model_max.y);
	printf("Model size = %d, %d\n", model_size.x, model_size.y);
}