#include "point.h"

Point::Point(float x, float y) : _x(x), _y(y) {}

float Point::getX() const {
    return _x;
}

float Point::getY() const {
    return _y;
}

Point Point::operator+(Point other) const {
    return {
            this->getX() + other.getX(), 
            this->getY() + other.getY()
    };
}

string Point::toString() {
    return "{" + to_string(this->getX()) + ", " + to_string(this->getY()) + "}";
}
