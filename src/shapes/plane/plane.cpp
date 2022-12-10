#include "plane.h"

void Plane::addShape(Shape *shape) {
    this->_shapes.push_back(shape);
}

void Plane::removeShape(int index) {
    this->_shapes.erase(next(_shapes.begin(), index));
}

Plane::~Plane() {
    std::for_each( // I could have use a for loop but wanted to demonstrate my understanding of iterators and lambdas.
            this->_shapes.begin(), 
            this->_shapes.end(), 
            [](Shape* shape) { delete shape; }
            );
}
