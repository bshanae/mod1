#pragma once

#include "mod1_OpenGL.h"
#include "mod1_exception.h"

#include "mod1_model_data.h"
#include "mod1_loader.h"
#include "mod1_point2.h"

class				mod1_model
{

public :

					mod1_model() = default;
					~mod1_model() = default;

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_build, "Mod1 Model : Object not built")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_load, "Mod1 Model : Object not loaded")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_dynamic, "Mod1 Model : Can't set object as dynamic after loading")

	virtual void	build() = 0;
	void			load(mod1_loader &loader);
	void			use();

	int 			vertex_number();
	glm::mat4		&transformation();

protected :

	mod1_model_data	data;
	int				vertex_number_internal = -1;
	glm::mat4 		transformation_internal = glm::mat4(1);

	void			*get_ptr(const int &index, const mod1_model_data::slot_type &slot);
	void const		*get_ptr(const int &index, const mod1_model_data::slot_type &slot) const;

	void 			upload_buffer(const mod1_model_data::slot_type &slot);

	void			set_as_built();
	void			set_as_dynamic();

private :

	bool			is_built = false;
	bool			is_loaded = false;
	bool 			is_dynamic = false;
};


