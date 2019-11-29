#include "mod1_error.h"

void 				mod1_error::print_error(const std::string message, va_list args) const
{
	printf("\033[0;31m");
	printf("%s warning : ", prefix.c_str());
	vprintf(message.c_str(), args);
	printf("\033[0m");
}

void 				mod1_error::print_warning(const std::string message, va_list args) const
{
	printf("\033[0;31m");
	printf("%s warning : ", prefix.c_str());
	vprintf(message.c_str(), args);
	printf("\033[0m");
}

void 				mod1_error::raise_warning(const std::string message, ...) const
{
	va_list			args;

	va_start(args, message);
	print_warning(message, args);
	va_end(args);
}

void 				mod1_error::raise_error(const std::string message, ...) const
{
	va_list			args;

	va_start(args, message);
	print_error(message, args);
	va_end(args);
	exit(1);
}

void 				mod1_error::test(bool statement, const std::string message, ...) const
{
	va_list 		args;

	va_start(args, message);
	if (!statement)
		raise_warning(message, args);
	va_end(args);
}

void 				mod1_error::test_critical(bool statement, const std::string message, ...) const
{
	va_list 		args;

	va_start(args, message);
	if (!statement)
		raise_error(message, args);
	va_end(args);
}