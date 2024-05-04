#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/SpaceShip.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroides");
    auto spaceShip = SpaceShip(sf::Color::Yellow);
    auto chrono = sf::Clock{};

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            spaceShip.updateState(event);
        }
        spaceShip.update(chrono.restart().asSeconds());

        window.clear();
        spaceShip.display(window);
        window.display();
    }

    return 0;
}