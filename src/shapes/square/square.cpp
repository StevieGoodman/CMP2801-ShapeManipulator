using namespace std;
#include <string>
#include "square.h"

Square::Square(Point* leftTop, float size) 
    : _edge(size) {
    this->_leftTop = leftTop;
    this->name = __func__;
    this->_isCircular = false;
    calculateArea();
    calculatePerimeter();
    calculatePoints();
}

Square::~Square() {
    std::for_each(
            this->_points.begin(),
            this->_points.end(),
            [](Point* point){
                delete point;
            }
    );
}

void Square::scale(float xMultiplier, float yMultiplier) {
    this->_edge *= xMultiplier;
    calculatePoints();
    calculateArea();
    calculatePerimeter();
}

void Square::calculateArea() {
    this->_area = this->_edge * this->_edge;
}

void Square::calculatePerimeter() {
    _perimeter = this->_edge * 4;
}

void Square::calculatePoints() {
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
    Point* rightTop    = *this->_leftTop + Point(this->_edge, 0);
    Point* leftBottom  = *this->_leftTop + Point(0, this->_edge);
    Point* rightBottom = *this->_leftTop + Point(this->_edge, this->_edge);
    this->_points = vector<Point*>{
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
    string circular  = (to_string(this->_isCircular) == "1") ? "Yes" : "No";
    return "Position: " + position 
    + "\nSize: " + size
    + "\nArea: " + area
    + "\nPerimeter: " + perimeter
    + "\nCircular: " + circular
    + "\nPoints: " + points;
}

void Square::move(Point *newLeftTop) {
    this->_leftTop = newLeftTop;
    this->calculatePoints();
}
