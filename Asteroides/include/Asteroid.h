#pragma once
#include "../include/SpaceElement.h"
#include "../include/Space.h"
#include "../include/Game.h"


class Asteroid : public SpaceElement // superclass should become MaterialElement
{
	public:
		explicit Asteroid(Game& p_game, Space& p_space, Asteroid* parent = nullptr);
		virtual void reactToCollision(TypeElement otherType) override;

	private:
		Space& space;
		Game& game;
};

