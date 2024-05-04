#include "../include/SpaceShip.h"


void SpaceShip::moveForward() {
	circle.move(10, 0);
}

void SpaceShip::display(sf::RenderWindow& window) {
	window.draw(circle);
}
