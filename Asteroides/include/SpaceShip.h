#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Vector.h"
#include "../include/Coordinates.h"
#include "../include/SpaceElement.h"
#include "../include/Explosion.h"

class SpaceShip : public SpaceElement { // superclass should become MaterialElement
	public:
	explicit SpaceShip(sf::Color const& color);
	void updateState();
	virtual void update(float duration) override;
	virtual void reactToCollision() override;
	virtual void display(sf::RenderWindow& window) const override;

	private:
	bool accelerationInProgress{ false };
	bool turnToRight{ false };
	bool turnToLeft{ false };
	bool destructed{ false };

	Explosion explosion{};

	static constexpr float ACCELERATION{ 7000.f };
	static constexpr float FRICTION_COEFFICIENT{ 2.f };
	static constexpr float ANGULAR_VELOCITY{ 50 };
};

