#pragma once

using namespace		mod1_algorithm;

template			<typename color_type>
point3<float>		plane<color_type>::read_point(const point2<int> &iter) const
{

	return (point3<float>(
		(float *) pointer(iter, model_slot::point, index_convention::dual_first),
		point3<float>::convention_xzy));
}

template			<typename color_type>
float				plane<color_type>::read_height(const point2<int> &iter) const
{
	return (((float *)pointer(iter, model_slot::point, index_convention::dual_first))[1]);
}