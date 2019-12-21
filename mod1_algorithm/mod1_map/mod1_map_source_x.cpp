#include "mod1_map.h"

float					mod1_map::source_read_float(std::ifstream &stream, bool eat_delimiter)
{
	float				temp;

	if (eat_delimiter)
		if (stream.get() != ',')
			global_error->raise_error("Map : Incorrect pattern");
	stream >> temp;
	return (temp);
}

void					mod1_map::source_update_min(const mod1_point3<int> &test)
{
	for (int i = 0; i < 3; i++)
		if (test[i] < source_min[i])
			source_min[i] = test[i];
}

void					mod1_map::source_update_max(const mod1_point3<int> &test)
{
	for (int i = 0; i < 3; i++)
		if (test[i] > source_max[i])
			source_max[i] = test[i];
}

void					mod1_map::source_parse(const std::string &file)
{
	std::ifstream		stream;
	int 				temp_char;
	MOD1_MAP_VECTOR_RI	iter;

	stream.open(file);

	if (!stream.is_open())
		global_error->raise_error("Map : Invalid file");

	while ((temp_char = stream.get()) != EOF)
		switch (temp_char)
		{
			case ' ' : case ')' : case ',' : case '\n' :
				continue ;
			case '(' :
			{
				source_data.emplace_back();
				iter = source_data.rbegin();
				continue ;
			}
			case '0' ... '9' :
			{
				stream.unget();
				iter->x = source_read_float(stream, false);
				iter->y = source_read_float(stream, true);
				iter->z = source_read_float(stream, true);
				source_update_min(*iter);
				source_update_max(*iter);
				continue ;
			}
			default :
				global_error->raise_error("Map : Unknown character [%c]", temp_char);
		}

	stream.close();
}

void						mod1_map::source_print()
{
	printf("Mod1 Map :\n{\n");
	for (const auto &point : source_data)
		printf("\t{%d, %d, %d}\n", point.x, point.y, point.z);
	printf("}\n");
	printf("min = {%d, %d, %d}\n", source_min.x, source_min.y, source_min.z);
	printf("max = {%d, %d, %d}\n", source_max.x, source_max.y, source_max.z);
}