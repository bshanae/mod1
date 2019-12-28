#pragma once

#include "mod1_model.h"
#include "mod1_plane.h"
#include "mod1_terrain.h"
#include "mod1_buffer2.h"

class						mod1_water : private mod1_plane
{
public :

	struct					exception_no_water : public std::exception
	{
		const char			*what() const noexcept override;
	};

	explicit	 			mod1_water(mod1_terrain const *terrain);
							~mod1_water() = default;

	void					build() final;
	mod1_model				*model() final;

	static bool				callback(int key, void *ptr);

private :

	mod1_terrain const		*terrain;
	mod1_buffer2<int>		water_level;
	const float				water_drop_height = 1.f;

	float					get_height(const mod1_point2<int> &iter);
	int						get_water(const mod1_point2<int> &iter);
	float					get_pressure(const mod1_point2<int> &iter);

	void					add_water(const mod1_point2<int> &iter);
	void					replace_water(const mod1_point2<int> &from, const mod1_point2<int> &to);

	void					update_height_helper(const mod1_point2<int> &iter, const float &new_height);
	void					update_height_iter(const mod1_point2<int> &iter);
	void					update_height();

	void					gravity_helper_a(const mod1_point2<int> &iter);
	void					gravity_helper_b(const mod1_point2<int> &from, const mod1_point2<int> &to);
	void					gravity();
};


