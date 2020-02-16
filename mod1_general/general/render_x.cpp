#include "general.h"

void				general::render()
{
	mod1_engine_gl::core::clear(MOD1_BACKGROUND);

	program.start();

	program.camera_position.upload(camera.position());
	program.camera_projection.upload(camera.projection());
	program.camera_view.upload(camera.view());

	program.light_ambient_intensity.upload(light_info.ambient_intensity);
	program.light_direct_direction.upload(light_info.direct_direction);
	program.light_direct_intensity.upload(light_info.direct_intensity);

	for (auto &model : model_array())
	{
		program.object_transformation.upload(rotation);
		program.object_ambient_receptivity.upload(model->ambient_receptivity());
		program.object_diffuse_receptivity.upload(model->diffuse_receptivity());
		program.object_specular_receptivity.upload(model->specular_receptivity());
		model->draw();
	}
	program::stop();

	mod1_engine_gl::core::swap_buffers();
}

void 				general::render_block(const bool &state)
{
	if (state)
	{
		callback_rotate_start->block(true);
		callback_rotate_finish->block(true);
		timer_gravity->block(true);
		run_blur();
		run_gui_front();
		request_render(false);
	}
	else
	{
		callback_rotate_start->block(false);
		callback_rotate_finish->block(false);
		timer_gravity->block(false);
		gui_level = level::render;
		request_render();
	}
}