#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/texture/texture.h"

class				mod1_engine_gl::framebuffer
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_attachment,
	"Mod1 Engine GL, Framebuffer : A texture is already attached")

					framebuffer();
					~framebuffer();

	void			start();
	void 			stop();

	void			attach_texture(const int &width, const int &height);
	void			attach_texture(const texture *attachment);

private :

	GLuint			object;
	const texture	*texture = nullptr;
};


