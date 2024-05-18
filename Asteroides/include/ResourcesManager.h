#pragma once

#include <iostream>
#include <string_view>
#include <unordered_map>
#include "../include/MissingResourceException.h"

template <typename T> 
class ResourcesManager
{
	public:
		ResourcesManager() = delete;
		static T const& getResource(std::string_view const& imagePath) {
			auto result = resources.find(imagePath);
			if (result == end(resources)) {
				if (resources[imagePath].loadFromFile(imagePath.data()) == false) {
					throw MissingResourceException{ imagePath };
				}
				return resources[imagePath];
			}
			return result->second;
		}

	private :
		static std::unordered_map<std::string_view, T> resources;
};

