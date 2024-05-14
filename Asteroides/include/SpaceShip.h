#pragma once

#include <SFML/Graphics.hpp>
#include "../include/SpaceElement.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"
#include "../include/Explosion.h"
#include "../include/Space.h"

class SpaceShip : public SpaceElement { // superclass should become MaterialElement
	public:
		explicit SpaceShip(Space& spaceReference, sf::Color const& color);

		virtual void reactToCollision() override;

	protected:
		virtual void update(float duration) override;

	private:
		void updateState();
		bool accelerationInProgress{ false };
		bool turnToRight{ false };
		bool turnToLeft{ false };

		Space& space;

		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float FRICTION_COEFFICIENT{ 2.f };
		static constexpr float ANGULAR_VELOCITY{ 50 };
};

