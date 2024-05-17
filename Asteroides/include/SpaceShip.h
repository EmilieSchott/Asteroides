#pragma once

#include <SFML/Graphics.hpp>
#include "../include/SpaceElement.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"
#include "../include/Explosion.h"
#include "../include/Space.h"
#include "../include/Missile.h"
#include "../include/Game.h"

class SpaceShip : public SpaceElement { // superclass should become MaterialElement
	public:
		explicit SpaceShip(Game& p_game, Space& p_space, sf::Color const& color);

		virtual void reactToCollision(TypeElement otherType) override;

	protected:
		virtual void update(float duration) override;

	private:
		void updateState();
		bool accelerationInProgress{ false };
		bool turnToRight{ false };
		bool turnToLeft{ false };

		Game& game;
		Space& space;
		sf::Clock lastShot{};

		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float FRICTION_COEFFICIENT{ 2.f };
		static constexpr float ANGULAR_VELOCITY{ 50 };
};

