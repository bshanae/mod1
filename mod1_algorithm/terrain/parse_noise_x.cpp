#include "terrain.h"

using namespace					mod1_algorithm;

void							terrain::parse_noise_line(std::vector<noise_config> &target, std::stringstream &stream)
{
	char						color = 0;
	noise_config				noise;

	if (not (stream >> color) or color != ':')
		throw (exception_pattern());

	if (not (stream >> noise.frequency))
		throw (exception_pattern());
	if (not (stream >> noise.range))
		throw (exception_pattern());
	if (not (stream >> noise.offset))
		noise.offset = point2<int>();
	if (not (stream >> noise.power))
		noise.power = 1;

	target.push_back(noise);
}

void							terrain::parse_noise(const std::string &file_source)
{
	std::ifstream				file_stream;
	std::string					line_string;
	std::stringstream			line_stream;

	std::string					temp;

	if (file_source.empty())
		return ;

	file_stream.open(file_source);
	if (!file_stream.is_open())
		throw (exception_source());

	while (getline(file_stream, line_string))
	{
		line_stream = std::stringstream(line_string);
		getline(line_stream, temp, ' ');
		if (temp == "hill")
			parse_noise_line(noise_hill, line_stream);
		else if (temp == "general")
			parse_noise_line(noise_general, line_stream);
		else if (temp[0] != '#')
			throw (exception_pattern());
	}

	file_stream.close();
}