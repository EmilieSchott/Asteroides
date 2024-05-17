#include "../include/Game.h"
#include "../include/SpaceShip.h"
#include "../include/Asteroid.h"
#include <iostream>

using namespace std;

const sf::Color SPACESHIP_COLOR{ 128, 255, 128 };

Game::Game(Space& p_space) : space{ p_space } {

}

void Game::start() {
	running = true;
	space.add(make_unique<SpaceShip>(*this, space, SPACESHIP_COLOR));
	space.add(make_unique<Asteroid>(space));
	space.add(make_unique<Asteroid>(space));
	space.add(make_unique<Asteroid>(space));
}

void Game::terminate() {
	running = false;
	space.clear();
}
