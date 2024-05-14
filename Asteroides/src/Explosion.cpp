#include "../include/Explosion.h"

Explosion::Explosion(Coordinates const& spaceShipPosition) : SpaceElement{ "resources/images/explosion.png" } {
	position = spaceShipPosition;
}


void Explosion::update(float duration) {
	age += duration; 
	if (age < LIFE_SPAN) {
		sprite.setScale(age/LIFE_SPAN, age/LIFE_SPAN);
	} else {
		destroyed = true;
	}
}

void Explosion::reactToCollision() { // To delete when add MaterialElement Class

}
