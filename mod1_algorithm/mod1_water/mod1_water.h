#pragma once

#include "mod1_model.h"
#include "mod1_plane.h"
#include "mod1_terrain.h"
#include "mod1_buffer2.h"

#include <random>

#define MOD1_WATER_COLOR_A			mod1_point3<float>(0, 0.62, 1)
#define MOD1_WATER_COLOR_B			mod1_point3<float>(0, 0.05, 0.1)

#define MOD1_WATER_RIGHT			mod1_point2<int>(1, 0)
#define MOD1_WATER_UPPER			mod1_point2<int>(0, -1)
#define MOD1_WATER_LEFT				mod1_point2<int>(-1, 0)
#define MOD1_WATER_DOWN				mod1_point2<int>(0, 1)

#define	FLOOD_POINT

class								mod1_water : private mod1_plane
{
public :

	struct							exception_unknown_flow_type : public std::exception
	{
		const char					*what() const noexcept override;
	};

	explicit	 					mod1_water(mod1_terrain const *terrain);
									~mod1_water() = default;

	void							build() final;
	mod1_model						*model() final;

	static bool						callback(int key, void *ptr);

private :

	mod1_terrain const				*terrain;
	mod1_buffer2<float>				flow_horizontal;
	mod1_buffer2<float>				flow_vertical;
	float							flow_constant;

	mod1_buffer2<float>				water_depth;
	float							water_depth_constant;

	float							get_terrain_height(const mod1_point2<int> &iter);
	float							get_total_height(const mod1_point2<int> &iter);

	typedef enum
	{
		flow_right,
		flow_up,
		flow_left,
		flow_down
	}								mod1_water_flow_type;
	float							get_flow(const mod1_point2<int> &iter, const mod1_water_flow_type &type);
	float							get_flow_safe(const mod1_point2<int> &iter, const mod1_water_flow_type &type);

	void							set_flow(const mod1_point2<int> &iter, const mod1_water_flow_type &type, const float &value);
	bool							set_flow_safe(const mod1_point2<int> &iter, const mod1_water_flow_type &type, const float &value);

	void							update_model_helper_b(const mod1_point2<int> &iter, const float &new_height);
	void							update_model_helper_a(const mod1_point2<int> &iter);
	void							update_model();

	void							update_color();

	void							update_flow();
	void							limit_flow();
	void							update_depth();

	void 							gravity_debug();
	void							gravity();
};


