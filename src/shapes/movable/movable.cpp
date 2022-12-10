#include "movable.h"
#include "../shape/shape.h"

void Movable::move(Point *newLeftTop) {
    auto* object = dynamic_cast<Shape*>(this);
    object->_leftTop = newLeftTop;
    object->calculatePoints();
}