#include "../include/SpaceShip.h"
#include <iostream>

using namespace std;

SpaceShip::SpaceShip(sf::Color const& color) {
	if (!texture.loadFromFile("resources/images/spaceship.png")) {
		cerr << "L'image du vaisseau n'a pas ete correctement chargee";
	}
	sprite.setTexture(texture);
	sprite.setColor(color);
}

void SpaceShip::updateState(sf::Event const& event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z ) {
		accelerationInProgress = true;
	} else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z) {
		accelerationInProgress = false;
	}
}

void SpaceShip::update(float duration) {
	if (accelerationInProgress) {
		speed += ACCELERATION*duration;
	}
	speed -= speed * FRICTION_COEFFICIENT * duration;
	sprite.move(speed*duration, 0);
}

void SpaceShip::display(sf::RenderWindow& window) const {
	window.draw(sprite);
}
