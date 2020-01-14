#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::info(const bool &raw, const bool &model) const
{
	printf("Mod1 Terrain Info : \n");

	if (raw)
	{
		printf("\nSource\n");
		printf("{\n");
		for (const auto &iter : data_raw)
			printf("\t{%d, %d, %d}\n", iter.x, iter.y, iter.z);
		printf("}\n");
		printf("Raw min = {%d, %d, %d}\n", min_raw.x, min_raw.y, min_raw.z);
		printf("Raw max = {%d, %d, %d}\n", max_raw.x, max_raw.y, max_raw.z);
	}

	if (model)
	{
		printf("\nModel : \n");
		printf("Min = {%f, %f}\n", min().x, min().y);
		printf("Max = {%f, %f}\n", max().x, max().y);
		printf("Size = {%d, %d}\n", size().x, size().y);
		printf("Delta = %f(%d)\n", delta(), delta_i);
	}
}