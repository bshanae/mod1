#pragma once

#include "mod1_macros.h"
#include <exception>

#define MOD1_GENERATE_EXCEPTION(name, message)							\
class							name : public std::exception			\
{																		\
public :																\
                        		name() : std::exception()				\
{}																		\
const char               		 *what() const noexcept					\
{																		\
    return (buffer);													\
}																		\
private :																\
    const char					*buffer = message;						\
};


#define MOD1_GENERATE_EXCEPTION_DECLARATION(name, message)				\
class							name : public std::exception			\
{																		\
public :																\
								name();									\
	virtual const char			*what() const noexcept final;			\
																		\
private :																\
	const char					*buffer = message;						\
};

#define MOD1_GENERATE_EXCEPTION_DEFINITION(space, name)					\
								space::name::name() : std::exception()	\
{}																		\
																		\
const char						*space::name::what() const noexcept		\
{																		\
	return (buffer);													\
}

#define MOD1_GENERATE_GET_DECLARATION(name)								\
TYPE(name##_internal)			name() const;

#define MOD1_GENERATE_GET_DEFINITION(space, name)						\
TYPE(space::name##_internal)	space::name() const						\
{																		\
	return (name##_internal);											\
}

//		TEMPLATE

#define MOD1_GENERATE_TEMPLATE(name)									\
	template					<typename name>

//		UNIFORM

#define MOD1_GENERATE_UNIFORM(name, name_GL)							\
	uniform						name = uniform(name_GL);

