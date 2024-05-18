#include <SFML/Graphics.hpp>
#include "../include/SpaceElement.h"
#include "../include/Coordinates.h"
#include "../include/Space.h"
#include "../include/Game.h"

using namespace std;

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroides");
    Coordinates::initializeSpace(WINDOW_WIDTH, WINDOW_HEIGHT);
    auto space = Space{};
    auto game = Game{ space };

    while(window.isOpen()) {
        auto event = sf::Event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && game.isRunning() == false) {
                game.start();
            }
        }

        space.actualize();
        space.manageCollisions();

        window.clear();
        space.display(window);
        game.display(window);
        window.display();

        space.cleanUp();
    }

    return 0;
}