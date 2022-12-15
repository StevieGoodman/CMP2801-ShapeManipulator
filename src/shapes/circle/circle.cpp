#include <cmath>
#include "circle.h"

Circle::Circle(Point *leftTop, float radius) 
    : _radius(radius) {
    this->_leftTop = leftTop;
    this->name = __func__;
    this->_isCircular = true;
    calculateArea();
    calculatePerimeter();
    calculatePoints();
}

void Circle::move(Point *newLeftTop) {
    this->_leftTop = newLeftTop;
    this->calculatePoints();
}

void Circle::scale(float xMultiplier, float yMultiplier) {
    this->_radius *= xMultiplier;
    calculatePoints();
    calculateArea();
    calculatePerimeter();
}

void Circle::calculateArea() {
    this->_area = M_PI * _radius * _radius;
}

void Circle::calculatePerimeter() {
    this->_perimeter = 4 * M_PI * _radius;
}

void Circle::calculatePoints() {
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
    Point* rightBottom = *this->_leftTop + Point(this->_radius, this->_radius);
    this->_points = vector<Point*>{
            leftTop,
            rightBottom
    };
}

string Circle::toString() {
    string size      = to_string(this->_radius);
    string position  = this->_leftTop->toString();
    string points    =
            this->_points.at(0)->toString() + ", " +
            this->_points.at(1)->toString();
    string area      = to_string(this->_area);
    string perimeter = to_string(this->_perimeter);
    string circular  = (to_string(this->_isCircular) == "1") ? "Yes" : "No";
    return "Position: " + position
           + "\nSize: " + size
           + "\nArea: " + area
           + "\nPerimeter: " + perimeter
           + "\nCircular: " + circular
           + "\nPoints: " + points;
}
