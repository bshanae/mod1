#include "water.h"

using namespace			mod1_algorithm;

void					water::add_color(const point3<float> &color, const water_color_type &type)
{

}

void					water::add_color(const point3<int> &color, const water_color_type &type)
{

}


void					water::update_color(const bool &save)
{
	point2<int> iter;
	point3<float> color;
	float total;

	auto color_a_ = point3<float>(116,204,244);
	auto color_b_ = point3<float>(15,94,156);

	auto color_a = point3<float>(color_a_ / 255.f);
	auto color_b = point3<float>(color_b_ / 255.f);

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
		{
			total = read_water_depth(iter);
			for (int i = 0; i < 3; i++)
				color[i] = terrain::interpolate_cosine(
					color_a[i],
					color_b[i],
					total / 100);
			write_color(iter, point4<float>(color, 0.7));
		}

	if (save)
		model::save(model_slot::color);
}