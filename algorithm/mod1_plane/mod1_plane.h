#pragma once

#include "mod1_main/mod1_generic.h"
#include "mod1_main/mod1_macro.h"

#include "mod1_engine/mod1_engine.h"

using namespace				mod1_engine;

class						mod1_plane : protected mod1_engine::model
{
public :
							mod1_plane() = default;
							~mod1_plane() = default;

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_coordinate, "Mod1 Plane : Bad coordinate")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_logic, "Mod1 Plane : Object not set")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_color, "Mod1 Plane : Too few colors defined")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_indexing_convention, "Mod1 Plane : Unknown indexing convention")

	void					set(
							const point2<float> &min,
							const point2<float> &max,
							const float &delta);
	void					build() override;

	virtual model			*model();

private :

	point2<int>				size_internal;
	point2<float>			min_internal;
	point2<float>			max_internal;
	float					delta_internal = 0;

	point2<int>				real_size_internal;

	point3<float>			final_min_internal;
	point3<float>			final_max_internal;

protected :

	typedef enum
	{
		convention_single,
		convention_dual_first,
		convention_dual_second
	}						mod1_indexing_convention;

	point3<float>			read_point(const point2<int> &iter) const;
	float					read_height(const point2<int> &iter) const;

	bool					write_height(const point2<int> &iter, const float &z);
	void					write_color(const point2<int> &iter, const point3<float> &color);

	bool					is_valid(
							const point2<int> &iter,
							const model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first) const;
	bool 					is_dual(const point2<int> &iter) const;

	void 					update_normal();

	void 					update_final();

	void					add_color(const point3<float> &color);
	void 					add_color(const point3<int> &color);
	point3<float>			compute_color(const float &height) const;

	MOD1_GENERATE_GET_DEFINITION(size)
	MOD1_GENERATE_GET_DEFINITION(real_size)
	MOD1_GENERATE_GET_DEFINITION(min)
	MOD1_GENERATE_GET_DEFINITION(max)
	MOD1_GENERATE_GET_DEFINITION(delta)
	MOD1_GENERATE_GET_DEFINITION(final_min)
	MOD1_GENERATE_GET_DEFINITION(final_max)

private :

	MOD1_PLANE_COLOR_DATA	color_data;
	using 					model::data;

	bool					is_set = false;

	int 					get_index(
							const point2<int> &iter,
							const mod1_indexing_convention &convention = convention_dual_first) const;

	void 					*get_ptr(
							const point2<int> &iter,
							const model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first);
	void const				*get_ptr(
							const point2<int> &iter,
							const model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first) const;

	void					update_normal_helper(
							const int &index_a,
							const int &index_b,
							const int &index_c);

};