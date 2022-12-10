#ifndef ASSESSMENT_2_MOVABLE_H
#define ASSESSMENT_2_MOVABLE_H

#include "../point/point.h"

/// Abstract class that all shape classes derive from the implement movement functionality.
class Movable {
public:
    /// Mutates the shape's private _leftTop and _points fields.
    virtual void move(Point *newLeftTop) = 0;
    /// Mutates the shape's size by multiplying its current size with a given multiplier.
    virtual void scale(float multiplier) = 0;
};


#endif //ASSESSMENT_2_MOVABLE_H
