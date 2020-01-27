#include "framebuffer.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_a)
MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_b)

					framebuffer::framebuffer()
{
	glGenFramebuffers(1, &object);
}

					framebuffer::~framebuffer()
{
	glDeleteFramebuffers(1, &object);
	delete texture_internal;
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
	if (texture_internal)
		throw (exception_attachment_b());

	start();
	texture_internal = attachment;
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, texture_internal->object(), 0);
	stop();
}

const texture		&framebuffer::texture() const
{
	if (not texture_internal)
		throw (exception_attachment_a());

	return (*texture_internal);
}