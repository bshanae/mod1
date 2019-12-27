#include "mod1_terrain.h"

void						mod1_terrain::info(unsigned int flags) const
{
	int						width_count;

	printf("Mod1 Terrain Info : \n");

	if (flags & MOD1_MAP_INFO_RAW)
	{
		printf("\nSource\n");
		printf("{\n");
		for (const auto &iter : data_raw)
			printf("\t{%d, %d, %d}\n", iter.x, iter.y, iter.z);
		printf("}\n");
		printf("Raw min = {%d, %d, %d}\n", min_raw.x, min_raw.y, min_raw.z);
		printf("Raw max = {%d, %d, %d}\n", max_raw.x, max_raw.y, max_raw.z);
	}

	if (flags & MOD1_MAP_INFO_MODEL)
	{
		printf("\nModel : \n");
		printf("Min = {%f, %f}\n", min.x, min.y);
		printf("Max = {%f, %f}\n", max.x, max.y);
		printf("Size = {%d, %d}\n", size.x, size.y);
		printf("Delta = %f(%d)\n", delta, delta_i);
	}

	if(flags & MOD1_MAP_INFO_POINT)
	{
		width_count = 0;
		printf("\nPoints : \n");
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

	if(flags & MOD1_MAP_INFO_NORMAL)
	{
		width_count = 0;
		printf("\nNormals : \n");
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

	if(flags & MOD1_MAP_INFO_COLOR)
	{
		width_count = 0;
		printf("\nNormals : \n");
		for (int i = 0; i < data.point_buffer.size(); i += 3)
		{
			printf("{%5.2f %5.2f %5.2f} ",
				   data.color_buffer.data()[i],
				   data.color_buffer.data()[i + 1],
				   data.color_buffer.data()[i + 2]);
			if (width_count == size.x - 1)
			{
				width_count = 0;
				printf("\n");
			} else
				width_count++;
		}
	}

	if (flags & MOD1_MAP_INFO_POLYGON)
	{
		printf("\nPolygons : \n");
		for (int i = 0; i < data.index_buffer.size(); i += 3)
		{
			printf("{%d, %d, %d}\n",
				   data.index_buffer.data()[i],
				   data.index_buffer.data()[i + 1],
				   data.index_buffer.data()[i + 2]);
		}
		printf("\n");
	}
	printf("\n");
}