#pragma once

#include "mod1_model.h"
#include "mod1_terrain.h"

class					mod1_water : mod1_model
{
public :
		 				mod1_water(const mod1_terrain &terrain);
						~mod1_water() = default;

	void				build();

private :

	const mod1_terrain	&terrain;

	int 				get_index(const mod1_point2<int> iter);
	int 				*get_ptr(const mod1_point2<int> iter);
};


