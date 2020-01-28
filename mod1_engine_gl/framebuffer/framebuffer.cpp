#include "framebuffer.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_a)
MOD1_GENERATE_EXCEPTION_DEFINITION(framebuffer, exception_attachment_b)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(framebuffer, object)

					framebuffer::framebuffer()
{
	glGenFramebuffers(1, &MOD1_INTERNAL(object));

	start();
	glDrawBuffer(GL_COLOR_ATTACHMENT0);
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

	unsigned int depthrenderbuffer;
	glGenRenderbuffers(1, &depthrenderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, MOD1_INTERNAL(texture)->width(), MOD1_INTERNAL(texture)->height());
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);

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