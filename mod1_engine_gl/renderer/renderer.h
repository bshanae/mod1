#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/program/program.h"
#include "mod1_engine_gl/framebuffer/framebuffer.h"
#include "mod1_engine_gl/model/model.h"
#include "mod1_engine_gl/camera/camera.h"
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

#include "mod1_common/mod1_freetype.h"
#include <map>

#include "mod1_engine_gl/vbo/vbo.h"
#include "mod1_engine_gl/vao/vao.h"
#include "mod1_engine_gl/eab/eab.h"

using namespace					mod1_engine_gl;

class 							square : public mod1_engine_gl::model
{
public :
	void						build() override
	{

		float					vertices[] = {
			-1, -1, 0,
			-1, +1, 0,
			+1, -1, 0,
			+1, +1, 0
		};

		float					texture[] = {
			0, 0,
			0, 1,
			+1, 0,
			+1, +1
		};

		int						indices[] =
		{
			2, 1, 0,
			2, 3, 1
		};

		buffer_point.allocate(3 * 4);
		buffer_point.copy(vertices);

		buffer_index.allocate(3 * 2);
		buffer_index.copy(indices);

		buffer_texture.allocate(2 * 4);
		buffer_texture.copy(texture);

		set_as_built();
	}

	using						model::update;
	using						model::buffer_point;

	using						model::set_as_dynamic;
};

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

	virtual void				render_call() = 0;

private :

	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<callback>		callback_array;
	bool						render_request = true;

MOD1_GENERATE_INTERNAL(std::vector<model *>, model_array)

protected :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(model_array)
};

