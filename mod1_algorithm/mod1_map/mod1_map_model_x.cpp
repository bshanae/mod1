#include "mod1_map.h"

static int 				gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 					mod1_map::model_update_delta(const int &i, const int &j, const int &index)
{
	int 				temp_delta;

	temp_delta = abs(source_data[i][index] - source_data[j][index]);
	model_delta = gcd(model_delta, (int)temp_delta);
}

static bool				reduce(int &value)
{
	for (int temp = 2; temp <= value; temp++)
		if (value % temp == 0)
		{
			value /= temp;
			return (true);
		}
	return (false);
}

static bool				does_need_optimization(const mod1_point3<int> &diff, const int &delta)
{
	mod1_point2<int>	count;

	count = diff / delta;
	return (count.x < MOD1_MAP_MIN_COUNT || count.y < MOD1_MAP_MIN_COUNT);
}

void 					mod1_map::model_optimize_delta(const mod1_point3<int> &diff)
{
	while (does_need_optimization(diff, model_delta))
		if (!reduce(model_delta))
			break ;
}

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

int						mod1_map::model_get_index(const mod1_point2<int> &iter)
{
	if (iter.x < 0 || iter.x >= model_size.x)
		throw (mod1_map::exception_bad_coordinate());
	if (iter.y < 0 || iter.y >= model_size.y)
		throw (mod1_map::exception_bad_coordinate());
	return (iter.y * model_size.x + iter.x);
}

float					*mod1_map::model_get_ptr(const mod1_point2<int> &iter, mod1_map_slot slot)
{
	float				*ptr;

	ptr = nullptr;
	if (slot == mod1_map_slot_point)
		ptr = data.point_array.data();
	else if (slot == mod1_map_slot_normal)
		ptr = data.normal_array.data();
	else if (slot == mod1_map_slot_color)
		ptr = data.color_array.data();
	else
		global_error->raise_error("Map : Incorrect slot");
	return (ptr + 3 * model_get_index(iter));
}

mod1_point2<int>		mod1_map::model_find_ptr(const mod1_point3<int> &object)
{
	mod1_point2<int>	iter;
	float 				*ptr;

	for (iter.y = 0; iter.y < model_size.y; iter.y++)
		for (iter.x = 0; iter.x < model_size.x; iter.x++)
		{
			ptr = model_get_ptr(iter, mod1_map_slot_point);
			if ((int)ptr[0] == object.x && (int)ptr[2] == object.y)
				return (iter);
		}
	global_error->raise_error("Map : Point (%d, %d) not found", object.x, object.y);
	return (iter);
}


void					mod1_map::model_create_hill(const mod1_point3<int> &summit)
{
	const auto			iter_const = model_find_ptr(summit);
	mod1_point2<int>	iter;
	int 				delta = model_delta;
	int 				height;
	bool 				at_least_one;

	for (int step = 1; ; step++)
	{
		height = summit.z - delta * step;
		if (height < 0)
			break ;

		at_least_one = false;

		for (iter.x = iter_const.x - step; iter.x < iter_const.x + step; iter.x++)
		{
			iter.y = iter_const.y - step;
			try
			{
				model_get_ptr(iter, mod1_map_slot_point)[1] = (float)height;
				at_least_one = true;
			}
			catch (mod1_map::exception_bad_coordinate &exception) {}

			iter.y = iter_const.y + step;
			try
			{
				model_get_ptr(iter, mod1_map_slot_point)[1] = (float)height;
				at_least_one = true;
			}
			catch (mod1_map::exception_bad_coordinate &exception) {}
		}
		for (iter.y = iter_const.y - step; iter.y < iter_const.y + step; iter.y++)
		{
			iter.x = iter_const.x - step;
			try
			{
				model_get_ptr(iter, mod1_map_slot_point)[1] = (float)height;
				at_least_one = true;
			}
			catch (mod1_map::exception_bad_coordinate &exception) {}

			iter.x = iter_const.x + step;
			try
			{
				model_get_ptr(iter, mod1_map_slot_point)[1] = (float)height;
				at_least_one = true;
			}
			catch (mod1_map::exception_bad_coordinate &exception) {}
		}
		if (!at_least_one)
			break ;
	}
}

void					mod1_map::model_build()
{
	model_prepare();

	//					Points

	data.point_array.allocate(3 * model_size.x * model_size.y);

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < model_size.y; iter.y++)
		for (iter.x = 0; iter.x < model_size.x; iter.x++)
		{
			ptr = model_get_ptr(iter, mod1_map_slot_point);
			ptr[0] = (float)(model_min.x + iter.x);
			ptr[1] = 0;
			ptr[2] = (float)(model_min.y + iter.y);
		}

	//					Indices

	data.index_array.allocate(6 * (model_size.x - 1) * (model_size.y - 1));

	int 				*index_ptr = data.index_array.data();
	int					index_i = 0;

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;

	index_i = 0;
	for (iter.y = 0; iter.y < model_size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < model_size.x - 1; iter.x++)
		{
			top_left = model_get_index(mod1_point2<int>(iter.x, iter.y));
			top_right = model_get_index(mod1_point2<int>(iter.x + 1, iter.y));
			bottom_left = model_get_index(mod1_point2<int>(iter.x, iter.y + 1));
			bottom_right = model_get_index(mod1_point2<int>(iter.x + 1, iter.y + 1));

			index_ptr[index_i++] = top_left;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = top_right;

			index_ptr[index_i++] = top_right;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = bottom_right;
		}

	//					Normals

	data.normal_array.allocate(6 * (model_size.x - 1) * (model_size.y - 1));

	for (iter.y = 0; iter.y < model_size.y; iter.y++)
		for (iter.x = 0; iter.x < model_size.x; iter.x++)
		{
			ptr = model_get_ptr(iter, mod1_map_slot_normal);
			ptr[0] = 0;
			ptr[1] = 1.;
			ptr[2] = 0;
		}

	//					Colors

	data.color_array.allocate(6 * (model_size.x - 1) * (model_size.y - 1));

	for (iter.y = 0; iter.y < model_size.y; iter.y++)
		for (iter.x = 0; iter.x < model_size.x; iter.x++)
		{
			ptr = model_get_ptr(iter, mod1_map_slot_color);
			ptr[0] = 0.8;
			ptr[1] = 0;
			ptr[2] = 0;
		}

	//					Hills

	for (auto const &iter_source : source_data)
		model_create_hill(iter_source);
}

void					mod1_map::model_print(bool point, bool normal, bool polygon)
{
	printf("Mod1 Map Model : \n");

	if(point)
	{
		printf("Points : \n");
		int					width_count = 0;
		for (int i = 0; i < data.point_array.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				data.point_array.data()[i],
				data.point_array.data()[i + 1],
				data.point_array.data()[i + 2]);
			if (width_count == model_size.x - 1)
			{
				width_count = 0;
				printf("\n");
			} else
				width_count++;
		}
	}

	if(normal)
	{
		printf("Normals : \n");
		int					width_count = 0;
		for (int i = 0; i < data.point_array.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				   data.normal_array.data()[i],
				   data.normal_array.data()[i + 1],
				   data.normal_array.data()[i + 2]);
			if (width_count == model_size.x - 1)
			{
				width_count = 0;
				printf("\n");
			} else
				width_count++;
		}
	}

	if (polygon)
	{
		printf("Polygons : \n");
		for (int i = 0; i < data.index_array.size(); i += 3)
		{
			printf("{%d, %d, %d}\n",
				   data.index_array.data()[i],
				   data.index_array.data()[i + 1],
				   data.index_array.data()[i + 2]);
		}
		printf("\n");
	}
}