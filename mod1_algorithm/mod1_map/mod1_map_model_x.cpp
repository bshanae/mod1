#include "mod1_map.h"

void						mod1_map::model_build(int additional_points)
{
	model_width = source_width + (source_width - 1) * additional_points;
	model_height = source_height + (source_height - 1) * additional_points;

	data.point_array_length = model_width * model_height;

	data.point_array = new mod1_point_3f[data.point_array_length];

	mod1_point_2i			iter_source;
	mod1_point_2i			iter_model;
	mod1_point_3f			*ptr_model;

	for (iter_model.x = 0; iter_model.x < model_width; iter_model.x++)
		for (iter_model.y = 0; iter_model.y < model_height; iter_model.y++)
		{
			ptr_model = model_get_ptr(iter_model);
			ptr_model->x = (float)iter_model.x;
			ptr_model->y = (float)iter_model.y;
			ptr_model->z = INFINITY;

		}

	for (iter_source.x = 0; iter_source.x < source_width; iter_source.x++)
		for (iter_source.y = 0; iter_source.y < source_height; iter_source.y++)
		{
			iter_model = mod1_point_2i(iter_source.x * (additional_points + 1), iter_source.y * (additional_points + 1));
			model_get_ptr(iter_model)->z = (float)source_get_value(iter_source);
		}


}

void						mod1_map::model_print()
{
	mod1_point_2i			iter;

	printf("Mod1 Map Model : \n");
	for (iter.y = 0; iter.y < model_width; iter.y++)
	{
		for (iter.x = 0; iter.x < model_width; iter.x++)
			printf("%-10.2f", model_get_ptr(iter)->z);
		printf("\n");
	}
	printf("\n");
}

mod1_point_3f				*mod1_map::model_get_ptr(const mod1_point_2i &point)
{
	global_error->test_critical(point.x > -1 && point.x < model_width, "Map Model : Incorrect x value");
	global_error->test_critical(point.y > -1 && point.y < model_height, "Map Model : Incorrect y value");

	return (data.point_array + point.y * model_width + point.x);
}

bool						mod1_map::model_restore_point(const mod1_point_2i &point)
{

}