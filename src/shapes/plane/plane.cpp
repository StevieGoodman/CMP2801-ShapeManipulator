#include "plane.h"
#include "../movable/movable.h"

Plane::~Plane() {
    std::for_each( // I could have use a for loop but wanted to demonstrate my understanding of iterators and lambdas.
            this->_shapes.begin(),
            this->_shapes.end(),
            [](Shape* shape) { delete shape; }
    );
}

void Plane::addShape(Shape *shape) {
    this->_shapes.push_back(shape);
}

void Plane::removeShape(int index) {
    this->_shapes.erase(next(_shapes.begin(), index-1));
}

void Plane::moveShape(int index, Point* newPos) {
    dynamic_cast<Movable*>(this->_shapes.at(index-1))->move(newPos);
}

void Plane::scaleShape(int index, float xMultiplier, float yMultiplier) {
    dynamic_cast<Movable *>(this->_shapes.at(index-1))->scale(xMultiplier, -1);
}

string Plane::getInfo(int index) {
    return this->_shapes.at(index-1)->toString();
}

void Plane::transformShape(int index, Point offset) {
    Shape* shape = this->_shapes.at(index-1);
    dynamic_cast<Movable*>(shape)->move(*shape->_leftTop + offset);
}
