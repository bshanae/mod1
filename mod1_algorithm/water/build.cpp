#include "water.h"

using namespace			mod1_algorithm;

void 					water::build()
{
	set_as_dynamic();

	MOD1_INTERNAL(ambient_receptivity) = 1.2;
	MOD1_INTERNAL(diffuse_receptivity) = 0.8;
	MOD1_INTERNAL(specular_receptivity) = 0.2;

	set(
		terrain->min() - point2<float>(terrain->delta() / 2),
		terrain->max() + point2<float>(terrain->delta() / 2),
		terrain->delta());
	plane::build();

	data_prepare();

	update_model();
	update_normal();
//	update_color();

	cl_build();
	cl_set();
	cl_link();
	cl_write();
}

void					water::_update_color(const bool &save)
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