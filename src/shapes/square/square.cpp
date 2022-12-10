using namespace std;
#include <string>
#include "square.h"

#include <iostream>

Square::Square(Point* leftTop, float size) 
    : Shape(leftTop), _edge(size) {
    this->_isCircular = false;
    this->_area = calculateArea();
    this->_perimeter = calculatePerimeter();
    this->_points = calculatePoints();
}

void Square::scale(float multiplier) {
    this->_edge *= multiplier;
    this->_area = calculateArea();
    this->_points = calculatePoints();
}

float Square::calculateArea() {
    return this->_edge * this->_edge;
}

float Square::calculatePerimeter() {
    return this->_edge * 4;
}

vector<Point*> Square::calculatePoints() {
    Point* leftTop     = this->_leftTop;
    Point* rightTop    = *this->_leftTop + Point(this->_edge, 0);
    Point* leftBottom  = *this->_leftTop + Point(0, this->_edge);
    Point* rightBottom = *this->_leftTop + Point(this->_edge, this->_edge);
    return vector<Point*>{
        leftTop,
        rightTop,
        rightBottom,
        leftBottom
    };
}

string Square::toString() {
    string size      = to_string(this->_edge);
    string position  = this->_leftTop->toString();
    string points    = 
            this->_points.at(0)->toString() + ", " +
            this->_points.at(1)->toString() + ", " +
            this->_points.at(2)->toString() + ", " +
            this->_points.at(3)->toString();
    string area      = to_string(this->_area);
    string perimeter = to_string(this->_perimeter);
    return "Position: " + position 
    + "\nSize: " + size
    + "\nArea: " + area
    + "\nPerimeter: " + perimeter
    + "\nPoints: " + points;
}