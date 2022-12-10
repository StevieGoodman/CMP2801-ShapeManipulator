#ifndef ASSESSMENT_2_POINT_H
#define ASSESSMENT_2_POINT_H

using namespace std;
#include <string>

/// Represents a point in space on a 2D plane.
class Point {
public:
    /// Creates a new Point object with a given set of x and y coordinates.
    Point(float x, float y);
    /// Getter method for private member field _x.
    float getX() const;
    /// Getter method for private member field _y.
    float getY() const;
    /// Returns a string describing the point.
    string toString() const;
    /// Overloads the addition operator.
    Point * operator+(Point other) const;

private:
    /// Horizontal component of position in 2D space.
    float _x;
    /// Vertical component of position in 2D space.
    float _y;
};


#endif //ASSESSMENT_2_POINT_H
