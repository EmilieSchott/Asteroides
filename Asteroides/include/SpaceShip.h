#pragma once

#include <SFML/Graphics.hpp>

class SpaceShip {
	public:
	SpaceShip(sf::Color const& color);
	void updateState(sf::Event const& event);
	void display(sf::RenderWindow& window) const;
	void update(float duration);

	private:
	sf::Texture texture{};
	sf::Sprite sprite{};
	float speed{ 0.f };
	bool accelerationInProgress{ false };

	static constexpr float ACCELERATION{ 7000.f };
	static constexpr float FRICTION_COEFFICIENT{ 2.f };
};

