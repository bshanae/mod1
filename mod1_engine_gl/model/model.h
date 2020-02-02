#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/vbo/vbo.h"
#include "mod1_engine_gl/vao/vao.h"
#include "mod1_engine_gl/eab/eab.h"

enum class			mod1_engine_gl::model_slot
{
	point,
	index,
	normal,
	color
};

class				mod1_engine_gl::model
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Engine GL, Model : Object not built")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_load, "Mod1 Engine GL, Model : Object not loaded")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_dynamic, "Mod1 Engine GL, Model : Can't set object as dynamic after loading")

					model() = default;
					~model() = default;

	virtual void	build() = 0;

	void			load();
	void			draw() const;

	void			start() const;
	void			stop() const;

protected :

	buffer<float>	point_buffer;
	buffer<int>		index_buffer;
	buffer<float>	normal_buffer;
	buffer<float>	color_buffer;

	vao				*vao = nullptr;
	vbo				*vbo_point = nullptr;
	vbo				*vbo_normal = nullptr;
	vbo				*vbo_color = nullptr;
	eab				*eab = nullptr;

	int				vertex_number = 0;

	void 			*pointer(const int &index, const model_slot &slot);
	void const		*pointer(const int &index, const model_slot &slot) const;

	void 			upload_slot(const model_slot &slot);

	void			set_as_built();
	void			set_as_dynamic();

MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, transformation, glm::mat4(1))

private :

	bool			is_built = false;
	bool			is_loaded = false;
	bool 			is_dynamic = false;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(transformation)
};


