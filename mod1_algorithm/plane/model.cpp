#include "plane.h"

using namespace					mod1_algorithm;

mod1_engine_gl::model			*plane::model()
{
	return ((mod1_engine_gl::model *)this);
}

const mod1_engine_gl::model		*plane::model() const
{
	return ((mod1_engine_gl::model *)this);
}