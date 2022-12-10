#include "movable.h"
#include "../shape/shape.h"

void Movable::move(Point *newLeftTop) {
    auto* shape = dynamic_cast<Shape*>(this);
    shape->_leftTop = newLeftTop;
    shape->calculatePoints();
}