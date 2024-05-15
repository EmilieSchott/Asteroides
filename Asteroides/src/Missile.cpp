#include "../include/Missile.h"

Missile::Missile(Coordinates const& spaceShipPosition, float rotation) : SpaceElement{ "resources/images/missile.png" } {
	type = TypeElement::MISSILE;
	position = spaceShipPosition;
	sprite.setRotation(rotation);
	speed = Vector::createFromAngle(SPEED, rotation);
}

void Missile::reactToCollision(TypeElement otherType) {
	if (otherType != TypeElement::SPACESHIP) {
		destroyed = true;
	}
}