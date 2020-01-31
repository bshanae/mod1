#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/texture/texture.h"

class						mod1_engine_gl::framebuffer
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_complete, "Mod1 Engine GL, Framebuffer : Object is not complete")

							framebuffer(const int &width, const int &height);
							~framebuffer();

	void					start();
	void 					stop();

	const texture			&texture();

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

	class texture			*texture_color = nullptr;
	class texture			*texture_depth = nullptr;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)
};
