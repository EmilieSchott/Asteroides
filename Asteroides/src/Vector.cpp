#include "../include/Vector.h"
#include <cmath>

const float Vector::PI{std::acosf(-1)};

void Vector::operator+=(Vector const& otherVector) {
	x += otherVector.x;
	y += otherVector.y;
}

void Vector::operator-=(Vector const& otherVector) {
	x -= otherVector.x;
	y -= otherVector.y;
}

Vector Vector::operator*(float coefficient) const {
	return { x * coefficient,y * coefficient };
}

Vector Vector::createFromAngle(float norm, float angleInDegree) {
	return { norm * cos(angleInDegree*(PI/180.f)), norm * sin(angleInDegree*(PI/180.f)) }; // *(PI/180.f) to convert degrees in radians

}
