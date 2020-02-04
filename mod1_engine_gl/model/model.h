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
	color,
	texture
};

class				mod1_engine_gl::model
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Engine GL, Model : Object not built")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_load, "Mod1 Engine GL, Model : Object not loaded")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_dynamic_a, "Mod1 Engine GL, Model : Can't set object as dynamic after loading")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_dynamic_b, "Mod1 Engine GL, Model : Can't update static object")

					model() = default;
	virtual			~model() = default;

	virtual void	build() = 0;

	virtual void	load();
	void			draw() const;

	void			start() const;
	void			stop() const;

protected :

	buffer<float>	buffer_point;
	buffer<int>		buffer_index;
	buffer<float>	buffer_normal;
	buffer<float>	buffer_color;
	buffer<float>	buffer_texture;

	vao				*vao = nullptr;
	eab				*eab = nullptr;
	vbo				*vbo_point = nullptr;
	vbo				*vbo_normal = nullptr;
	vbo				*vbo_color = nullptr;
	vbo				*vbo_texture = nullptr;

	int				vertex_number = 0;

	void 			*pointer(const int &index, const model_slot &slot);
	void const		*pointer(const int &index, const model_slot &slot) const;

	void 			update(const model_slot &slot);

	void			set_as_built();
	void			set_as_loaded();
	void			set_as_dynamic();

MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, transformation, glm::mat4(1))

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(bool, is_built, false)
MOD1_GENERATE_INTERNAL_WITH_VALUE(bool, is_loaded, false)
MOD1_GENERATE_INTERNAL_WITH_VALUE(bool, is_dynamic, false)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(transformation)

MOD1_GENERATE_INTERNAL_READ_DECLARATION(is_built)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(is_loaded)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(is_dynamic)
};


