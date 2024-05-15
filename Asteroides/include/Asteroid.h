#pragma once
#include "../include/SpaceElement.h"
#include "../include/Space.h"

class Asteroid : public SpaceElement // superclass should become MaterialElement
{
	public:
		explicit Asteroid(Space& p_space, Asteroid* parent = nullptr);
		virtual void reactToCollision(TypeElement otherType) override;

	private:
		Space& space;
};

