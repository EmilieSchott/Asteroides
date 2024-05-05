#include "../include/Coordinates.h"
#include "../include/Vector.h"

float Coordinates::xLimit = 0;
float Coordinates::yLimit = 0;

Coordinates::Coordinates() : x{ xLimit / 2 }, y{ yLimit / 2 } {

}

Coordinates::Coordinates(int const& requestedX, int const& requestedY) {
    x = static_cast<float>(requestedX);
    y = static_cast<float>(requestedY);

    if (x > xLimit) {
        x -= xLimit;
    }

    if (y > yLimit) {
        y -= yLimit;
    }
}

void Coordinates::initializeSpace(int const& requestedXLimit, int const& requestedYLimit) {
    xLimit = static_cast<float>(requestedXLimit);
    yLimit = static_cast<float>(requestedYLimit);
}

float Coordinates::getX() const {
    return x;
}

float Coordinates::getY() const {
    return y;
}

void Coordinates::operator+=(Vector const& vector) {
    x += vector.x;
    y += vector.y;

    if (x > xLimit) {
        x -= xLimit;
    }
    else if (x < 0) {
        x += xLimit;
    }

    if (y > yLimit) {
        y -= yLimit;
    }
    else if (y < 0) {
        y += yLimit;
    }
}