#pragma once

#include "mod1_algorithm/namespace.h"

#include "mod1_algorithm/terrain/terrain.h"

/*
 * 	FLOW :
 * 		f < 0 : outcoming
 * 		f > 0 : incoming
 */

enum class							mod1_algorithm::water_color_type
{
	min,
	max
};

class								mod1_algorithm::water : private plane<water_color_type>
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_unknown_flow_type, "Mod1 Water : Unknown flow type")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_color_redefinition, "Mod1 Water : Can't redefine color")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_color_min, "Mod1 Water : Min color is not defined")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_color_max, "Mod1 Water : Max color is not defined")

									water(mod1_engine_cl::core &core, terrain const *terrain);
									~water() final = default;

	void							build() final;
	mod1_engine_gl::model			*model() final;

	static void						callback(const mod1_engine_gl::event &event, void *ptr);

	void							add_color(const point3<float> &color, const water_color_type &type) final;
	void							add_color(const point3<int> &color, const water_color_type &type) final;

	void							set_alpha(const float &alpha);
	void							set_alpha(const int &alpha);

private :

	terrain const					*terrain;

	float							constant_flow = 0;
	float							constant_depth = 0;

	point2<int>						data_size;
	buffer<float>					empty_data;
	buffer<float>					terrain_data;
	buffer<float>					water_data;

	void							data_prepare();
	void							gravity();

//									READ-WRITE

	float							read_terrain_height(const point2<int> &iter);
	float							read_water_depth(const point2<int> &iter);
	float							read_total_height(const point2<int> &iter);

	void							write_water_depth(const point2<int> &iter, const float &value);

//									MODEL

	void							update_model_helper_b(const point2<int> &iter, const float &new_height);
	void							update_model_helper_a(const point2<int> &iter);
	void							update_model(const bool &save = false);

//									COLOR

	point3<float>					color_min = point3<float>(std::numeric_limits<float>::infinity());
	point3<float>					color_max = point3<float>(std::numeric_limits<float>::infinity());
	float							color_alpha = 1;

	void							update_color(const bool &save) final;

//									CL

	mod1_engine_cl::core			&cl_core;

	mod1_engine_cl::kernel			cl_kernel_debug;
	mod1_engine_cl::kernel			cl_kernel_update_flow;
	mod1_engine_cl::kernel			cl_kernel_limit_flow;
	mod1_engine_cl::kernel			cl_kernel_update_depth;

	mod1_engine_cl::argument		cl_arg_const_flow;
	mod1_engine_cl::argument		cl_arg_const_depth;
	mod1_engine_cl::argument		cl_arg_size;
	mod1_engine_cl::argument		cl_arg_terrain_data;
	mod1_engine_cl::argument		cl_arg_water_data;
	mod1_engine_cl::argument		cl_arg_flow_horizontal;
	mod1_engine_cl::argument		cl_arg_flow_vertical;

	void							cl_build();
	void							cl_build_debug();
	void							cl_build_update_flow();
	void							cl_build_limit_flow();
	void							cl_build_update_depth();

	void							cl_set();
	void							cl_set_const();
	void							cl_set_size();
	void							cl_set_terrain();
	void							cl_set_water();
	void							cl_set_flow();

	void							cl_link();
	void							cl_link_debug();
	void							cl_link_update_flow();
	void							cl_link_limit_flow();
	void							cl_link_update_depth();

	void							cl_write();
};


