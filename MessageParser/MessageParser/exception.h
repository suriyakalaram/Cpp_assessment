#pragma once
#include <stdexcept>

class exception : public std::runtime_error {
public:
	exception(const std::string& message);
};