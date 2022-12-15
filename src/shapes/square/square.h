#ifndef ASSESSMENT_2_SQUARE_H
#define ASSESSMENT_2_SQUARE_H

#include "../shape/shape.h"
#include "../movable/movable.h"

/// A quadrilateral with perpendicular sides with equal lengths.
class Square : public Shape, public Movable {
public:
    /// Creates a new square from a position and size.
    Square(Point* leftTop, float size);
    void move(Point *newLeftTop) override;
    void scale(float xMultiplier, float yMultiplier) override;
    void calculateArea() override;
    void calculatePerimeter() override;
    void calculatePoints() override;
    string toString() override;

    virtual ~Square();

private:
    /// The length of each side of the square.
    float _edge;
};


#endif //ASSESSMENT_2_SQUARE_H
