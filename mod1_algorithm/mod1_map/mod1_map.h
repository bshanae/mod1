#pragma once

#include "mod1_error.h"
#include "mod1_model.h"
#include "mod1_point_x.h"

#include <fstream>
#include <vector>

#define MOD1_MAP_DATA_TYPE		std::vector<std::vector<int>>
#define MOD1_MAP_DATA_TYPE_RI	std::vector<std::vector<int>>::reverse_iterator

class							mod1_map : public mod1_model
{
public :

	struct						exception_bad_coordinate : public std::exception
	{
		 const char *			what() const throw() override;
	};

								mod1_map();
								~mod1_map() = default;

	void						source_parse(const std::string &file);
	void 						source_print();

	void						model_build(int additional_points = 1, float min = -50.f, float max = 50.f);
	void						model_print(
		bool print_raw = false, bool print_y = true,
		bool print_index = false, bool print_polygon = false);

private :

	MOD1_MAP_DATA_TYPE			source_data;
	int 						source_width;
	int 						source_height;
	int							model_width;
	int							model_height;

	int							source_get_value(const mod1_point_2i &point);

	int							model_get_index(const mod1_point_2i &point);
	mod1_point_3f				*model_get_ptr(const mod1_point_2i &point);
	void						model_test_point(const mod1_point_2i &point, int &count_filled, int &count_valid, float &sum);
	bool						model_restore_point(const mod1_point_2i &point);

};
