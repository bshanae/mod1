#pragma once

#include "mod1_OpenGL.h"
#include "mod1_model_data.h"
#include "mod1_loader.h"
#include "mod1_point2.h"

class				mod1_model
{

public :

					mod1_model();
					~mod1_model() = default;

	struct			exception_not_built : public std::exception
	{
		const char	*what() const noexcept override;
	};

	struct			exception_not_loaded : public std::exception
	{
		const char	*what() const noexcept override;
	};

	virtual void	build() = 0;
	void			load(mod1_loader &loader);
	void			use();
	int 			vertex_number();

private :

	GLuint 			vao;
	bool			is_built = false;
	bool			is_loaded = false;

protected :

	mod1_model_data	data;
	int				vertex_number_internal;

	void			*get_ptr(const int &index, const mod1_model_data::slot_type &slot);
	void const		*get_ptr(const int &index, const mod1_model_data::slot_type &slot) const;

	void			set_as_built();
};


