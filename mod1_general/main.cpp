#include "mod1_general/general/general.h"

using namespace				mod1_algorithm;

void						main_unsafe(int argc, char **argv)
{
	general					general(argc, argv);

	general.terrain()->add_color(mod1_engine_gl::point3<int>(77, 51, 25), plane::color_type::negative);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(101, 67, 33), plane::color_type::negative);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(201, 178, 99), plane::color_type::negative);

	general.terrain()->add_color(mod1_engine_gl::point3<int>(201, 178, 99), plane::color_type::positive);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(80, 171, 93), plane::color_type::positive);
	general.terrain()->add_color(mod1_engine_gl::point3<int>(120, 120, 120), plane::color_type::positive);

//	general.water()->add_color(plane::color::negative, mod1_engine_gl::point3<int>(0, 0, 255));
//	general.water()->add_color(plane::color::positive, mod1_engine_gl::point3<int>(0, 0, 255));

	general.water()->define_alpha(1.f);

	general.build();
	general.start();
}

int							main(int argc, char **argv)
{
	main_unsafe(argc, argv);
	return (0);
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