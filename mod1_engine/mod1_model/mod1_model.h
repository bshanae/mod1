#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_model_data.h"
#include "mod1_loader.h"

class				mod1_model
{

public :

					mod1_model();
					~mod1_model() = default;

	void			load(mod1_loader &loader);
	void			use();
	int 			get_vertex_number();

//private :

	GLuint 			vao;
	GLuint 			eab;

protected :

	mod1_model_data	data;
	int				vertex_number;
};


