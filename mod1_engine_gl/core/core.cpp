#include "core.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_logic_object)
MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_logic_callback)
MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_window)
MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_GLEW)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(core, window_width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(core, window_height)

					core::core()
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

	window = glfwCreateWindow(
		MOD1_INTERNAL(window_width),
		MOD1_INTERNAL(window_height),
		window_name.c_str(),
		nullptr, nullptr);
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

	MOD1_INTERNAL(window_width) = width;
	MOD1_INTERNAL(window_height) = height;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);

#if MOD1_ENABLED(MOD1_DEPTH_TEST)
	glEnable(GL_DEPTH_TEST);
#endif

#if MOD1_DISABLED(MOD1_SHOW_BACK_OF_POLYGON)
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
#endif

#if MOD1_ENABLED(MOD1_SRGB)
	glEnable(GL_FRAMEBUFFER_SRGB);
#endif
}

					core::~core()
{
	glfwTerminate();
}

bool				core::is_working() const
{
	return (glfwWindowShouldClose(window));
}

void				core::terminate() const
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}

void				core::update() const
{
	glfwPollEvents();
}

void 				core::clear(const point3<float> &color)
{
	glClearColor(color.x, color.y, color.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void 				core::draw_elements(const int &count)
{
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}

void 				core::draw_arrays(const int &count)
{
	glDrawArrays(GL_TRIANGLES, 0, count);
}

void				core::swap_buffers()
{
	glfwSwapBuffers(window);
}

void				core::set_callback(mod1_callback function, void *ptr)
{
	static int 		count;

	if (count++ > 0)
		throw (exception_logic_callback());

	glfwSetWindowUserPointer(window, ptr);
	glfwSetKeyCallback(window, function);
}