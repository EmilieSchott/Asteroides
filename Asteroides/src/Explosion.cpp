#include "../include/Explosion.h"

Explosion::Explosion() : SpaceElement{ "resources/images/explosion.png" } {

}

void Explosion::begin(Coordinates const& spaceShipPosition) {
	position = spaceShipPosition;
	begun = true;
}

void Explosion::update(float duration) {
	if (begun == true) {
		age += duration; 
	}

	if (age < LIFE_SPAN) {
		sprite.setScale(age/LIFE_SPAN, age/LIFE_SPAN);
	}
	SpaceElement::update(duration);
}

void Explosion::display(sf::RenderWindow& window) const {
	if (age < LIFE_SPAN) {
		SpaceElement::display(window);
	}
}

void Explosion::reactToCollision() { // To delete when add MaterialElement Class

}
