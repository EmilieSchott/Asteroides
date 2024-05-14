#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../include/SpaceElement.h"

class Space
{
	public :
		Space();
		void add(std::unique_ptr<SpaceElement> spaceElement);
		void actualize();
		void manageCollisions();
		void display(sf::RenderWindow& window) const;
		void cleanUp();

	private :
		std::vector<std::unique_ptr<SpaceElement>> spaceElements{};
		sf::Clock chrono{};
};

