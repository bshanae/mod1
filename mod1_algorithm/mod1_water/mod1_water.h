#pragma once

#include "mod1_model.h"
#include "mod1_plane.h"
#include "mod1_terrain.h"

class					mod1_water : private mod1_plane
{
public :
	explicit	 		mod1_water(mod1_terrain const *terrain);
						~mod1_water() = default;

	void				build() final;
	mod1_model			*model() final;

private :

	mod1_terrain const	*terrain;
	mod1_point2<int>	size;
};


