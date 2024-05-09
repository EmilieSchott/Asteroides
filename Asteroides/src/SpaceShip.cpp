#include <iostream>
#include "../include/SpaceShip.h"
#include "../include/SpaceElement.h"

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

	if (turnToLeft == true) {
		angularVelocity = -ANGULAR_VELOCITY;
	} else if (turnToRight  == true) {
		angularVelocity = ANGULAR_VELOCITY;
	} else {
		angularVelocity = 0;
	}

	SpaceElement::update(duration);
}

