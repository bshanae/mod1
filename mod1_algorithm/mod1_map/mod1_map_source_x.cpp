#include "mod1_map.h"

float					mod1_map::source_read_float(std::ifstream &stream, bool get_space)
{
	float				temp;

	if (get_space)
		if (stream.get() != ' ')
			global_error->raise_error("Map : Incorrect pattern");
	stream >> temp;
	return (temp);
}

void					mod1_map::source_update_min(const mod1_point_3f &test)
{
	if (test.x < source_min.x)
		source_min.x = test.x;
}

void					mod1_map::source_update_max(const mod1_point_3f &test)
{

}

void					mod1_map::source_parse(const std::string &file)
{
	std::ifstream		stream;
	int 				temp_char;
	float 				temp_float;
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