#include "plane.h"

using namespace			mod1_algorithm;

void					plane::add_color(const plane_color &type, const point3<float> &color)
{
	if (type == plane_color::positive)
		color_data_positive.push_back(color);
	else if (type == plane_color::negative)
		color_data_negative.push_back(color);
}

void					plane::add_color(const plane_color &type, const point3<int> &color)
{
	auto				color_f = (point3<float>)color;

	color_f /= 255;
	if (type == plane_color::positive)
		color_data_positive.push_back(color_f);
	else if (type == plane_color::negative)
		color_data_negative.push_back(color_f);
}

#define INTERPOLATE(a, b, r)	(a + (b - a) * r)

point3<float>			plane::compute_color(const float &height) const
{
	auto 				&color_data = height >= 0 ? color_data_positive : color_data_negative;

	float				ratio;
	int 				index_from;
	int 				index_to;
	float				ratio_normal;
	point3<float>		result;

	if (color_data.empty())
		throw (exception_color());
	if (color_data.size() == 1)
		return (color_data[0]);

	ratio =
		(height - final_min_internal.z) /
		(final_max_internal.z - final_min_internal.z) *
		(float)(color_data.size() - 1);

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

void					plane::update_color()
{
	point2<int>			iter;
	point3<float>		color;

	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x; iter.x++)
		{
			color = compute_color(read_height(iter));
			write_color(iter, color);
		}

}