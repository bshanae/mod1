#include "general.h"

void				general::callback(const mod1_engine_gl::event &event, void *ptr)
{
	auto 			*general = (::general *)ptr;

	if (event.read_type() != mod1_engine_gl::event_type::press)
		return ;
	if (event.read_key() == GLFW_KEY_5)
	{
		general->framebuffer.bind();
		general->render_call();
		mod1_engine_gl::framebuffer::unbind();

		general->blur.program.start();
		general->framebuffer.texture().bind();
		mod1_engine_gl::texture::activate();
		general->blur.program.texture.upload(0);
		general->blur.square.draw();
		mod1_engine_gl::texture::unbind();
		program::stop();

		general->core.swap_buffers();
	}
	else if (event.read_key() == GLFW_KEY_6)
	{
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		auto				*symbol = renderer->symbol_map['j'];
//
//#define X_START				100.f
//#define Y_START				100.f
//
//#define X_EXTEND			symbol->size().x
//#define Y_EXTEND			symbol->size().y
//
//		float			array[] = {
//			X_START, Y_START, 0,
//			X_START, Y_START + Y_EXTEND, 0,
//			X_START + X_EXTEND, Y_START, 0,
//			X_START + X_EXTEND, Y_START + Y_EXTEND, 0
//		};
//
//		renderer->square_text.buffer_point.copy(array);
//		renderer->square_text.update(model_slot::point);
//
//		renderer->program_text.start();
//		symbol->texture()->bind();
//		texture::activate();
//		renderer->square_text.draw();
//		texture::unbind();
//		program::stop();
//
//		renderer->core.swap_buffers();
	}
}