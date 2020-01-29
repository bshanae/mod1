#include "framebuffer.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_a)
MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_b)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(framebuffer, object)

					framebuffer::framebuffer()
{
	glGenFramebuffers(1, &MOD1_INTERNAL(object));

	attach_texture(MOD1_WINDOW_WIDTH, MOD1_WINDOW_HEIGHT);

	start();

//	GLuint colorRenderbuffer;
//	glGenRenderbuffers(1, &colorRenderbuffer);
//	glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGB, MOD1_WINDOW_WIDTH, MOD1_WINDOW_HEIGHT);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderbuffer);

	GLuint depthRenderbuffer;

	glGenRenderbuffers(1, &depthRenderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, MOD1_WINDOW_WIDTH, MOD1_WINDOW_HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture_internal->object(), 0);

	GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, DrawBuffers);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		exit(1);

	stop();
}

					framebuffer::~framebuffer()
{
	glDeleteFramebuffers(1, &MOD1_INTERNAL(object));
	delete MOD1_INTERNAL(texture);
}

void				framebuffer::start()
{
	glBindFramebuffer(GL_FRAMEBUFFER, MOD1_INTERNAL(object));
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
	if (MOD1_INTERNAL(texture))
		throw (exception_attachment_b());

	MOD1_INTERNAL(texture) = attachment;

	start();

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, MOD1_INTERNAL(texture)->object(), 0);
	stop();
}

const texture		*framebuffer::texture() const
{
	if (not MOD1_INTERNAL(texture))
		throw (exception_attachment_a());

	return (MOD1_INTERNAL(texture));
}