#include <iostream>
#include <string_view>
#include <array>
#include "../include/SpaceElement.h"
#include "../include/Vector.h"
#include "../include/Coordinates.h"

using namespace std;

SpaceElement::SpaceElement(string_view const& imagePath) {
	if (!texture.loadFromFile(imagePath.data())) {
		cerr << "L'image " << imagePath << " n'a pas ete correctement chargee";
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::actualize(float duration) {
	update(duration);
	auto movement = speed * duration;
	position += movement;
	sprite.setPosition(position.getX(), position.getY());
	sprite.rotate(angularVelocity * duration);
}

void SpaceElement::update(float duration) {

}

void SpaceElement::display(sf::RenderWindow& window) const {
	auto displayVectors = array<Vector, 9>{
		Vector{ -1, -1 }, Vector{ -1, 0 }, Vector{ -1, 1 },
		Vector{ 0, -1 }, Vector{ 0, 0 }, Vector{ 0, 1 },
		Vector{ 1, -1 }, Vector{ 1, 0 }, Vector{ 1, 1 }
	};
	for (auto& displayVector : displayVectors) {
		auto transformation = sf::Transform{};
		transformation.translate(displayVector.x * Coordinates::getSpaceWidth(), displayVector.y * Coordinates::getSpaceHeight());
		window.draw(sprite, transformation);
	}

}

float SpaceElement::getRadius() const {
	return sprite.getLocalBounds().height / 2.f;
}

void SpaceElement::testCollision(SpaceElement& otherElement) {
	auto distance = position.calculateDistance(otherElement.position);
	if (distance < getRadius() + otherElement.getRadius()) {
		reactToCollision();
	}
}
