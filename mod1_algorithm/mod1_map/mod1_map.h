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

	void						model_build(int additional_points = 1);
	void						model_print();

private :

	MOD1_MAP_DATA_TYPE			source_data;
	int 						source_width;
	int 						source_height;
	int							model_width;
	int							model_height;

	int							source_get_value(const mod1_point_2i &point);

	mod1_point_3f				*model_get_ptr(const mod1_point_2i &point);
	bool						model_restore_point(const mod1_point_2i &point);
};
