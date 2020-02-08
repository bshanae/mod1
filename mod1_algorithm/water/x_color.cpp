#include "water.h"

using namespace			mod1_algorithm;

void					water::add_color(const point3<float> &color, const water_color_type &type)
{
	if (type == water_color_type::min)
	{
		if (color_min != point3<float>(std::numeric_limits<float>::infinity()))
			throw (exception_color_redefinition());
		color_min = color;
	}
	else if (type == water_color_type::max)
	{
		if (color_max != point3<float>(std::numeric_limits<float>::infinity()))
			throw (exception_color_redefinition());
		color_max = color;
	}
}

void					water::add_color(const point3<int> &color, const water_color_type &type)
{
	add_color(point3<float>(color) / 255.f, type);
}

void					water::update_color(const bool &save)
{
	point2<int>			iter;
	point3<float>		color;
	float				total;

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
		{
			total = read_water_depth(iter);
			for (int i = 0; i < 3; i++)
				color[i] = terrain::interpolate_cosine(
					color_max[i],
					color_min[i],
					total / 100);
			write_color(iter, point4<float>(color, color_alpha));
		}

	if (save)
		model::save(model_slot::color);
}