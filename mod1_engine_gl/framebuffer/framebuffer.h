#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/texture/texture.h"

class					mod1_engine_gl::framebuffer
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_attachment_a, "Mod1 Engine GL, Framebuffer : No texture attached")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_attachment_b, "Mod1 Engine GL, Framebuffer : A texture is already attached")

						framebuffer();
						~framebuffer();

	void				start();
	void 				stop();

	void				attach_texture(const int &width, const int &height);
	void				attach_texture(const texture *attachment);

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(const class texture *, texture, nullptr)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(texture)

};
