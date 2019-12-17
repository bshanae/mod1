#include "mod1_map.h"

void						mod1_map::source_parse(const std::string &file)
{
	std::ifstream			stream;
	int 					temp_char;
	int 					temp_int;
	MOD1_MAP_DATA_TYPE_RI	map_iter;

	stream.open(file);

	if (!stream.is_open())
		global_error->raise_error("Map : Invalid file");

	while ((temp_char = stream.peek()) != EOF)
		switch (temp_char)
		{
			case ' ' : case ')' : case ',' : case '\n' :
			{
				stream.get();
				continue ;
			}
			case '(' :
			{
				source_height++;
				source_data.emplace_back(std::vector<int>());
				map_iter = source_data.rbegin();
				stream.get();
				continue ;
			}
			case '0' ... '9' :
			{
				if (source_height == 1)
					source_width++;
				stream >> temp_int;
				map_iter->push_back(temp_int);
				continue ;
			}
			default :
				global_error->raise_error("Map : Unknown character [%c]", temp_char);
		}

	stream.close();
}

void						mod1_map::source_print()
{
	printf("Mod1 Map :\n");
	for (const auto &row : source_data)
	{
		printf("{");
		for (const auto &item : row)
		{
			printf("%d", item);
			if (item != row.back())
				printf(", ");
		}
		printf("}\n");
	}
	printf("width = %d, height = %d\n", source_width, source_height);
	printf("\n");
}

int							mod1_map::source_get_value(const mod1_point_2i &point)
{
	if (point.x < 0 || point.x >= source_width)
		throw (mod1_map::exception_bad_coordinate());
	if (point.y < 0 || point.y >= source_height)
		throw (mod1_map::exception_bad_coordinate());
	return (source_data.at(point.y).at(point.x));
}