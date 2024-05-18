#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Space.h"
#include <memory>

class Game
{
public:
	Game(Space& p_space);
	void start();
	void terminate();
	inline bool isRunning() { return running; };
	void display(sf::RenderWindow& window) const;
	void initializeException(std::exception const& exception);

private:
	Space& space;
	bool running{ false };
	sf::Sprite welcomeSprite{};
	sf::Font font{};
	std::unique_ptr<sf::Text> exceptionText{ nullptr };

};

