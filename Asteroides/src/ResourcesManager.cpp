#include <iostream>
#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>
#include "../include/ResourcesManager.h"

using namespace std;

unordered_map<string_view, sf::Texture> ResourcesManager::resources{};

sf::Texture const& ResourcesManager::getResource(string_view const& imagePath) {
	auto result = resources.find(imagePath);
	if (result == end(resources)) {
		if (resources[imagePath].loadFromFile(imagePath.data()) == false) {
			cerr << "Error : impossible to upload the texture " << imagePath << endl;
		}
		return resources[imagePath];
	}
	return result->second;
}
