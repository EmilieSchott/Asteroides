#include <iostream>
#include <string_view>
#include <array>
#include "../include/SpaceElement.h"

using namespace std;

SpaceElement::SpaceElement(string_view const& imagePath) {
	if (!texture.loadFromFile(imagePath.data())) {
		cerr << "L'image " << imagePath << " n'a pas ete correctement chargee";
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());
	speed = { 100,20 };
}

void SpaceElement::update(float duration) {
	auto movement = speed * duration;
	position += movement;
	sprite.setPosition(position.getX(), position.getY());
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
