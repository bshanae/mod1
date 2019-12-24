#pragma once

#include "mod1_error.h"
#include "mod1_model.h"
#include "mod1_point2.h"
#include "mod1_point3.h"

#include <fstream>
#include <vector>

#define MOD1_MAP_VECTOR		std::vector<mod1_point3<int>>
#define MOD1_MAP_VECTOR_RI	MOD1_MAP_VECTOR::reverse_iterator
#define MOD1_MAP_DEF_DELTA	100
#define MOD1_MAP_DEF_SIZE	mod1_point3<int>(1000)
#define MOD1_MAP_INDENT		0.3
#define MOD1_MAP_MIN_COUNT	100

class						mod1_map : public mod1_model
{
public :

							mod1_map() = default;
							~mod1_map() = default;

	struct					exception_bad_coordinate : public std::exception
	{
		const char *		what() const throw() override;
	};

	void					source_parse(const std::string &file);
	void 					source_print();

	void					model_build();
	void					model_print(bool point = true, bool normal = true, bool polygon = true);

private :

	MOD1_MAP_VECTOR			source_data;
	mod1_point3<int>		source_min = mod1_point3<int>(INT_MAX, INT_MAX, INT_MAX);
	mod1_point3<int>		source_max = mod1_point3<int>(-INT_MAX, -INT_MAX, -INT_MAX);

	static float			source_read_float(std::ifstream &stream, bool eat_delimiter);
	void					source_update_min(const mod1_point3<int> &test);
	void					source_update_max(const mod1_point3<int> &test);

	typedef enum
	{
		mod1_map_slot_point,
		mod1_map_slot_normal,
		mod1_map_slot_color
	}						mod1_map_slot;

	mod1_point2<int>		model_min;
	mod1_point2<int>		model_max;
	mod1_point2<int>		model_size;
	int						model_delta = 0;

	void					model_update_delta(const int &i, const int &j, const int &index);
	void					model_optimize_delta(const mod1_point3<int> &diff);

	static float			model_interpolate_linear(int min, int max, float ratio);
	static float			model_interpolate_cosine(int min, int max, float ratio);
	static float			model_interpolate_smooth(int min, int max, float ratio);

	bool					model_write_height(const mod1_point2<int> &iter, const float &height);
	void					model_generate_hill(const mod1_point3<int> &summit);

	int 					model_get_index(const mod1_point2<int> &iter);
	float					*model_get_ptr(const mod1_point2<int> &iter, mod1_map_slot slot);
	mod1_point2<int>		model_find_ptr(const mod1_point3<int> &object);

	void					model_prepare();
};
