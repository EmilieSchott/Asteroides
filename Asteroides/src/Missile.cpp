#include "../include/Missile.h"
#include "../include/ResourcesManager.h"

Missile::Missile(Coordinates const& spaceShipPosition, float rotation) : SpaceElement{ "resources/images/missile.png" } {
	type = TypeElement::MISSILE;
	position = spaceShipPosition;
	sprite.setRotation(rotation);
	speed = Vector::createFromAngle(SPEED, rotation);
	sound.setBuffer(ResourcesManager<sf::SoundBuffer>::getResource("resources/sounds/laser.wav"));
	sound.play();
}

void Missile::reactToCollision(TypeElement otherType) {
	if (otherType != TypeElement::SPACESHIP) {
		destroyed = true;
	}
}