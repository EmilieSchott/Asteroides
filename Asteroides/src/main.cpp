#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../include/SpaceElement.h"
#include "../include/SpaceShip.h"
#include "../include/Coordinates.h"
#include "../include/Asteroid.h"
#include "../include/Space.h"

using namespace std;

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };
const sf::Color SPACESHIP_COLOR{128, 255, 128};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroides");
    Coordinates::initializeSpace(WINDOW_WIDTH, WINDOW_HEIGHT);
    auto space = Space{};
    auto gameBegun{ false };
    auto chrono = sf::Clock{};

    while(window.isOpen()) {
        auto event = sf::Event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && gameBegun == false) {
                space.add(make_unique<SpaceShip>(space, SPACESHIP_COLOR));
                space.add(make_unique<Asteroid>());
                space.add(make_unique<Asteroid>());
                space.add(make_unique<Asteroid>());
                gameBegun = true;
            }
        }

        space.actualize();
        space.manageCollisions();
        space.cleanUp();

        window.clear();
        space.display(window);
        window.display();
    }

    return 0;
}