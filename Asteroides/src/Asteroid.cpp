#include <iostream>
#include <random>
#include "../include/Asteroid.h"
#include "../include/SpaceElement.h"

using namespace std;

Asteroid::Asteroid() : SpaceElement("resources/images/asteroid.png") 
{
	auto generator = random_device();
	auto positionDistribution = uniform_real_distribution<float>{ -150, 150 }; // cannot spawn in the middle of the space
	auto speedDistribution = uniform_real_distribution<float>{ 80, 120 };
	auto angleDistribution = uniform_real_distribution<float>{ 0, 360 };
	auto angularVelocityDistribution = uniform_real_distribution<float>{ 10, 30 };
	position = { positionDistribution(generator), positionDistribution(generator)};
	speed = Vector::createFromAngle(speedDistribution(generator), angleDistribution(generator));
	angularVelocity = angularVelocityDistribution(generator);
}

void Asteroid::reactToCollision() {

}


