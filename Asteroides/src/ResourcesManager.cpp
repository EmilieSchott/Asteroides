
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/ResourcesManager.h"

using namespace std;

template<>
unordered_map<string_view, sf::Texture> ResourcesManager<sf::Texture>::resources{};

template<>
unordered_map<string_view, sf::SoundBuffer> ResourcesManager<sf::SoundBuffer>::resources{};
