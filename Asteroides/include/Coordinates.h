#pragma once

#include "../include/Vector.h"

class Coordinates
{
	public:
	Coordinates();
	Coordinates(int const& requestedX, int const& requestedY);
	static void initializeSpace(int const& requestedXLimit, int const& requestedYLimit);
	float getX() const;
	float getY() const;
	void operator+=(Vector const& vector);
	static float getSpaceWidth();
	static float getSpaceHeight();

	private:
	float x{};
	float y{};
	static float xLimit;
	static float yLimit;

};

