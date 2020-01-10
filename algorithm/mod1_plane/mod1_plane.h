#pragma once

#include "mod1_exception.h"
#include "mod1_macros.h"

#include "mod1_model.h"
#include "mod1_point2.h"
#include "mod1_point3.h"

class						mod1_plane : protected mod1_model
{
public :
							mod1_plane() = default;
							~mod1_plane() = default;

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_coordinate, "Mod1 Plane : Bad coordinate")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_logic, "Mod1 Plane : Object not set")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_color, "Mod1 Plane : Too few colors defined")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_indexing_convention, "Mod1 Plane : Unknown indexing convention")

	void					set(
							const mod1_point2<float> &min,
							const mod1_point2<float> &max,
							const float &delta);
	void					build() override;

	virtual mod1_model		*model();

protected :

	mod1_point2<int>		size;
	mod1_point2<float>		min;
	mod1_point2<float>		max;
	float					delta = 0;

	typedef enum
	{
		convention_single,
		convention_dual_first,
		convention_dual_second
	}						mod1_indexing_convention;

	int 					get_index(
							const mod1_point2<int> &iter,
							const mod1_indexing_convention &convention = convention_dual_first) const;

	void 					*get_ptr(
							const mod1_point2<int> &iter,
							const mod1_model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first);
	void const				*get_ptr(
							const mod1_point2<int> &iter,
							const mod1_model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first) const;

	bool					is_valid(
							const mod1_point2<int> &iter,
							const mod1_model_data::slot_type &slot,
							const mod1_indexing_convention &convention = convention_dual_first) const;
	bool 					is_dual(const mod1_point2<int> &iter) const;

	void 					update_normal();
	void					update_normal_helper(
							const int &index_a,
							const int &index_b,
							const int &index_c);

	mod1_point3<float>		final_min;
	mod1_point3<float>		final_max;

	void 					update_final();

	void					add_color(const mod1_point3<float> &color);
	void 					add_color(const mod1_point3<int> &color);
	mod1_point3<float>		compute_color(const float &height) const;

private :

	bool					is_set = false;

	MOD1_PLANE_COLOR_DATA	color_data;

};