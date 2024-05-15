#include "../include/Explosion.h"

Explosion::Explosion(Coordinates const& otherObjectPosition) : SpaceElement{ "resources/images/explosion.png" } {
	position = otherObjectPosition;
}


void Explosion::update(float duration) {
	age += duration; 
	if (age < LIFE_SPAN) {
		sprite.setScale(age/LIFE_SPAN, age/LIFE_SPAN);
	} else {
		destroyed = true;
	}
}

void Explosion::reactToCollision(TypeElement otherType) { // To delete when add MaterialElement Class

}
