#pragma once

#include "mod1_error.h"
#include "mod1_model.h"
#include "mod1_point3.h"

#include <fstream>
#include <vector>

#define MOD1_MAP_VECTOR		std::vector<mod1_point3<int>>
#define MOD1_MAP_VECTOR_RI	MOD1_MAP_VECTOR::reverse_iterator

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

private :

	MOD1_MAP_VECTOR			source_data;
	mod1_point3<int>		source_min = mod1_point3<int>(INT_MAX, INT_MAX, INT_MAX);
	mod1_point3<int>		source_max = mod1_point3<int>(-INT_MAX, -INT_MAX, -INT_MAX);

	static float			source_read_float(std::ifstream &stream, bool eat_delimiter);
	void					source_update_min(const mod1_point3<int> &test);
	void					source_update_max(const mod1_point3<int> &test);

	mod1_point2<int>		model_min;
	mod1_point2<int>		model_max;
	int						model_delta;

	void					model_update_delta(const int &i, const int &j, const int &index);
	void					model_prepare();
};
