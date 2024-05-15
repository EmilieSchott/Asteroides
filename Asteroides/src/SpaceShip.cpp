#include <iostream>
#include "../include/SpaceShip.h"
#include "../include/SpaceElement.h"
#include "../include/Explosion.h"

using namespace std;

SpaceShip::SpaceShip(Space& spaceReference, sf::Color const& color) : SpaceElement{ "resources/images/spaceship.png" }, space{ spaceReference } {
	type = TypeElement::SPACESHIP;
	sprite.setColor(color);
}

void SpaceShip::updateState() {
	accelerationInProgress = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	turnToRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	turnToLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShot.getElapsedTime().asSeconds() > 0.1) {
		space.add(make_unique<Missile>(position, sprite.getRotation()));
		lastShot.restart();
	}
}

void SpaceShip::update(float duration) {
	updateState();
	if (destroyed == false) {
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
	}
}

void SpaceShip::reactToCollision(TypeElement otherType) {
	if (otherType == TypeElement::ASTEROID) {
		destroyed = true;
		space.add(std::make_unique<Explosion>(position));
	}
}

