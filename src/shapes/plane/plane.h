#ifndef ASSESSMENT_2_PLANE_H
#define ASSESSMENT_2_PLANE_H

#include <sstream>
#include <vector>
#include <iostream>
#include "../shape/shape.h"

/// Represents a container for 2D objects.
class Plane {
public:
    /// Performs memory management on shape objects in private member field _shapes.
    virtual ~Plane();
    /// Inserts a shape to the plane.
    void addShape(Shape* shape);
    /// Removes a shape from the plane.
    void removeShape(int index);
    /// Moves the nth shape to a new location on the plane.
    void moveShape(int index, Point* newPos);
    /// Offsets a shape's position by a given offset.
    void transformShape(int index, Point offset);
    /// Scales the nth shape on the plane by a given multiplier.
    void scaleShape(int index, float xMultiplier, float yMultiplier);
    /// Gets detailed information on the nth shape on the plane.
    string getInfo(int index);
    /// Displays a concise list of shapes on the plane.
    void printList();
    /// Empties the plane of any shapes on it.
    void clearList();
private:
    vector<Shape*> _shapes;
    /// Used to apply clamping to an integer to a shape's index.
    void clampIndex(int &index) const;
};


#endif //ASSESSMENT_2_PLANE_H
