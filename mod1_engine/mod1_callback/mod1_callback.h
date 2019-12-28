#pragma once

class				mod1_callback
{
public :

	typedef	void	(*functor_type)(int glwf_key, void *ptr);

					mod1_callback(functor_type functor, void *ptr);
					~mod1_callback() = default;

	void			run(int key) const;

private :

	functor_type	functor;
	void 			*ptr;
};
