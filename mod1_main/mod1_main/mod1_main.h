#pragma once

#include "mod1_renderer.h"
#include "mod1_terrain.h"
#include "mod1_water.h"

class 				mod1_main
{

public :

					mod1_main(int argc, char **argv);
					~mod1_main();

	struct			exception_invalid_arguments : public std::exception
	{
		const char	*what() const noexcept override;
	};

	void			build();
	void			loop();

	mod1_renderer	*renderer = nullptr;
	mod1_terrain	*terrain = nullptr;
	mod1_water		*water = nullptr;

private :

	char			*source;

};