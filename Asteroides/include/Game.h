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
		void addPoints(int points);
		inline bool isRunning() { return running; };
		void display(sf::RenderWindow& window) const;
		void initializeException(std::exception const& exception);

	private:
		void updateScoreText();
		void updateBestScoreText();
		Space& space;
		bool running{ false };
		int score{};
		int bestScore{};
		sf::Text scoreText{};
		sf::Text bestScoreText{};
		sf::Sprite welcomeSprite{};
		sf::Font font{};
		std::unique_ptr<sf::Text> exceptionText{ nullptr };

};

