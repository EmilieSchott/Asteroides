#pragma once
#include "../include/SpaceElement.h"

class Explosion : public SpaceElement 
{
	public :
		explicit Explosion();
		void begin(Coordinates const& spaceShipPosition);
		virtual void update(float duration) override;
		virtual void display(sf::RenderWindow& window) const override;
		virtual void reactToCollision() override; // to delete when add MaterialElement class

	private:
		bool begun{ false };
		float age{};

		static constexpr float LIFE_SPAN{0.1f};
};

