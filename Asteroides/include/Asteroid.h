#pragma once
#include "../include/SpaceElement.h"

class Asteroid : public SpaceElement // superclass should become MaterialElement
{
	public:
		explicit Asteroid();
		virtual void reactToCollision() override;
};

