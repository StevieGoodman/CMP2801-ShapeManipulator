using namespace std;
#include <algorithm>
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
    clampIndex(index);
    this->_shapes.erase(next(_shapes.begin(), index-1));
}

void Plane::moveShape(int index, Point* newPos) {
    clampIndex(index);
    dynamic_cast<Movable*>(this->_shapes.at(index-1))->move(newPos);
}

void Plane::scaleShape(int index, float xMultiplier, float yMultiplier) {
    clampIndex(index);
    dynamic_cast<Movable *>(this->_shapes.at(index-1))->scale(xMultiplier, yMultiplier);
}

void Plane::scaleShape(int index, float xMultiplier) {
    this->scaleShape(index, xMultiplier, xMultiplier);
}

string Plane::getInfo(int index) {
    clampIndex(index);
    return this->_shapes.at(index-1)->toString();
}

void Plane::transformShape(int index, Point offset) {
    clampIndex(index);
    Shape* shape = this->_shapes.at(index-1);
    dynamic_cast<Movable*>(shape)->move(*shape->_leftTop + offset);
}

void Plane::clearList() {
    if (this->_shapes.empty()) { return; } // Prevents segmentation faults when plane is empty.
    for (int index=0; index<=this->_shapes.size(); index++) {
        removeShape(index);
    }
}

void Plane::printList() {
    stringstream output;
    for (int index=1; index<=this->_shapes.size(); index++) {
        Shape* shape = this->_shapes.at(index-1);
        output << index << ": " << shape->name << " [" << *shape->_leftTop << "]" << endl;
    }
    if (output.str().empty()) { // Adds a message if plane is empty.
        output << "There are no shapes on the plane! 🥲"; 
    }
    cout << output.str() << endl;
}

void Plane::clampIndex(int &index) const {
    index = min((int)this->_shapes.size(), max(index, 1));
}