#pragma once

#include "mod1_OpenGL.h"
#include "mod1_model_data.h"
#include "mod1_loader.h"
#include "mod1_point2.h"

class				mod1_model
{

public :

					mod1_model() = default;
					~mod1_model() = default;

	struct			exception_not_built : public std::exception
	{
		const char	*what() const noexcept override;
	};

	struct			exception_not_loaded : public std::exception
	{
		const char	*what() const noexcept override;
	};

	struct			exception_logic_dynamic : public std::exception
	{
		const char	*what() const noexcept override;
	};

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


