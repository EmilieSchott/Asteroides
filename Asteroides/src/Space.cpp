#include "../include/Space.h"
#include "../include/SpaceElement.h"
#include <vector>
#include <memory>

using namespace std;

Space::Space() {

}

void Space::add(unique_ptr<SpaceElement> spaceElement) {
    newSpaceElements.push_back(move(spaceElement));
}

void Space::actualize() {
    auto loopTime = chrono.restart().asSeconds();
    for (auto i{ 0u }; i<spaceElements.size(); i++) {
        spaceElements[i]->actualize(loopTime);
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
    auto firstElementToCleanUp = remove_if(begin(spaceElements), end(spaceElements), SpaceElement::isDestroyed);
    spaceElements.erase(firstElementToCleanUp, end(spaceElements));
    for (auto& newSpaceElement : newSpaceElements) {
        spaceElements.push_back(move(newSpaceElement));
    }
    newSpaceElements.clear();
}