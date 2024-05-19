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
    // spaceElements is passed by reference in for struture because it's a unique pointer and couldn't be copied :
    for (auto& spaceElement : spaceElements) {
        spaceElement->actualize(loopTime);
    }
}

void Space::manageCollisions() {
    /* Use a classic for structure here beacause testCollision() add new elements in vector array spaceElements 
    if a base ranged for structure is use, its iterator will be lost with the new elements addition and 
    could cause some bugs */
    for (auto i{ 0u }; i < spaceElements.size(); i++) {
        for (auto j{ 0u }; j < spaceElements.size(); j++) {
            if (i != j) {
                spaceElements[i]->testCollision(*spaceElements[j]);
            }
        }
    }
}

void Space::display(sf::RenderWindow& window) const {
    // spaceElement is passed by reference in for struture because it's a unique pointer and couldn't be copied :
    for (auto& spaceElement : spaceElements) {
        spaceElement->display(window);
    }
}

void Space::cleanUp() {
    if (toClear == true) {
        spaceElements.clear();
        toClear = false;
    }/*
    auto firstElementToCleanUp = remove_if(begin(spaceElements), end(spaceElements), SpaceElement::isDestroyed);*/
    auto firstElementToCleanUp = remove_if(
        begin(spaceElements), end(spaceElements), 
        [] (auto& spaceElement) {return spaceElement->isDestroyed();} // create a lambda to determine if spaceElement should be destroyed
    );
    spaceElements.erase(firstElementToCleanUp, end(spaceElements));
    for (auto& newSpaceElement : newSpaceElements) {
        spaceElements.push_back(move(newSpaceElement));
    }
    newSpaceElements.clear();
}

void Space::clear() {
    toClear = true;
}