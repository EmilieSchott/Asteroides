#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Vector.h"
#include "../include/Coordinates.h"

class SpaceShip {
	public:
	SpaceShip(sf::Color const& color);
	void updateState();
	void display(sf::RenderWindow& window) const;
	void update(float duration);

	private:
	sf::Texture texture{};
	sf::Sprite sprite{};
	Coordinates position{};
	Vector speed{ 0.f, 0.f };
	bool accelerationInProgress{ false };
	bool turnToRight{ false };
	bool turnToLeft{ false };

	static constexpr float ACCELERATION{ 7000.f };
	static constexpr float FRICTION_COEFFICIENT{ 2.f };
	static constexpr float ANGULAR_VELOCITY{ 50 };
};

