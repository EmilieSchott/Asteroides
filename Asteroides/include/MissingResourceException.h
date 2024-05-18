#pragma once

#include <exception>
#include <string_view>
#include <string>

class MissingResourceException : public std::exception
{
	public:
		MissingResourceException(std::string_view const& imagePath);
		virtual const char* what() const noexcept override;

	private:
		std::string errorMessage{};
};

