#include "mod1_main.h"

class 					test : public mod1_model
{

public :
	test()
	{
		data.point_array = new float[12];
		data.point_array_length = 12;
		data.index_array = new int[6];
		data.index_array_length = 6;

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

	~test() = default;
};

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->parse(argv[1]);
	main.map->print();

	test				test;

	main.renderer->load_model(&test);
	main.renderer->loop();

	return 0;
}