#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include "../include/Vector.h"
#include "../include/Coordinates.h"

class SpaceElement
{
	public:
		SpaceElement(std::string_view const& imagePath);
		void display(sf::RenderWindow& window) const;
		void update(float duration);

	protected:
		sf::Texture texture{};
		sf::Sprite sprite{};
		Coordinates position{};
		Vector speed{ 0.f, 0.f };
};
