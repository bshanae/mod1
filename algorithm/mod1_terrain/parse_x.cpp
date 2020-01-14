#include "mod1_terrain.h"

float						mod1_terrain::parse_coordinate(std::ifstream &stream, bool eat_delimiter)
{
	float					temp;

	if (eat_delimiter)
		if (stream.get() != ',')
			throw (exception_pattern());
	stream >> temp;
	return (temp);
}

void						mod1_terrain::parse(const std::string &file)
{
	std::ifstream			stream;
	int 					temp_char;
	MOD1_TERRAIN_RAW_DATA_RI	iter;

	stream.open(file);

	if (!stream.is_open())
		throw (exception_source());

	while ((temp_char = stream.get()) != EOF)
		switch (temp_char)
		{
			case ' ' : case ')' : case ',' : case '\n' :
				continue ;
			case '(' :
			{
				data_raw.emplace_back();
				iter = data_raw.rbegin();
				continue ;
			}
			case '0' ... '9' :
			{
				stream.unget();
				iter->x = parse_coordinate(stream, false);
				iter->y = parse_coordinate(stream, true);
				iter->z = parse_coordinate(stream, true);
				min_raw = point3<int>::min(min_raw, *iter);
				max_raw = point3<int>::max(max_raw, *iter);
				continue ;
			}
			default :
				throw (exception_pattern());
		}

	stream.close();
	if (data_raw.size() >= 50)
		throw (exception_pattern());
}