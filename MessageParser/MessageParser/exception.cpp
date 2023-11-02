#include "pch.h"
#include "exception.h"

//exception class
exception::exception(const std::string& message) : std::runtime_error(message) {}