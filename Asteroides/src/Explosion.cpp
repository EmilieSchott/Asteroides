#include "../include/Explosion.h"
#include "../include/ResourcesManager.h"

Explosion::Explosion(Coordinates const& otherObjectPosition) : SpaceElement{ "resources/images/explosion.png" } {
	position = otherObjectPosition;
	sound.setBuffer(ResourcesManager<sf::SoundBuffer>::getResource("resources/sounds/explosion.wav"));
	sound.play();
}


void Explosion::update(float duration) {
	age += duration; 
	if (age < LIFE_SPAN) {
		sprite.setScale(age/LIFE_SPAN, age/LIFE_SPAN);
	} else {
		sprite.setScale(0, 0);
		if(sound.getStatus() == sf::SoundSource::Stopped) {
			destroyed = true;
		}
	}
}

void Explosion::reactToCollision(TypeElement otherType) { // To delete when add MaterialElement Class

}
