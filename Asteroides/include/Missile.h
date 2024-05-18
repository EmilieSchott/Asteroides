#pragma once

#include "../include/SpaceElement.h"
#include <SFML/Audio.hpp>

class Missile : public SpaceElement 
{
	public : 
		Missile(Coordinates const& spaceShipPosition, float rotation);
		virtual void reactToCollision(TypeElement otherType) override;

	private:
		sf::SoundBuffer buffer{};
		sf::Sound sound{};
		static constexpr float SPEED{2000.f};

};

