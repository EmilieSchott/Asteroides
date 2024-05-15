#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
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
		std::vector<std::unique_ptr<SpaceElement>> newSpaceElements{};
		sf::Clock chrono{};
};

