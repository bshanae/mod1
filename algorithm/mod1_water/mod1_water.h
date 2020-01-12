#pragma once

#include "mod1_main/mod1_macro.h"
#include "mod1_main/mod1_control.h"

#include "algorithm/mod1_plane/mod1_plane.h"
#include "algorithm/mod1_terrain/mod1_terrain.h"

#define MOD1_WATER_RIGHT			point2<int>(1, 0)
#define MOD1_WATER_UPPER			point2<int>(0, -1)
#define MOD1_WATER_LEFT				point2<int>(-1, 0)
#define MOD1_WATER_DOWN				point2<int>(0, 1)

class								mod1_water : private mod1_plane
{
public :

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_unknown_flow_type, "Mod1 Water : Unknown flow type")

	explicit	 					mod1_water(mod1_terrain const *terrain);
									~mod1_water() = default;

	void							build() final;
	class model						*model() final;

	static bool						callback(int key, void *ptr);

private :

	mod1_terrain const				*terrain;
	buffer2<float>					flow_horizontal;
	buffer2<float>					flow_vertical;
	float							flow_constant = 0;

	buffer2<float>					water_depth_copy;
	buffer2<float>					water_depth;
	float							water_depth_constant = 0;

	float							get_terrain_height(const point2<int> &iter);
	float							get_total_height(const point2<int> &iter);

	typedef enum
	{
		flow_right,
		flow_up,
		flow_left,
		flow_down,
		flow_end
	}								mod1_water_flow_type;
	float							get_flow(const point2<int> &iter, const mod1_water_flow_type &type);
	float							get_flow_safe(const point2<int> &iter, const mod1_water_flow_type &type);

	void							set_flow(const point2<int> &iter, const mod1_water_flow_type &type, const float &value);
	bool							set_flow_safe(const point2<int> &iter, const mod1_water_flow_type &type, const float &value);

	void							update_model_helper_b(const point2<int> &iter, const float &new_height);
	void							update_model_helper_a(const point2<int> &iter);
	void							update_model();

	void							update_color();

	void							update_flow();
	void							limit_flow();

	void							update_depth();
	void							diffuse_depth();

	void 							gravity_debug();
	void							gravity();
};


