#pragma once

#include <SFML/Graphics.hpp>

class SpaceShip {
	public:
	SpaceShip(sf::Color color);
	void moveForward();
	void display(sf::RenderWindow& window);

	private:
		sf::Texture texture{};
		sf::Sprite sprite{};
};

