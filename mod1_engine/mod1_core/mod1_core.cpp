#include "mod1_core.h"

					mod1_core::mod1_core()
{
	static int 		count;

	if (count++ > 0)
		throw (exception_logic_object());

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(window_width_internal, window_height_internal, window_name.c_str(), nullptr, nullptr);
	if (!window)
		throw (exception_window());
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw (exception_GLEW());

	int				width;
	int 			height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
}

					mod1_core::~mod1_core()
{
	glfwTerminate();
}

bool				mod1_core::is_working()
{
	return (glfwWindowShouldClose(window));
}

int					mod1_core::window_width()
{
	return (window_width_internal);
}

int					mod1_core::window_height()
{
	return (window_height_internal);
}

void				mod1_core::update()
{
	glfwPollEvents();
}

void				mod1_core::swap_buffers()
{
	glfwSwapBuffers(window);
}

void				mod1_core::set_callback(mod1_callback function, void *ptr)
{
	static int 		count;

	if (count++ > 0)
		throw (exception_logic_callback());

	glfwSetWindowUserPointer(window, ptr);
	glfwSetKeyCallback(window, function);
}

const char			*mod1_core::exception_logic_object::what() const noexcept
{
	return ("Mod1 Core : Can't create more than one core");
}

const char			*mod1_core::exception_logic_callback::what() const noexcept
{
	return ("Mod1 Core : Can't create more than one callback");
}

const char			*mod1_core::exception_window::what() const noexcept
{
	return ("Mod1 Core : Can't initialize window");
}

const char			*mod1_core::exception_GLEW::what() const noexcept
{
	return ("Mod1 Core : Can't initialize GLEW");
}