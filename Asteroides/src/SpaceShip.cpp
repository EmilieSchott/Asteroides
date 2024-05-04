#include "../include/SpaceShip.h"
#include <iostream>

using namespace std;

SpaceShip::SpaceShip(sf::Color color) {
	if (!texture.loadFromFile("resources/images/spaceship.png")) {
		cerr << "L'image du vaisseau n'a pas ete correctement chargee";
	}
	sprite.setTexture(texture);
	sprite.setColor(color);
}

void SpaceShip::moveForward() {
	sprite.move(10, 0);
}

void SpaceShip::display(sf::RenderWindow& window) {
	window.draw(sprite);
}
