#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/shader/shader.h"
#include "engine_gl/uniform/uniform.h"

class					mod1_engine_gl::program
{

public :

						program();
	virtual				~program();

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Engine GL, Program : Compilation error")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Engine GL, Program : Object is nit linked")

	void				start() const;
	static void			stop();

	void 				add_shader(const shader_type &type, const char *source);
	void				link();
	void 				connect_uniform(uniform &uniform);

private :

	bool				is_linked = false;

MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

	void				check_error();

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)
};
