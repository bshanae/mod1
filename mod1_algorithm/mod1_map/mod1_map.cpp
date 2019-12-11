#include "mod1_map.h"

									mod1_map::mod1_map()
{
	width = -1;
	height = -1;
}

void								mod1_map::parse(const std::string &file)
{
	std::ifstream					stream;
	int 							temp_char;
	int 							temp_int;
	mod1_map_type::reverse_iterator	map_iter;

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
				data.push_back(std::vector<int>());
				map_iter = data.rbegin();
				stream.get();
				continue ;
			}
			case '0' ... '9' :
			{
				stream >> temp_int;
				map_iter->push_back(temp_int);
				continue ;
			}
			default :
				global_error->raise_error("Unknown character [%c]", temp_char);
		}

	stream.close();
}

void								mod1_map::print()
{
	printf("Mod1 map :\n");
	for (const auto &row : data)
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
	printf("\n");

}