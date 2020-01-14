#pragma once

class				mod1_callback
{
public :

	typedef	bool	(*functor_type)(int glwf_key, void *ptr);

					mod1_callback(functor_type functor, void *ptr);
					~mod1_callback() = default;

	bool			run(int key) const;

private :

	functor_type	functor;
	void 			*ptr;
};
