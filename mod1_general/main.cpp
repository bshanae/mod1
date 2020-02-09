#include "mod1_general/general/general.h"

using namespace		mod1_algorithm;

void				main_unsafe(int argc, char **argv)
{
	general			general(argc, argv);

	general.terrain()->add_color(mod1_engine_gl::point3<int>(77, 51, 25), terrain_color_type::negative);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(101, 67, 33), terrain_color_type::negative);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(201, 178, 99), terrain_color_type::negative);

	general.terrain()->add_color(mod1_engine_gl::point3<int>(201, 178, 99), terrain_color_type::positive);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(80, 171, 93), terrain_color_type::positive);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(120, 120, 120), terrain_color_type::positive);

	general.water()->add_color(point3<int>(15, 94, 156), water_color_type::min);
	general.water()->add_color(point3<int>(116, 204, 244), water_color_type::max);
	general.water()->set_alpha(0.7f);

	general.build();
	general.start();
}

#if MOD1_ENABLED(MOD1_DEVELOPER_MODE)
int					main(int argc, char **argv)
{
	main_unsafe(argc, argv);
	return (0);
}
#else
int					main(int argc, char **argv)
{
	try
	{
		main_unsafe(argc, argv);
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Mod1 : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
	}
}
#endif