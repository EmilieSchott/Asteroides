#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Vector.h"
#include "../include/Coordinates.h"

enum class TypeElement {SPACESHIP, ASTEROID, MISSILE, OTHER};

class SpaceElement
{
	public:
		explicit SpaceElement(std::string_view const& imagePath);
		virtual ~SpaceElement() = default;
		SpaceElement(SpaceElement const& otherSpaceElement) = delete;
		void operator=(SpaceElement const& otherSpaceElement) = delete;
		virtual void display(sf::RenderWindow& window) const;
		void actualize(float duration);

		/* isDestroyed is used in remove_if() arguments list. (see src/Space.cpp file)
		For this, isDestroyed should have in argument the same type, or a reference for an object of the same type 
		that the one used by the array in remove_if() argument.
		Here, it's a unique pointer so passing by reference is mandatory */
		static inline float isDestroyed(std::unique_ptr<SpaceElement>& spaceElement) { return spaceElement->destroyed; };

		float getRadius() const;
		void testCollision(SpaceElement& otherElement);
		virtual void reactToCollision(TypeElement otherType) = 0; // to move to MaterialElement class

	protected:
		virtual void update(float duration);
		TypeElement type{TypeElement::OTHER};
		bool destroyed{ false };
		sf::Sprite sprite{};
		Coordinates position{};
		Vector speed{ 0.f, 0.f }; // to move to MaterialElement class
		float angularVelocity{}; // to move to MaterialElement class
};
