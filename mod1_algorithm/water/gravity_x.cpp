#include "water.h"

using namespace			mod1_algorithm;

void 					water::gravity_debug()
{
# define RED			"\033[0;31m"
# define BLACK			"\033[0m"

	point2<int>			iter;
/*
	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			if (iter.x)
				printf(":");
			printf("[%+7.2f]:%s%+7.2f%s",
				   water_depth[iter],
				   RED, get_flow(iter, water::flow_right), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			if (iter.x)
				printf("         ");
			printf("%s %+7.2f %s", RED, get_flow(iter, water::flow_down), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
	}
	printf("\n");
 */
}

void					water::gravity()
{
	update_flow();
	limit_flow();

	update_depth();
	diffuse_depth();

	update_model();
}