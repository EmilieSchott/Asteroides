#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>


class ResourcesManager
{
	public:
		ResourcesManager() = delete;
		static sf::Texture const& getResource(std::string_view const& imagePath);

	private :
		static std::unordered_map<std::string_view, sf::Texture> resources;
};

