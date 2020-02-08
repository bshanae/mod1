#pragma once

using namespace		mod1_algorithm;

template			<typename color_type>
void 				*plane<color_type>::pointer(
					const point2<int> &iter,
					const model_slot &slot,
					const index_convention &convention)
{
	return (mod1_engine_gl::model::pointer(index(iter, convention), slot));
}

template			<typename color_type>
void const			*plane<color_type>::pointer(
					const point2<int> &iter,
					const model_slot &slot,
					const index_convention &convention) const
{
	return (mod1_engine_gl::model::pointer(index(iter, convention), slot));
}