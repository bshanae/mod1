#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/program/program.h"
#include "mod1_engine_gl/framebuffer/framebuffer.h"
#include "mod1_engine_gl/model/model.h"
#include "mod1_engine_gl/camera/camera.h"
#include "mod1_engine_gl/event/event.h"
#include "mod1_engine_gl/callback/callback.h"
#include "mod1_engine_gl/uniform/uniform.h"
#include "mod1_engine_gl/point/point3.h"

//								TEST START

typedef struct
{
	GLuint						textureID;
	glm::ivec2					size;
	glm::ivec2					bearing;
	GLuint						advance;
}								Character;

//								TEST END

class							mod1_engine_gl::renderer
{

public :

								renderer();
	virtual						~renderer() = default;

	void						add_callback(callback::functor_type functor, void *ptr);
	void						add_model(model *model);

	void						render();

	void						loop();
	void						terminate();

protected :

	core						core;
	camera						camera;
	event						event;

	virtual void				render_call() = 0;

private :

	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<callback>		callback_array;
	bool						render_request = true;

MOD1_GENERATE_INTERNAL(std::vector<model *>, model_array)

protected :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(model_array)
};

