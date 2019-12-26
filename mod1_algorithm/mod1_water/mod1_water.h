#pragma once

#include "mod1_model.h"
#include "mod1_terrain.h"

class					mod1_water : mod1_model
{
public :
	explicit	 		mod1_water(const mod1_terrain &terrain);
						~mod1_water() = default;

	struct				exception_bad_coordinate : public std::exception
	{
		const char *	what() const throw() override;
	};

	void				build();

private :

	const mod1_terrain	&terrain;
	mod1_point2<int>	size;

	void				*get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot);
};


