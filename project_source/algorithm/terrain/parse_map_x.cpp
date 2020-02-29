#include "terrain.h"

using namespace					mod1_algorithm;

double							terrain::parse_map_coordinate(std::ifstream &stream, bool eat_delimiter)
{
	double						temp;

	if (eat_delimiter)
		if (stream.get() != ',')
			throw (exception_pattern());
	stream >> temp;
	return (temp);
}

void							terrain::parse_map(const std::string &file)
{
	std::ifstream				stream;
	int 						temp_char;
	MOD1_TERRAIN_RAW_DATA_RI	iter;

	check_extension(file, ".mod1");

	stream.open(file);

	if (!stream.is_open())
		throw (exception_source());

	while ((temp_char = stream.get()) != EOF)
		switch (temp_char)
		{
			case ' ' : case ')' : case ',' : case '\n' :
				break ;
			case '(' :
				data_raw.emplace_back();
				iter = data_raw.rbegin();
				break ;
			case '-' : case '0' ... '9' :
				stream.unget();
				iter->x = parse_map_coordinate(stream, false);
				iter->y = parse_map_coordinate(stream, true);
				iter->z = parse_map_coordinate(stream, true);
				min_raw = point3<double>::min(min_raw, *iter);
				max_raw = point3<double>::max(max_raw, *iter);
				break ;
			default :
				throw (exception_pattern());
		}

	stream.close();
	if (data_raw.size() >= 50)
		throw (exception_point_number());

	min_raw.z = min_raw.z <= 0 ? min_raw.z : 0;
}