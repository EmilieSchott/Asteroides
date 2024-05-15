#pragma once

#include "../include/SpaceElement.h"

class Missile : public SpaceElement 
{
	public : 
		Missile(Coordinates const& spaceShipPosition, float rotation);
		virtual void reactToCollision(TypeElement otherType) override;

	private:
		static constexpr float SPEED{2000.f};

};

