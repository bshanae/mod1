#include "terrain.h"

using namespace		mod1_algorithm;

void				terrain::check_extension(const std::string &path, const std::string &extension)
{
	const char		*raw;

	raw = strrchr(path.c_str(), '.');
	if (not raw or std::string(raw) != extension)
		throw (exception_extension());
}