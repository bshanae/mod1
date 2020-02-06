#pragma once

#include "mod1_macros.h"

//									EXCEPTION

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

//									INTERNAL

#define MOD1_GENERATE_INTERNAL(type, name)										\
	type							MOD1_INTERNAL(name);

#define MOD1_GENERATE_INTERNAL_WITH_VALUE(type, name, value)					\
	type							MOD1_INTERNAL(name) = value;

#define MOD1_GENERATE_INTERNAL_READ(name)										\
MOD1_INTERNAL_RETURN(name)			name() const								\
{	return (MOD1_INTERNAL(name));	}

#define MOD1_GENERATE_INTERNAL_READ_DECLARATION(name)							\
MOD1_INTERNAL_RETURN(name)			name() const;

#define MOD1_GENERATE_INTERNAL_READ_DEFINITION(space, name)						\
MOD1_INTERNAL_RETURN(space::name)	space::name() const							\
{	return (MOD1_INTERNAL(name));	}

//									UNIFORM

#define MOD1_GENERATE_UNIFORM(name, name_GL)									\
	mod1_engine_gl::uniform			name = mod1_engine_gl::uniform(name_GL);

#define MOD1_CONNECT_UNIFORM(program, uniform)									\
	(program).connect_uniform((program).uniform);

//									OTHERS

#define MOD1_GENERATE_GL_TEST		if (glGetError()) printf("GL Error in function %s, line %d\n", __FUNCTION__, __LINE__);

#define MOD1_GENERATE_MESSAGE(text)												\
	std::cout << text << std::endl;
