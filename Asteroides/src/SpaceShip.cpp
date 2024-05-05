#include <iostream>
#include "../include/SpaceShip.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"

using namespace std;

SpaceShip::SpaceShip(sf::Color const& color) {
	if (!texture.loadFromFile("resources/images/spaceship.png")) {
		cerr << "L'image du vaisseau n'a pas ete correctement chargee";
	}
	sprite.setTexture(texture);
	sprite.setColor(color);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());
}

void SpaceShip::updateState() {
	accelerationInProgress = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	turnToRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	turnToLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

void SpaceShip::update(float duration) {
	if (accelerationInProgress == true) {
		speed += Vector::createFromAngle(ACCELERATION * duration, sprite.getRotation());
	}
	speed -= speed * FRICTION_COEFFICIENT * duration;
	auto movement = speed * duration;
	position += movement;
	sprite.setPosition(position.getX(), position.getY());
	
	if (turnToRight == true) {
		sprite.rotate(- ANGULAR_VELOCITY * duration);
	}

	if (turnToLeft == true) {
		sprite.rotate(ANGULAR_VELOCITY * duration);
	}
}

void SpaceShip::display(sf::RenderWindow& window) const {
	window.draw(sprite);
}
