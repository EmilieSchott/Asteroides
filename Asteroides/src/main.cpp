#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/SpaceShip.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroides");
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    auto spaceShip = SpaceShip{};

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                spaceShip.moveForward();
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(circle);
        spaceShip.display(window);
        window.display();
    }

    return 0;
}