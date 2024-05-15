#include <iostream>
#include <random>
#include "../include/Asteroid.h"
#include "../include/SpaceElement.h"
#include "../include/Space.h"
#include "../include/Explosion.h"

using namespace std;

Asteroid::Asteroid(Space& p_space, Asteroid* parent) : SpaceElement("resources/images/asteroid.png"), space{ p_space } {
	type = TypeElement::ASTEROID;
	auto generator = random_device();
	auto positionDistribution = uniform_real_distribution<float>{ -150, 150 }; // cannot spawn in the middle of the space
	auto speedDistribution = uniform_real_distribution<float>{ 80, 120 };
	auto angleDistribution = uniform_real_distribution<float>{ 0, 360 };
	auto angularVelocityDistribution = uniform_real_distribution<float>{ 10, 30 };
	speed = Vector::createFromAngle(speedDistribution(generator), angleDistribution(generator));
	angularVelocity = angularVelocityDistribution(generator);
	if (parent) {
		sprite.setScale(parent->sprite.getScale().x / 1.4, parent->sprite.getScale().y / 1.4);
		position = parent->position;
	} else {
		position = { positionDistribution(generator), positionDistribution(generator) };
	}
}

void Asteroid::reactToCollision(TypeElement otherType) {
	if (otherType == TypeElement::MISSILE) {
		destroyed = true;
		space.add(make_unique<Explosion>(position));
		if (sprite.getScale().x > 0.1) {
			space.add(make_unique<Asteroid>(space, this));
			space.add(make_unique<Asteroid>(space, this));
		}
	}
}


