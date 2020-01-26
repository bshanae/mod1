#include "framebuffer.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment)

					framebuffer::framebuffer()
{
	glGenFramebuffers(1, &object);
}

					framebuffer::~framebuffer()
{
	glDeleteFramebuffers(1, &object);
	delete texture;
}

void				framebuffer::start()
{
	glBindFramebuffer(GL_FRAMEBUFFER, object);
}

void 				framebuffer::stop()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void				framebuffer::attach_texture(const int &width, const int &height)
{
	attach_texture(new class texture(width, height));
}

void				framebuffer::attach_texture(const class texture *attachment)
{
	if (texture)
		throw (exception_attachment());

	texture = attachment;
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, texture->object(), 0);
}
