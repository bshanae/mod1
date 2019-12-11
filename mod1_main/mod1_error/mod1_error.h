#pragma once

#include <string>

class 				mod1_error
{

public :

	mod1_error() = default;

	~mod1_error() = default;

	void 			raise_warning(const std::string message, ...) const;

	void 			raise_error(const std::string message, ...) const;

	void 			test(bool statement, const std::string message, ...) const;

	void 			test_critical(bool statement, const std::string message, ...) const;

private :

	void 			print_warning(const std::string message, va_list args) const;

	void 			print_error(const std::string message, va_list args) const;

	std::string		prefix = "Mod1";
};

extern mod1_error	*global_error;