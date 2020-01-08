#include "mod1_terrain.h"

void					mod1_terrain::add_color(const mod1_point3<float> &color)
{
	data_color.push_back(color);
}

void					mod1_terrain::add_color(const mod1_point3<int> &color)
{
	auto				color_f = (mod1_point3<float>)color;

	color_f /= 255;
	data_color.push_back(color_f);
}

mod1_point3<float>		mod1_terrain::compute_color(const float &height) const
{
	float				ratio;
	int 				index_from;
	int 				index_to;
	float				ratio_normal;
	mod1_point3<float>	result;

	if (data_color.empty())
		throw (exception_color());
	if (data_color.size() == 1)
		return (data_color[0]);

	ratio = (height - final_min.z) / (final_max.z - final_min.z) * (float)(data_color.size() - 1);

	index_from = floor(ratio);
	index_to = index_from + 1;
	ratio_normal = ratio - floor(ratio);

	if (index_to == data_color.size())
		return (data_color[index_from]);

	if (height > 0)
		printf("%f : %d->%d, %f\n", height, index_from, index_to, ratio_normal);

	for (int i = 0; i < 3; i++)
		result[i] = interpolate_linear(data_color[index_from][i], data_color[index_to][i], ratio_normal);
	result = mod1_point3<float>::min(result, mod1_point3<float>(1.f));
	return (result);
}