#pragma once

#include "mod1_error.h"

#include <fstream>
#include <vector>

class								mod1_map
{

public :

	explicit mod1_map(const mod1_error &error);

	~mod1_map() = default;

	void							parse(const std::string &file);

	void 							print();

private :

	typedef std::vector<std::vector<int>> mod1_map_type;

	const mod1_error				&error;
	mod1_map_type					data;
	int 							width;
	int 							height;

};
