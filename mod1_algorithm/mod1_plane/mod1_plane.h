#pragma once

#include "mod1_model.h"

class					mod1_plane : public mod1_model
{
public :
						mod1_plane() = default;
						~mod1_plane() = default;

	void				build(
						const mod1_point2<int> &size,
						const mod1_point2<int> &min,
						const mod1_point2<int> &max,
						const int &delta);

protected :

	mod1_point2<int>	size;
	mod1_point2<int>	min;
	mod1_point2<int>	max;
	int					delta = 0;
};


