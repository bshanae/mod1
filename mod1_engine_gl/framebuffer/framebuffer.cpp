#include "framebuffer.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_complete)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(framebuffer, object)

					framebuffer::framebuffer(const int &width, const int &height)
{
	glGenFramebuffers(1, &MOD1_INTERNAL(object));

	start();

	texture_color = new mod1_engine_gl::texture(texture_type::color, width, height);
	texture_depth = new mod1_engine_gl::texture(texture_type::depth, width, height);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture_color->object(), 0);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, texture_depth->object(), 0);

	GLenum			DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};

	glDrawBuffers(1, DrawBuffers);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		throw (exception_complete());

	stop();
}

					framebuffer::~framebuffer()
{
	glDeleteFramebuffers(1, &MOD1_INTERNAL(object));
}

void				framebuffer::start()
{
	glBindFramebuffer(GL_FRAMEBUFFER, MOD1_INTERNAL(object));
}

void 				framebuffer::stop()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const texture		&framebuffer::texture()
{
	return (*texture_color);
}