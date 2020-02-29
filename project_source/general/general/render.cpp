#include "general.h"

void				general::render()
{
	mod1_engine_gl::core::clear(MOD1_GENERAL_BACKGROUND);

	program.start();

	program.camera_position.upload(camera.position());
	program.camera_projection.upload(camera.projection());
	program.camera_view.upload(camera.view());

	program.light_ambient_intensity.upload(light.ambient_intensity);
	program.light_direct_direction.upload(light.direct_direction);
	program.light_direct_intensity.upload(light.direct_intensity);

	for (auto &model : model_array())
	{
		program.object_transformation.upload(rotation);
		program.object_ambient_receptivity.upload(model->ambient_receptivity());
		program.object_diffuse_receptivity.upload(model->diffuse_receptivity());
		program.object_specular_receptivity.upload(model->specular_receptivity());
		model->draw();
	}
	program::stop();

	hint_render();

	mod1_engine_gl::core::swap_buffers();
}