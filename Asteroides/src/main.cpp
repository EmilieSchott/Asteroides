#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>
#include "../include/SpaceElement.h"
#include "../include/SpaceShip.h"
#include "../include/Coordinates.h"
#include "../include/Asteroid.h"

using namespace std;

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };
const sf::Color SPACESHIP_COLOR{128, 255, 128};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroides");
    Coordinates::initializeSpace(WINDOW_WIDTH, WINDOW_HEIGHT);
    auto spaceShip = SpaceShip{ SPACESHIP_COLOR };
    auto asteroid = Asteroid{};
    auto asteroid2 = Asteroid{};
    auto asteroid3 = Asteroid{};
    auto spaceElements = array<SpaceElement*, 4>{&asteroid, &asteroid2, &asteroid3, &spaceShip};
    auto chrono = sf::Clock{};

    while(window.isOpen()) {
        auto event = sf::Event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        spaceShip.updateState();
        auto loopTime = chrono.restart().asSeconds();
        for (auto* spaceElement : spaceElements) {
            spaceElement->update(loopTime);
        }

        for (auto* spaceElement : spaceElements) {
            for (auto* otherSpaceElement : spaceElements) {
                if (spaceElement != otherSpaceElement) {
                    spaceElement->testCollision(*otherSpaceElement);
                }
            }
        }

        window.clear();
        for (auto* spaceElement : spaceElements) {
            spaceElement->display(window);
        }
        window.display();
    }

    return 0;
}