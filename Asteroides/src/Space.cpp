#include "../include/Space.h"
#include <vector>

Space::Space() {

}

void Space::add(std::unique_ptr<SpaceElement> spaceElement) {
	spaceElements.push_back(std::move(spaceElement));
}

void Space::actualize() {
    auto loopTime = chrono.restart().asSeconds();
    for (auto& spaceElement : spaceElements) {
        spaceElement->actualize(loopTime);
    }
}

void Space::manageCollisions() {
    for (auto i{ 0u }; i < spaceElements.size(); i++) {
        for (auto j{ 0u }; j < spaceElements.size(); j++) {
            if (i != j) {
                spaceElements[i]->testCollision(*spaceElements[j]);
            }
        }
    }
}

void Space::display(sf::RenderWindow& window) const {
    for (auto& spaceElement : spaceElements) {
        spaceElement->display(window);
    }
}

void Space::cleanUp() {
    auto firstElementToCleanUp = std::remove_if(std::begin(spaceElements), std::end(spaceElements), SpaceElement::isDestroyed);
    spaceElements.erase(firstElementToCleanUp, std::end(spaceElements));
}