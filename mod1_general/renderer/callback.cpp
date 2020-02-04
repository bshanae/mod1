#include "renderer.h"

void				::renderer::callback(const class event &event, void *ptr)
{
	auto 			*renderer = (::renderer *)ptr;

	if (event.read_type() != event_type::press)
		return ;
	if (event.read_key() == GLFW_KEY_5)
	{
		renderer->framebuffer.bind();
		renderer->render_call();
		framebuffer::unbind();

		renderer->blur.program.start();
		renderer->framebuffer.texture().bind();
		texture::activate();
		renderer->blur.program.texture.upload(0);
		renderer->blur.square.draw();
		texture::unbind();
		program::stop();

		renderer->core.swap_buffers();
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