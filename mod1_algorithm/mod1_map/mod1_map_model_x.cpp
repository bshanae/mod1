#include "mod1_map.h"

/*
void						mod1_map::model_build(int additional_points, float min, float max)
{
	//						Setting new size of map

	model_width = source_width + (source_width - 1) * additional_points;
	model_height = source_height + (source_height - 1) * additional_points;

	//						Filling map with x,z and y = 0

	data.point_array_length = 3 * model_width * model_height;
	data.point_array = new float[data.point_array_length];

	mod1_point_2i			iter_source;
	mod1_point_2i			iter_model;
	mod1_point_3f			*ptr_model;

	for (iter_model.y = 0; iter_model.y < model_height; iter_model.y++)
		for (iter_model.x = 0; iter_model.x < model_width; iter_model.x++)
		{
			ptr_model = model_get_ptr(iter_model);
			ptr_model->x = (float)iter_model.x;
			ptr_model->y = INFINITY;
			ptr_model->z = (float)iter_model.y;
		}

	//						Filling y from source

	float 					source_min = INFINITY;
	float 					source_max = -INFINITY;
	float 					source_temp;

	for (iter_source.y = 0; iter_source.y < source_height; iter_source.y++)
		for (iter_source.x = 0; iter_source.x < source_width; iter_source.x++)
		{
			source_temp = (float)source_get_value(iter_source);
			if (source_temp < source_min)
				source_min = source_temp;
			else if (source_temp > source_max)
				source_max = source_temp;
		}

	for (iter_source.y = 0; iter_source.y < source_height; iter_source.y++)
		for (iter_source.x = 0; iter_source.x < source_width; iter_source.x++)
		{
			iter_model = mod1_point_2i(iter_source.x * (additional_points + 1), iter_source.y * (additional_points + 1));
			source_temp = ((float)source_get_value(iter_source) - source_min) / (source_max - source_min);
			model_get_ptr(iter_model)->y = min + source_temp * (max - min);
		}

	//						Restoring values of additional points

	bool					is_done;

	do
	{
		is_done = true;
		for (iter_model.y = 0; iter_model.y < model_height; iter_model.y++)
			for (iter_model.x = 0; iter_model.x < model_width; iter_model.x++)
				is_done = model_restore_point(iter_model) && is_done;
	} while (!is_done);

	//						Settings polygons

	data.index_array_length = 6 * (model_width - 1) * (model_height - 1);
	data.index_array = new int[data.index_array_length];

	int				index_i = 0;

	int				top_left;
	int				top_right;
	int				bottom_left;
	int				bottom_right;

	index_i = 0;
	for (iter_model.y = 0; iter_model.y < model_height - 1; iter_model.y++)
		for (iter_model.x = 0; iter_model.x < model_width - 1; iter_model.x++)
		{
			top_left = model_get_index(mod1_point_2i(iter_model.x, iter_model.y));
			top_right = model_get_index(mod1_point_2i(iter_model.x + 1, iter_model.y));
			bottom_left = model_get_index(mod1_point_2i(iter_model.x, iter_model.y + 1));
			bottom_right = model_get_index(mod1_point_2i(iter_model.x + 1, iter_model.y + 1));

			data.index_array[index_i++] = top_left;
			data.index_array[index_i++] = bottom_left;
			data.index_array[index_i++] = top_right;

			data.index_array[index_i++] = top_right;
			data.index_array[index_i++] = bottom_left;
			data.index_array[index_i++] = bottom_right;

		}
}

void						mod1_map::model_print(bool print_raw, bool print_y, bool print_index, bool print_polygon)
{
	mod1_point_2i			iter;
	auto					ptr = (mod1_point_3f *)data.point_array;

	printf("Mod1 Map Model : \n");

	if(print_raw)
	{
		printf("Raw points : \n");
		int width_count = 0;
		for (int i = 0; i < data.point_array_length; i++)
		{
			printf("{%.2f, %.2f, %.2f} ", ptr[i].x, ptr[i].y, ptr[i].z);
			if (width_count == model_width - 1)
			{
				width_count = 0;
				printf("\n");
			} else
				width_count++;
		}
	}

	if (print_y)
	{
		printf("Points : \n");
		for (iter.y = 0; iter.y < model_width; iter.y++)
		{
			for (iter.x = 0; iter.x < model_width; iter.x++)
				printf("%-10.2f", model_get_ptr(iter)->z);
			printf("\n");
		}
	}

	if (print_index)
	{
		printf("Points indices : \n");
		for (iter.y = 0; iter.y < model_width; iter.y++)
		{
			for (iter.x = 0; iter.x < model_width; iter.x++)
				printf("%-4d", model_get_index(iter));
			printf("\n");
		}
	}

	if (print_polygon)
	{
		printf("Polygons : \n");
		for (int i = 0; i < data.index_array_length; i += 3)
		{
			printf("{%d, %d, %d}\n",
				   data.index_array[i],
				   data.index_array[i + 1],
				   data.index_array[i + 2]);
		}
		printf("\n");
	}
}

int							mod1_map::model_get_index(const mod1_point_2i &point)
{
	if (point.x < 0 || point.x >= model_width)
		throw (mod1_map::exception_bad_coordinate());
	if (point.y < 0 || point.y >= model_height)
		throw (mod1_map::exception_bad_coordinate());
	return (point.y * model_width + point.x);
}


mod1_point_3f				*mod1_map::model_get_ptr(const mod1_point_2i &point)
{
	return ((mod1_point_3f *)data.point_array + model_get_index(point));
}

void						mod1_map::model_test_point(const mod1_point_2i &point, int &count_filled, int &count_valid, float &sum)
{
	float					temp;

	try
	{
		temp = model_get_ptr(point)->y;
	}
	catch (mod1_map::exception_bad_coordinate &exception)
	{
		return ;
	}
	count_valid++;
	if (temp != INFINITY)
	{
		count_filled++;
		sum += temp;
	}
}

bool						mod1_map::model_restore_point(const mod1_point_2i &point)
{
	int 					count_filled = 0;
	int 					count_valid = 0;
	float					sum_filled = 0.f;

	if (model_get_ptr(point)->y != INFINITY)
		return (true);

	model_test_point(mod1_point_2i(point.x - 1, point.y - 1), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x - 1, point.y + 0), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x - 1, point.y + 1), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x + 0, point.y - 1), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x + 0, point.y + 1), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x + 1, point.y - 1), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x + 1, point.y + 0), count_filled, count_valid, sum_filled);
	model_test_point(mod1_point_2i(point.x + 1, point.y + 1), count_filled, count_valid, sum_filled);

	if ((float)count_filled / (float)count_valid >= 0.5f)
	{
		model_get_ptr(point)->y = sum_filled / (float)count_filled;
		return (true);
	}
	return (false);
}
 */