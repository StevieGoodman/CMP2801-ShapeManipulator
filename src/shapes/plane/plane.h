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
    void printList() {
        stringstream output;
        for (int index=1; index<=this->_shapes.size(); index++) {
            Shape* shape = this->_shapes.at(index-1);
            output << index << ": " << shape->name << " [" << *shape->_leftTop << "]" << endl;
        }
        cout << output.str() << endl;
    }
    /// Empties the plane of any shapes on it.
    void clearList();
private:
    vector<Shape*> _shapes;
};


#endif //ASSESSMENT_2_PLANE_H
