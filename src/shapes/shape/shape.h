#ifndef ASSESSMENT_2_SHAPE_H
#define ASSESSMENT_2_SHAPE_H

using namespace std;
#include <vector>
#include "../point/point.h"

/// Abstract class that all other shape classes derive functionality and fields from.
class Shape {
    friend class Plane;   // This allows Plane to access _leftTop for the Plane::transformShape().
public:
    /// Creates a new shape from a position.
    explicit Shape(Point* leftTop);
    /// Calculates the area of the shape and mutates the private member field _area accordingly.
    virtual void calculateArea() = 0;
    /// Calculates the perimeter of the shape and mutates the private member field _perimeter accordingly.
    virtual void calculatePerimeter() = 0;
    /// Calculates the position of each vertex and mutates the private member field _points accordingly.
    virtual void calculatePoints() = 0;
    /// Returns a string containing characteristics of the shape.
    virtual string toString() = 0;
    
protected:
    /// The total enclosed area of this shape.
    float _area;
    /// The total surface area of this shape.
    float _perimeter;
    /// Used for determining if the shape is circular.
    bool _isCircular;
    /// Top-left-most point of the shape.
    Point* _leftTop;
    /// Vector containing all the vertices of the shape.
    vector<Point *> _points;
};


#endif //ASSESSMENT_2_SHAPE_H
