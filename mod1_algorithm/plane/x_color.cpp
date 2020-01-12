#include "plane.h"

using namespace		mod1_algorithm;

void					plane::add_color(const point3<float> &color)
{
	color_data.push_back(color);
}

void					plane::add_color(const point3<int> &color)
{
	auto				color_f = (point3<float>)color;

	color_f /= 255;
	color_data.push_back(color_f);
}

#define INTERPOLATE(a, b, r)	(a + (b - a) * r)

point3<float>		plane::compute_color(const float &height) const
{
	float				ratio;
	int 				index_from;
	int 				index_to;
	float				ratio_normal;
	point3<float>	result;

	if (color_data.empty())
		throw (exception_color());
	if (color_data.size() == 1)
		return (color_data[0]);

	ratio = (height - final_min_internal.z) / (final_max_internal.z - final_min_internal.z) * (float)(color_data.size() - 1);

	index_from = floor(ratio);
	index_to = index_from + 1;
	ratio_normal = ratio - floor(ratio);

	if (index_to == color_data.size())
		return (color_data[index_from]);

	for (int i = 0; i < 3; i++)
		result[i] = INTERPOLATE(color_data[index_from][i], color_data[index_to][i], ratio_normal);
	result = point3<float>::min(result, point3<float>(1.f));
	return (result);
}