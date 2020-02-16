#include "general.h"

void				general::functor_key(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	const int 		key = event.read_key();

	if (key == GLFW_KEY_ESCAPE && general->gui_level == level::render)
		general->render_block(true);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_a)
		general->render_block(false);
	else if (key == GLFW_KEY_ESCAPE && general->gui_level == level::menu_b)
		general->run_gui_front();
}

void				general::functor_drag(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	float			angle;

	angle = -1 * (event.read_diff().x / (float)general->window_width()) * general->rotation_speed;
	general->rotation = glm::rotate(general->rotation, glm::radians(angle), general->rotation_axis);

	general->request_render();
}

void				general::functor_gravity(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->MOD1_INTERNAL(water)->gravity();
	general->request_render();
}

void				general::functor_fps(void *ptr)
{
	static int 		number_of_frames = 0;
	static double	last_time;

	const double	currentTime = glfwGetTime();

	number_of_frames++;
	if (currentTime - last_time >= 1.)
	{
		std::cout << "FPS : " << 1000.0 / (double)number_of_frames << std::endl;
		number_of_frames = 0;
		last_time += 1.;
	}
}

//					GUI

void				general::functor_continue(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->render_block(false);
}

void				general::functor_scenarios(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->run_blur();
	general->run_gui_scenarios();
}

void				general::functor_exit(void *ptr)
{
	auto 			*general = (::general *)ptr;

	general->finish();
}