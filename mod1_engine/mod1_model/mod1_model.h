#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_model_data.h"
#include "mod1_loader.h"
#include "mod1_point2.h"

class				mod1_model
{

public :

					mod1_model();
					~mod1_model() = default;

	void			load(mod1_loader &loader);
	void			use();
	int 			vertex_number();

private :

	GLuint 			vao;

protected :

	mod1_model_data	data;
	int				vertex_number_internal;

	void			*get_ptr(const int &index, const mod1_model_data::slot_type &slot);
};


