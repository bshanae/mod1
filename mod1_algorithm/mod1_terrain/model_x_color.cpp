#include "mod1_terrain.h"

void					mod1_terrain::model_push_color(const mod1_point3<float> &color)
{
	color_data.push_back(color);
}

mod1_point3<float>		mod1_terrain::model_get_color(const float &height) const
{
	float				ratio;
	int 				index_from;
	int 				index_to;
	float				ratio_normal;
	mod1_point3<float>	result;

	if (color_data.size() < 2)
		global_error->raise_error("Map : Too few colors defined");
	ratio = height / source_max.z * color_data.size();

	index_from = floor(ratio);
	index_to = index_from + 1;
	ratio_normal = ratio - floor(ratio);

	if (index_from == color_data.size() - 1)
		return (color_data[index_from]);

	for (int i = 0; i < 3; i++)
		result[i] = model_interpolate_linear(color_data[index_from][i], color_data[index_to][i], ratio_normal);
	result = mod1_point3<float>::min(result, mod1_point3<float>(1.f));
	return (result);
}