#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/model/model_data.h"
#include "mod1_engine_gl/loader/loader.h"
#include "mod1_engine_gl/point/point2.h"

class				mod1_engine_gl::model
{
	friend class 	model_reader;

public :

					model() = default;
					~model() = default;

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Engine GL, Model : Object not built")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_load, "Mod1 Engine GL, Model : Object not loaded")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_dynamic, "Mod1 Engine GL, Model : Can't set object as dynamic after loading")

	virtual void	build() = 0;

	void			load(loader &loader);
	void			draw(core &core);

	void			start() const;
	void			stop() const;

protected :

	model_data		data;

	int				vertex_number = -1;

	void			*get_ptr(const int &index, const model_data::slot_type &slot);
	void const		*get_ptr(const int &index, const model_data::slot_type &slot) const;

	void 			upload_buffer(const model_data::slot_type &slot);

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


