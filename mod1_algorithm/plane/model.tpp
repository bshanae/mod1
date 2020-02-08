#pragma once

using namespace				mod1_algorithm;

template					<typename color_type>
mod1_engine_gl::model		*plane<color_type>::model()
{
	return ((mod1_engine_gl::model *)this);
}

template					<typename color_type>
const mod1_engine_gl::model	*plane<color_type>::model() const
{
	return ((mod1_engine_gl::model *)this);
}