#include "rectangle.h"

Rectangle::Rectangle(Point *leftTop, float height, float width)
        : _height(height), _width(width) {
    this->_leftTop = leftTop;
    this->name = __func__;
    this->_isCircular = false;
    calculateArea();
    calculatePerimeter();
    calculatePoints();
}

void Rectangle::calculateArea() {
    this->_area = _width * _height;
}

void Rectangle::calculatePerimeter() {
    this->_perimeter = 2 * (_width + _height);
}

void Rectangle::calculatePoints() {
    // Deallocate memory from old points.
    std::for_each(
            this->_points.begin(),
            this->_points.end(),
            [this](Point* point){
                if (point == this->_leftTop) { return; }
                delete point;
            }
    );
    // Insert new points.
    Point* leftTop     = this->_leftTop;
    Point* rightTop    = *this->_leftTop + Point(this->_width, 0);
    Point* leftBottom  = *this->_leftTop + Point(0, this->_height);
    Point* rightBottom = *this->_leftTop + Point(this->_width, this->_height);
    this->_points = vector<Point*>{
            leftTop,
            rightTop,
            rightBottom,
            leftBottom
    };
}

string Rectangle::toString() {
    string width     = to_string(this->_width);
    string height    = to_string(this->_height);
    string position  = this->_leftTop->toString();
    string points    =
            this->_points.at(0)->toString() + ", " +
            this->_points.at(1)->toString() + ", " +
            this->_points.at(2)->toString() + ", " +
            this->_points.at(3)->toString();
    string area      = to_string(this->_area);
    string perimeter = to_string(this->_perimeter);
    string circular  = (to_string(this->_isCircular) == "1") ? "Yes" : "No";
    return "Position: " + position
           + "\nWidth: " + width
           + "\nHeight: " + height
           + "\nArea: " + area
           + "\nPerimeter: " + perimeter
           + "\nCircular: " + circular
           + "\nPoints: " + points;
}

void Rectangle::move(Point *newLeftTop) {
    this->_leftTop = newLeftTop;
    this->calculatePoints();
}

void Rectangle::scale(float xMultiplier, float yMultiplier) {
    this->_width *= xMultiplier;
    this->_height *= yMultiplier;
    calculatePoints();
    calculateArea();
    calculatePerimeter();
}
