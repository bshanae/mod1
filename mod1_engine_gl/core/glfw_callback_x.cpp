#include "core.h"

using namespace		mod1_engine_gl;

void				core::glfw_callback_key(GLFWwindow* window, int key, int code, int action, int mode)
{
	auto			*core = (mod1_engine_gl::core *)glfwGetWindowUserPointer(window);

	code = 0;
	mode = 0;

	core->event.reset();
	if (action == GLFW_PRESS)
		core->event.type = event_type::key_press;
	else if (action == GLFW_RELEASE)
		core->event.type = event_type::key_release;
	else if (action == GLFW_REPEAT)
		core->event.type = event_type::key_hold;
	else
		return ;
	core->event.key = key;
}

void				core::glfw_callback_mouse_movement(GLFWwindow* window, double x, double y)
{
	auto			*core = (mod1_engine_gl::core *)glfwGetWindowUserPointer(window);
	auto			old = core->event.mouse;

	core->event.reset();
	core->event.type = core->event.mouse_hold ? event_type::mouse_drag : event_type::mouse_move;
	core->event.mouse = point2<float>(x, y) * core->MOD1_INTERNAL(window_multiplier);
	core->event.mouse_diff = old - core->event.mouse;
}

void				core::glfw_callback_mouse_key(GLFWwindow* window, int key, int action, int mode)
{
	auto			*core = (mod1_engine_gl::core *)glfwGetWindowUserPointer(window);

	mode = 0;

	core->event.reset();
	if (key != GLFW_MOUSE_BUTTON_LEFT)
		return ;
	core->event.type = event_type::none;
	if (action == GLFW_PRESS)
	{
		core->event.type = event_type::mouse_press;
		core->event.mouse_hold = true;
	}
	else if (action == GLFW_RELEASE)
	{
		core->event.type = event_type::mouse_release;
		core->event.mouse_hold = false;
	}
}
