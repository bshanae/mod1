#include "mod1_cube.h"

#define SIDE	2.f

void			mod1_cube::build()
{
	set_as_built();

	float		points[] =
	{
		// 		Upper square
		+SIDE, +SIDE, -SIDE,
		+SIDE, +SIDE, +SIDE,
		-SIDE, +SIDE, -SIDE,
		-SIDE, +SIDE, +SIDE,
		// 		Lower square
		+SIDE, -SIDE, -SIDE,
		+SIDE, -SIDE, +SIDE,
		-SIDE, -SIDE, -SIDE,
		-SIDE, -SIDE, +SIDE
	};

	int 		indices[] =
	{
		//		Upper
		0, 2, 1,
		1, 2, 3,
		//		Lower
		5, 6, 4,
		7, 6, 5,
		//		Right
		3, 7, 1,
		1, 7, 5,
		//		Left
		0, 4, 2,
		2, 4, 6,
		//		Front
		4, 1, 5,
		0, 1, 4,
		//		Back
		2, 6, 3,
		3, 6, 7
	};

	float		normals[] =
	{
		// 		Upper square
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		// 		Lower square
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0
	};

	float 		colors[] =
	{
		// 		Upper square
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		// 		Lower square
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};

	data.point_buffer.allocate(sizeof(points) / sizeof(float));
	data.point_buffer.copy(points);

	data.index_buffer.allocate(sizeof(indices) / sizeof(int));
	data.index_buffer.copy(indices);

	data.normal_buffer.allocate(sizeof(normals) / sizeof(float));
	data.normal_buffer.copy(normals);

	data.color_buffer.allocate(sizeof(colors) / sizeof(float));
	data.color_buffer.copy(colors);
}

mod1_model			*mod1_cube::model()
{
	return ((mod1_model *)this);
}