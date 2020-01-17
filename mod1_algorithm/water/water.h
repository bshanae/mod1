#pragma once

#include "mod1_main/mod1_macros.h"
#include "mod1_main/mod1_control.h"

#include "mod1_algorithm/namespace.h"

#include "mod1_algorithm/terrain/terrain.h"

class								mod1_algorithm::water : private plane
{
public :

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_unknown_flow_type, "Mod1 Water : Unknown flow type")

	explicit	 					water(terrain const *terrain);
									~water() = default;

	void							build() final;
	mod1_engine_gl::model			*model() final;

	static bool						callback(int key, void *ptr);

private :

	terrain const					*terrain;
	float							constant_flow = 0;
	float							constant_water_depth = 0;
	buffer<float>					water_depth;

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

	mod1_engine_cl::core			cl_core;

	mod1_engine_cl::kernel			cl_kernel_flow_update;
	mod1_engine_cl::kernel			cl_kernel_flow_limit;
	mod1_engine_cl::kernel			cl_kernel_depth;

	mod1_engine_cl::argument		cl_arg_terrain_size;
	mod1_engine_cl::argument		cl_arg_terrain_data;
	mod1_engine_cl::argument		cl_arg_water_size;
	mod1_engine_cl::argument		cl_arg_water_data;
	mod1_engine_cl::argument		cl_arg_flow_horizontal;
	mod1_engine_cl::argument		cl_arg_flow_vertical;

	void 							gravity_debug();
	void							gravity();
};


