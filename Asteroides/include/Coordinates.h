#pragma once

#include "../include/Vector.h"

class Coordinates
{
	public:
		static void initializeSpace(int const& requestedXLimit, int const& requestedYLimit);
		static inline float getSpaceWidth() { return xLimit; };
		static inline float getSpaceHeight() { return yLimit; };

		Coordinates();
		Coordinates(float const& requestedX, float const& requestedY);
		
		inline float getX() const {	return x; };
		inline float getY() const {	return y; };

		void operator+=(Vector const& vector);
		float calculateDistance(Coordinates& otherCoordinates) const;

	private:
		float x{};
		float y{};

		static float xLimit;
		static float yLimit;

};

