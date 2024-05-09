#include <iostream>
#include "../include/Asteroid.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"

using namespace std;

Asteroid::Asteroid() : SpaceElement("resources/images/asteroid.png") {
	speed = { 100,20 };
}


