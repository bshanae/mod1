#pragma once

#include "mod1_main/mod1_generic.h"
#include "mod1_main/mod1_macros.h"

#include "mod1_algorithm/namespace.h"

class									mod1_algorithm::plane : protected mod1_engine_gl::model
{
public :
										plane() = default;
										~plane() = default;

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_coordinate, "Mod1 Plane : Bad coordinate")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_logic, "Mod1 Plane : Object not set")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_color, "Mod1 Plane : Too few colors defined")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_indexing_convention, "Mod1 Plane : Unknown indexing convention")

	void								set(
										const point2<float> &min,
										const point2<float> &max,
										const float &delta);
	void								build() override;

	virtual mod1_engine_gl::model		*model();
	virtual const mod1_engine_gl::model	*model() const;

private :

	point2<int>							size_internal;
	point2<float>						min_internal;
	point2<float>						max_internal;
	float								delta_internal = 0;

	point2<int>							real_size_internal;

	point3<float>						final_min_internal;
	point3<float>						final_max_internal;

protected :

	typedef enum
	{
		convention_single,
		convention_dual_first,
		convention_dual_second
	}									mod1_indexing_convention;

	point3<float>						read_point(const point2<int> &iter) const;
	float								read_height(const point2<int> &iter) const;

	bool								write_height(const point2<int> &iter, const float &z);
	void								write_color(const point2<int> &iter, const point3<float> &color);

	bool								is_valid(
										const point2<int> &iter,
										const model_slot &slot,
										const mod1_indexing_convention &convention = convention_dual_first) const;
	bool 								is_dual(const point2<int> &iter) const;

	void 								update_normal();

	void 								update_final();

	void								add_color(const point3<float> &color);
	void 								add_color(const point3<int> &color);
	point3<float>						compute_color(const float &height) const;

	MOD1_GENERATE_GET_DECLARATION(size)
	MOD1_GENERATE_GET_DECLARATION(real_size)
	MOD1_GENERATE_GET_DECLARATION(min)
	MOD1_GENERATE_GET_DECLARATION(max)
	MOD1_GENERATE_GET_DECLARATION(delta)
	MOD1_GENERATE_GET_DECLARATION(final_min)
	MOD1_GENERATE_GET_DECLARATION(final_max)

private :

	MOD1_PLANE_COLOR_DATA				color_data;
	using 								mod1_engine_gl::model::data;

	bool								is_set = false;

	int 								get_index(
										const point2<int> &iter,
										const mod1_indexing_convention &convention = convention_dual_first) const;
public : // todo delete later

	void 								*get_ptr(
										const point2<int> &iter,
										const model_slot &slot,
										const mod1_indexing_convention &convention = convention_dual_first);
	void const							*get_ptr(
										const point2<int> &iter,
										const model_slot &slot,
										const mod1_indexing_convention &convention = convention_dual_first) const;

	void								update_normal_helper(
										const int &index_a,
										const int &index_b,
										const int &index_c);

};