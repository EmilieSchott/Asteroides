#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Vector.h"
#include "../include/Coordinates.h"

class SpaceElement
{
	public:
		explicit SpaceElement(std::string_view const& imagePath);
		virtual ~SpaceElement() = default;
		SpaceElement(SpaceElement const& otherSpaceElement) = delete;
		void operator=(SpaceElement const& otherSpaceElement) = delete;
		virtual void display(sf::RenderWindow& window) const;
		void actualize(float duration);
		float getRadius() const;
		void testCollision(SpaceElement& otherElement);
		virtual void reactToCollision() = 0; // to move to MaterialElement class

	protected:
		virtual void update(float duration);

		sf::Texture texture{};
		sf::Sprite sprite{};
		Coordinates position{};
		Vector speed{ 0.f, 0.f }; // to move to MaterialElement class
		float angularVelocity{}; // to move to MaterialElement class
};
