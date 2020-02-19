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
	float				depth;

	for (iter.y = 0; iter.y < size().y - 1; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
		{
			if ((depth = read_water_depth(iter)) <= MOD1_WATER_MINIMUM)
				depth = MOD1_WATER_HIDDEN_ABSTRACT;

			for (int i = 0; i < 3; i++)
				color[i] = terrain::interpolate_linear(color_max[i], color_min[i], depth / terrain_range);
			write_color(iter, point4<float>(color, color_alpha));
		}

	if (save)
		model::save(model_slot::color);
}