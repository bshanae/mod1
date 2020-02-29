#include "terrain.h"

using namespace				mod1_algorithm;

mod1_engine_gl::model		*terrain::model()
{
	return ((mod1_engine_gl::model *)this);
}

const mod1_engine_gl::model	*terrain::model() const
{
	return ((mod1_engine_gl::model *)this);
}