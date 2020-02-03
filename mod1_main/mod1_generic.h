#pragma once

#include "mod1_macros.h"
#include <exception>

#define MOD1_GENERATE_EXCEPTION(name, message)									\
class								name : public std::exception				\
{																				\
public :																		\
                        			name() : std::exception()					\
{}																				\
const char               		 	*what() const noexcept						\
{																				\
    return (buffer);															\
}																				\
private :																		\
    const char						*buffer = message;							\
};

#define MOD1_GENERATE_EXCEPTION_DECLARATION(name, message)						\
class								name : public std::exception				\
{																				\
public :																		\
									name();										\
	virtual const char				*what() const noexcept final;				\
																				\
private :																		\
	const char						*buffer = message;							\
};

#define MOD1_GENERATE_EXCEPTION_DEFINITION(space, name)							\
									space::name::name() : std::exception()		\
{}																				\
																				\
const char							*space::name::what() const noexcept			\
{																				\
	return (buffer);															\
}

#define MOD1_GENERATE_INTERNAL(type, name)										\
	type							MOD1_INTERNAL(name);

#define MOD1_GENERATE_INTERNAL_WITH_VALUE(type, name, value)					\
	type							MOD1_INTERNAL(name) = value;

#define MOD1_GENERATE_INTERNAL_READ(name)										\
TYPE(MOD1_INTERNAL(name))			name() const								\
{	return (MOD1_INTERNAL(name));	}

#define MOD1_GENERATE_INTERNAL_READ_DECLARATION(name)							\
TYPE(MOD1_INTERNAL(name))			name() const;

#define MOD1_GENERATE_INTERNAL_READ_DEFINITION(space, name)						\
TYPE(space::MOD1_INTERNAL(name))	space::name() const							\
{	return (MOD1_INTERNAL(name));	}

//		UNIFORM

#define MOD1_GENERATE_UNIFORM(name, name_GL)									\
	uniform							name = uniform(name_GL);

#define MOD1_CONNECT_UNIFORM(program, uniform)									\
	program.connect_uniform(program.uniform);

//		TEST

#define MOD1_GENERATE_GL_TEST		if (glGetError()) printf("GL Error in function %s, line %d\n", __FUNCTION__, __LINE__);