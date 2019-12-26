#pragma once

#include "mod1_error.h"
#include "mod1_model.h"
#include "mod1_point2.h"
#include "mod1_point3.h"

#include <fstream>
#include <vector>

#define MOD1_MAP_DATA		std::vector<mod1_point3<int>>
#define MOD1_MAP_DATA_RI	MOD1_MAP_DATA::reverse_iterator
#define MOD1_MAP_COLOR		std::vector<mod1_point3<float>>
#define MOD1_MAP_DEF_DELTA	100
#define MOD1_MAP_DEF_SIZE	mod1_point3<int>(1000)
#define MOD1_MAP_INDENT		0.3
#define MOD1_MAP_MIN_COUNT	10

class						mod1_terrain : public mod1_model
{
public :
							mod1_terrain() = default;
							~mod1_terrain() = default;

	struct					exception_bad_coordinate : public std::exception
	{
		const char *		what() const throw() override;
	};

	void					source_parse(const std::string &file);
	void 					source_print() const;

	void					model_push_color(const mod1_point3<float> &color);
	mod1_point3<float>		model_get_color(const float &height) const;

	void					model_build();
	void					model_print(bool point = true, bool normal = true, bool polygon = true) const;

	friend class			mod1_water;

private :

	MOD1_MAP_DATA			source_data;
	mod1_point3<int>		source_min = mod1_point3<int>(INT_MAX, INT_MAX, INT_MAX);
	mod1_point3<int>		source_max = mod1_point3<int>(-INT_MAX, -INT_MAX, -INT_MAX);
	mod1_point3<int>		source_diff;

	static float			source_read_float(std::ifstream &stream, bool eat_delimiter);

	MOD1_MAP_COLOR			color_data;

	mod1_point2<int>		model_min;
	mod1_point2<int>		model_max;
	mod1_point2<int>		model_size;
	int						model_delta = 0;

	void					model_update_delta(const int &i, const int &j, const int &index);
	void 					model_compute_delta();
	void					model_optimize_delta();

	static float			model_interpolate_linear(float min, float max, float ratio);
	static float			model_interpolate_cosine(float min, float max, float ratio);
	static float			model_interpolate_smooth(float min, float max, float ratio);

	bool					model_write_height(const mod1_point2<int> &iter, const float &height);
	void					model_generate_hill(const mod1_point3<int> &summit);

	int 					model_get_index(const mod1_point2<int> &iter) const;
	void					*model_get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const;
	mod1_point2<int>		model_find_ptr(const mod1_point3<int> &object) const;

	void					model_prepare();
};
