#include "mod1_terrain.h"

void						mod1_terrain::info(bool source, bool point, bool normal, bool polygon) const
{
	int						width_count;

	printf("Mod1 Map : \n");

	if (source)
	{
		for (const auto &iter : data_raw)
			printf("\t{%d, %d, %d}\n", iter.x, iter.y, iter.z);
		printf("}\n");
		printf("Raw min = {%d, %d, %d}\n", min_raw.x, min_raw.y, min_raw.z);
		printf("Raw max = {%d, %d, %d}\n", max_raw.x, max_raw.y, max_raw.z);
	}

	if(point)
	{
		width_count = 0;
		printf("Points : \n");
		for (int i = 0; i < data.point_buffer.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				data.point_buffer.data()[i],
				data.point_buffer.data()[i + 1],
				data.point_buffer.data()[i + 2]);
			if (width_count == size.x - 1)
			{
				width_count = 0;
				printf("\n");
			} else
				width_count++;
		}
	}

	if(normal)
	{
		width_count = 0;
		printf("Normals : \n");
		for (int i = 0; i < data.point_buffer.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				   data.normal_buffer.data()[i],
				   data.normal_buffer.data()[i + 1],
				   data.normal_buffer.data()[i + 2]);
			if (width_count == size.x - 1)
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