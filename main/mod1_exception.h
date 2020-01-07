#pragma once

#include <exception>

#define MOD1_EXCEPTION_GENERATE(name, message)						\
class					name : public std::exception				\
{																	\
public :															\
                        name() : std::exception()					\
{}																	\
const char                *what() const noexcept					\
{																	\
    return (buffer);												\
}																	\
private :															\
    const char            *buffer = message;						\
};

#define MOD1_EXCEPTION_GENERATE_IMPLEMENTATION(space, name)			\
						space::name::name() : std::exception()		\
{}																	\
																	\
const char				*space::name::what() const noexcept			\
{																	\
	return (buffer);												\
}


#define MOD1_EXCEPTION_GENERATE_DEFINITION(name, message)			\
class					name : public std::exception				\
{																	\
public :															\
						name();										\
	virtual const char	*what() const noexcept final;				\
																	\
private :															\
	const char			*buffer = message;							\
};

#define MOD1_EXCEPTION_GENERATE_IMPLEMENTATION(space, name)			\
						space::name::name() : std::exception()		\
{}																	\
																	\
const char				*space::name::what() const noexcept			\
{																	\
	return (buffer);												\
}

