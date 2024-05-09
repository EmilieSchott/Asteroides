#include <iostream>
#include "../include/SpaceShip.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"

using namespace std;

SpaceShip::SpaceShip(sf::Color const& color): SpaceElement("resources/images/spaceship.png") {
	sprite.setColor(color);
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
	SpaceElement::update(duration);
	
	if (turnToRight == true) {
		sprite.rotate(- ANGULAR_VELOCITY * duration);
	}

	if (turnToLeft == true) {
		sprite.rotate(ANGULAR_VELOCITY * duration);
	}
}

