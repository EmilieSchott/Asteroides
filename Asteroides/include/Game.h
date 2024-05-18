#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Space.h"

class Game
{
public:
	Game(Space& p_space);
	void start();
	void terminate();
	inline bool isRunning() { return running; };
	void display(sf::RenderWindow& window) const;

private:
	Space& space;
	bool running{ false };
	sf::Sprite welcomeSprite{};

};

