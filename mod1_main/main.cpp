#include "mod1_main.h"
#include "mod1_terrain.h"

class 					test_a : public mod1_model
{

public :
	test_a()
	{
		data.point_array = new float[12];
		data.point_array_length = 12;
		data.index_array = new int[6];
		data.index_array_length = 6;

		vertex_number_value = 6;

		float			points[] =
		{
			0.5f,  0.5f,  0.0f,
			0.5f,  -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		int				indices[] =
		{
			0,1,3,
			3,1,2
		};

		memcpy(data.point_array, points, sizeof(float) * data.point_array_length);
		memcpy(data.index_array, indices, sizeof(int) * data.index_array_length);
	}

	~test_a() = default;
};

class 					test_b : public mod1_model
{

public :
	test_b()
	{
		data.point_array = new float[27];
		data.point_array_length = 27;
		data.index_array = new int[24];
		data.index_array_length = 24;

		vertex_number_value = 24;

		float			points[] =
		{
			-0.5, -0.5, 0,
			0, -0.5, 0,
			0.5, -0.5, 0,
			-0.5, 0, 0,
			0, 0, 0,
			0.5, 0, 0,
			-0.5, 0.5, 0,
			0, 0.5, 0,
			0.5, 0.5, 0,
		};

		int				indices[] =
		{
			0, 3, 1,
			1, 3, 4,
			1, 4, 2,
			2, 4, 5,
			3, 5, 4,
			4, 5, 7,
			4, 7, 6,
			5, 7, 8
		};

		memcpy(data.point_array, points, sizeof(float) * data.point_array_length);
		memcpy(data.index_array, indices, sizeof(int) * data.index_array_length);
	}

	~test_b() = default;
};

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->parse(argv[1]);
	main.map->print();

	test_a				a;
	test_b				b;
	mod1_terrain		terrain(0);

	main.renderer->load_model(&a);
	main.renderer->loop();

	return 0;
}