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
		model->draw();
	}
	program::stop();

	mod1_engine_gl::core::swap_buffers();
}