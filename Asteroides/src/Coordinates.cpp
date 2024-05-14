#include <cmath>
#include <algorithm>
#include "../include/Coordinates.h"
#include "../include/Vector.h"

using namespace std;

float Coordinates::xLimit = 0;
float Coordinates::yLimit = 0;

Coordinates::Coordinates() : x{ xLimit / 2 }, y{ yLimit / 2 } {

}

Coordinates::Coordinates(float const& requestedX, float const& requestedY) {
    x = requestedX;
    y = requestedY;

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

float Coordinates::calculateDistance(Coordinates& otherCoordinates) const {
    auto delta = Vector{ 
        min({ abs(x - otherCoordinates.x), abs(x - otherCoordinates.x - xLimit), abs(x - otherCoordinates.x + xLimit) }),
        min({ abs(y - otherCoordinates.y), abs(y - otherCoordinates.y - yLimit), abs(y - otherCoordinates.y + yLimit) })
    };
    auto distance = static_cast<float>(sqrt(pow(delta.x, 2) + pow(delta.y, 2)));
    return distance;
}