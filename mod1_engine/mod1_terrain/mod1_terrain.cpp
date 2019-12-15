#include "mod1_terrain.h"

					mod1_terrain::mod1_terrain(
					float position_z,
					float size,
					int vertex_number) :
					position_z(position_z),
					size(size)
{
	this->vertex_number_value = vertex_number;

	int 			vertex_number_sqr = vertex_number * vertex_number;

	data.point_array_length = vertex_number_sqr * 3;
	data.point_array = new float[data.point_array_length];

	int 			vertex_i = 0;

	for(int i = 0; i < vertex_number; i++)
	{
		for(int j = 0; j < vertex_number; j++)
		{
			data.point_array[vertex_i * 3] = (float)j / ((float)vertex_number - 1) * size;
			data.point_array[vertex_i * 3 + 1] = 0;
			data.point_array[vertex_i * 3 + 2] = (float)i / ((float)vertex_number - 1) * size;
			vertex_i++;
		}
	}

	data.index_array_length = 6 * (vertex_number - 1) * (vertex_number - 1);
	data.index_array = new int[data.index_array_length];

	int				index_i = 0;

	for(int gz = 0; gz < vertex_number - 1; gz++)
	{
		for(int gx = 0; gx < vertex_number - 1; gx++)
		{
			int		top_left = (gz * vertex_number) + gx;
			int		top_right = top_left + 1;
			int		bottom_left = ((gz + 1) * vertex_number) + gx;
			int		bottom_right = bottom_left + 1;

			data.index_array[index_i++] = top_left;
			data.index_array[index_i++] = bottom_left;
			data.index_array[index_i++] = top_right;
			data.index_array[index_i++] = top_right;
			data.index_array[index_i++] = bottom_left;
			data.index_array[index_i++] = bottom_right;
		}
	}
}