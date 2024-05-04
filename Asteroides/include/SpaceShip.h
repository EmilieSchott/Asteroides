#pragma once

#include <SFML/Graphics.hpp>

class SpaceShip {
	public:
	void moveForward();
	void display(sf::RenderWindow& window);

	private:
		sf::CircleShape circle{30};
};

