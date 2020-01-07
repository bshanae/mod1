#pragma once

#define MOD1_EXCEPTION_GENERATE_DEFINITION(name, message)			\
class				name : public std::exception					\
{																	\
public :															\
					name();											\
	const char		*what() const noexcept final;					\
																	\
private :															\
	const char		*buffer = message;								\
};

#define MOD1_EXCEPTION_GENERATE_IMPLEMENTATION(space, name)			\
					space::name::name() : std::exception()			\
{}																	\
																	\
const char			*space::name::what() const noexcept				\
{																	\
	return (buffer);												\
}

