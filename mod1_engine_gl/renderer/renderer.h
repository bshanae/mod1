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

class							mod1_engine_gl::renderer : public core
{

public :

								renderer();
								~renderer() override = default;

	void						add_model(model *model);

protected :

	camera						camera;

	virtual void				render() = 0;

private :

	static void					callback_key(void *ptr, const class event &event);

MOD1_GENERATE_INTERNAL(std::vector<model *>, model_array)

protected :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(model_array)
};

