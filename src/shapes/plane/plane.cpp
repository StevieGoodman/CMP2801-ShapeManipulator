#include "plane.h"

void Plane::addShape(Shape *shape) {

}

void Plane::removeShape(int index) {

}

Plane::~Plane() {
    std::for_each( // I could have use a for loop but wanted to demonstrate my understanding of iterators and lambdas.
            this->_shapes.begin(), 
            this->_shapes.end(), 
            [](Shape* shape) { delete shape; }
            );
}
