#include "../include/MissingResourceException.h"

using namespace std::string_literals;

MissingResourceException::MissingResourceException(std::string_view const& imagePath) : errorMessage{"Erreur, ressource introuvable :"s + imagePath.data()} {

}

const char* MissingResourceException::what() const noexcept  {
	return errorMessage.c_str();
}