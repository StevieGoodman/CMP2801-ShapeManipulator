#ifndef ASSESSMENT_2_POINT_H
#define ASSESSMENT_2_POINT_H

/// Represents a point in space on a 2D plane.
class Point {
public:
    /// Creates a new Point object with a given set of x and y coordinates.
    Point(float x, float y);
    /// Getter method for private member field _x.
    float getX() const;
    /// Getter method for private member field _y.
    float getY() const;

private:
    /// Horizontal component of position in 2D space.
    const float _x;
    /// Vertical component of position in 2D space.
    const float _y;
};


#endif //ASSESSMENT_2_POINT_H
