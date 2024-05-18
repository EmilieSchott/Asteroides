#pragma once
#include "../include/SpaceElement.h"
#include <SFML/Audio.hpp>

class Explosion : public SpaceElement 
{
	public :
		explicit Explosion(Coordinates const& otherObjectPosition);
		virtual void reactToCollision(TypeElement otherType) override; // to delete when add MaterialElement class

	protected:
		virtual void update(float duration) override;

	private:
		float age{};
		sf::Sound sound;
		static constexpr float LIFE_SPAN{0.1f};
};

