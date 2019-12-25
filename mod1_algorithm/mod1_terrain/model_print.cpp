#include "mod1_terrain.h"

void					mod1_terrain::model_print(bool point, bool normal, bool polygon)
{
	printf("Mod1 Map Model : \n");

	if(point)
	{
		printf("Points : \n");
		int					width_count = 0;
		for (int i = 0; i < data.point_buffer.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				data.point_buffer.data()[i],
				data.point_buffer.data()[i + 1],
				data.point_buffer.data()[i + 2]);
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
		for (int i = 0; i < data.point_buffer.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				   data.normal_buffer.data()[i],
				   data.normal_buffer.data()[i + 1],
				   data.normal_buffer.data()[i + 2]);
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
		for (int i = 0; i < data.index_buffer.size(); i += 3)
		{
			printf("{%d, %d, %d}\n",
				   data.index_buffer.data()[i],
				   data.index_buffer.data()[i + 1],
				   data.index_buffer.data()[i + 2]);
		}
		printf("\n");
	}
}