#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Vector.h"
#include "../include/Coordinates.h"
#include "../include/SpaceElement.h"

class SpaceShip : public SpaceElement {
	public:
	SpaceShip(sf::Color const& color);
	void updateState();
	void update(float duration);

	private:
	bool accelerationInProgress{ false };
	bool turnToRight{ false };
	bool turnToLeft{ false };

	static constexpr float ACCELERATION{ 7000.f };
	static constexpr float FRICTION_COEFFICIENT{ 2.f };
	static constexpr float ANGULAR_VELOCITY{ 50 };
};

