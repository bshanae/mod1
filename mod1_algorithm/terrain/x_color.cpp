#include "terrain.h"

using namespace		mod1_algorithm;

void				terrain::add_color(const point3<float> &color, const terrain_color_type &type)
{
	if (type == terrain_color_type::positive)
		color_data_positive.push_back(color);
	else if (type == terrain_color_type::negative)
		color_data_negative.push_back(color);
}

void 				terrain::add_color(const point3<int> &color, const terrain_color_type &type)
{
	auto			color_f = (point3<float>)color;

	color_f /= 255;
	add_color(color_f, type);
}

point4<float>		terrain::compute_color(const float &height) const
{
	auto 			&color_data = height >= 0 ? color_data_positive : color_data_negative;
	auto 			min = height >= 0 ? 0 : final_min().z;
	auto 			max = height >= 0 ? final_max().z : 0;

	float			ratio;
	int 			index_from;
	int 			index_to;
	float			ratio_normal;
	point3<float>	result;

#define COLOR_ALPHA 1

	if (color_data.empty())
		throw (exception_color());
	if (color_data.size() == 1)
		return (point4<float>(color_data[0], COLOR_ALPHA));

	ratio = (height - min) / (max - min) * (float)(color_data.size() - 1);

	index_from = floor(ratio);
	index_to = index_from + 1;
	ratio_normal = ratio - floor(ratio);

	if (index_to == (int)color_data.size())
		return (point4<float>(color_data[index_from], COLOR_ALPHA));

	for (int i = 0; i < 3; i++)
		result[i] = interpolate_linear(color_data[index_from][i], color_data[index_to][i], ratio_normal);
	result = point3<float>::min(result, point3<float>(1.f));
	return (point4<float>(result, COLOR_ALPHA));
}

void 				terrain::update_color(const bool &save)
{
	point2<int>			iter;
	point4<float>		color;

	for (iter.y = 0; iter.y < size().y - 1; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
		{
			color = compute_color(read_height(iter));
			write_color(iter, color);
		}

	if (save)
		model::save(model_slot::color);
}