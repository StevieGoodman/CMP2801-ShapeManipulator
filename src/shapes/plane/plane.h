#ifndef ASSESSMENT_2_PLANE_H
#define ASSESSMENT_2_PLANE_H

#include <vector>
#include "../shape/shape.h"

/// Represents a container for 2D objects.
class Plane {
public:
    /// Inserts a shape to the plane.
    void addShape(Shape* shape);
    /// Removes a shape from the plane.
    void removeShape(int index);
    /// Performs memory management on shape objects in private member field _shapes.
    virtual ~Plane();

private:
    vector<Shape*> _shapes;
};


#endif //ASSESSMENT_2_PLANE_H
