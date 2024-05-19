#include "../include/Game.h"
#include "../include/SpaceShip.h"
#include "../include/Asteroid.h"
#include "../include/ResourcesManager.h"
#include "../include/font.h"
#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

using namespace std;
using namespace string_literals;

const sf::Color SPACESHIP_COLOR{ 128, 255, 128 };

Game::Game(Space& p_space) : space{ p_space } {
	// this exception shouldn't be catch to make the program crash if trigerred.
	if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{ "Police introuvable !" };
	scoreText.setFont(font);
	scoreText.move(0, 30);
	bestScoreText.setFont(font);
	auto file = ifstream{ "bestScore.txt" };
	if (file.is_open()) {
		file >> bestScore;
	}
	file.close();
	updateBestScoreText();
	try {
		welcomeSprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/images/welcome.png"));
	}catch (std::exception const& exception) {
		initializeException(exception);
	}
}

void Game::start() {
	running = true;
	score = 0;
	updateScoreText();
	space.add(make_unique<SpaceShip>(*this, space, SPACESHIP_COLOR));
	space.add(make_unique<Asteroid>(*this, space));
	space.add(make_unique<Asteroid>(*this, space));
	space.add(make_unique<Asteroid>(*this, space));
}

void Game::terminate() {
	running = false;
	if (score > bestScore) {
		bestScore = score;
		updateBestScoreText();
		auto file = ofstream{ "bestScore.txt" };
		if (file.is_open()) {
			file << bestScore;
		} else {
			throw runtime_error("Impossible d'ouvrir le fichier bestScore en écriture.");
		}
		file.close();
	}
	space.clear();
}

void Game::display(sf::RenderWindow& window) const {
	if (exceptionText) {
		window.draw(*exceptionText);
	} else {
		if (running == false && space.isEmpty()) {	
			window.draw(welcomeSprite);
		} else {
			window.draw(scoreText);
		}
		window.draw(bestScoreText);
	}
}

void Game::initializeException(std::exception const& exception) {
	exceptionText = std::make_unique<sf::Text>();
	exceptionText->setFont(font);
	exceptionText->setString(exception.what());
	exceptionText->setFillColor(sf::Color::Red);
}

void Game::addPoints(int points) {
	score += points;
	updateScoreText();
}

void Game::updateScoreText() {
	scoreText.setString("Score : "s + to_string(score));
}

void Game::updateBestScoreText() {
	bestScoreText.setString("Meilleur sccore : "s + to_string(bestScore));
}