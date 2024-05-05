#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/SpaceShip.h"
#include "../include/Coordinates.h"

using namespace std;

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };
const sf::Color SPACESHIP_COLOR{128, 255, 128};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroides");
    Coordinates::initializeSpace(WINDOW_WIDTH, WINDOW_HEIGHT);
    auto spaceShip = SpaceShip(SPACESHIP_COLOR);
    auto chrono = sf::Clock{};

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        spaceShip.updateState();
        spaceShip.update(chrono.restart().asSeconds());

        window.clear();
        spaceShip.display(window);
        window.display();
    }

    return 0;
}