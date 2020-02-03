#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_algorithm/mod1_algorithm.h"

#include "mod1_general/renderer/renderer.h"

class 							general
{

public :

								general(int argc, char **argv);
								~general();

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_arguments, "Mod1 Main : Invalid number of arguments")

	void						build();
	void						loop();

	::renderer					*renderer = nullptr;
	mod1_algorithm::terrain		*terrain = nullptr;
	mod1_algorithm::water		*water = nullptr;

private :

	char						*source;

};