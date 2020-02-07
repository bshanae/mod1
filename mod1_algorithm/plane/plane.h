#pragma once

#include "mod1_algorithm/namespace.h"

enum class								mod1_algorithm::plane_color
{
	positive,
	negative
};

class									mod1_algorithm::plane : protected mod1_engine_gl::model
{
public :
										plane() = default;
										~plane() override = default;

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_coordinate, "Mod1 Plane : Bad coordinate")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_logic, "Mod1 Plane : Object not set")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_color, "Mod1 Plane : Too few colors defined")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_index_convention, "Mod1 Plane : Unknown index convention")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_cut_style, "Mod1 Plane : Unknown cut style")

	void								set(
										const point2<float> &min,
										const point2<float> &max,
										const float &delta);
	void								build() override;

	virtual mod1_engine_gl::model		*model();
	virtual const mod1_engine_gl::model	*model() const;

protected :

	enum class							index_convention
	{
		single,
		dual_first,
		dual_second
	};

	point3<float>						read_point(const point2<int> &iter) const;
	float								read_height(const point2<int> &iter) const;

	bool								write_height(const point2<int> &iter, const float &z);
	void								write_color(const point2<int> &iter, const point4<float> &color);

	bool 								is_dual(const point2<int> &iter) const;
	bool								is_valid(
										const point2<int> &iter,
										const model_slot &slot,
										const index_convention &convention = index_convention::dual_first) const;

	void 								update_normal(const bool &save = false);

	void 								update_final();

	void								add_color(const plane_color &type, const point3<float> &color);
	void 								add_color(const plane_color &type, const point3<int> &color);
	void								define_alpha(const float &alpha);
	void								define_alpha(const int &alpha);
	void 								update_color();

	enum class							cut_style
	{
		upwards,
		downwards
	};

	cut_style							get_cut_style(const point2<int> &iter);
	void								switch_cut_style(const point2<int> &iter);

private :

MOD1_GENERATE_INTERNAL(point2<int>, size)
MOD1_GENERATE_INTERNAL(point2<float>, min)
MOD1_GENERATE_INTERNAL(point2<float>, max)
MOD1_GENERATE_INTERNAL_WITH_VALUE(float, delta, 0)

MOD1_GENERATE_INTERNAL(point2<int>, real_size)

MOD1_GENERATE_INTERNAL(point3<float>, final_min)
MOD1_GENERATE_INTERNAL(point3<float>, final_max)

	MOD1_PLANE_COLOR_DATA				color_data_positive;
	MOD1_PLANE_COLOR_DATA				color_data_negative;
	float								color_alpha = 1;
	buffer2<cut_style>					cut_style_data;

	bool								is_set = false;

	int 								index(
										const point2<int> &iter,
										const index_convention &convention = index_convention::dual_first) const;
	void 								*pointer(
										const point2<int> &iter,
										const model_slot &slot,
										const index_convention &convention = index_convention::dual_first);
	void const							*pointer(
										const point2<int> &iter,
										const model_slot &slot,
										const index_convention &convention = index_convention::dual_first) const;

	void								update_normal_helper(
										const int &index_a,
										const int &index_b,
										const int &index_c);

	point4<float>						compute_color(const float &height) const;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(real_size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(min)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(max)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(delta)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(final_min)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(final_max)

};