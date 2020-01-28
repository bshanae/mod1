#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/shader/shader.h"
#include "mod1_engine_gl/uniform/uniform.h"

class					mod1_engine_gl::program
{

public :

						program();
						~program();

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Engine GL, Program : Compilation error")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Engine GL, Program : Object is nit linked")

	void				start();
	void				stop();

	void 				add_shader(const shader_type &type, const char *source);
	void				link();
	void 				set_uniform(uniform &uniform);

private :

	bool				is_linked = false;

MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

	void				check_error();

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)
};
