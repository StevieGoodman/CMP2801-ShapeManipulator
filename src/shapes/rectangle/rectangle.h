#ifndef ASSESSMENT_2_RECTANGLE_H
#define ASSESSMENT_2_RECTANGLE_H

#include "../shape/shape.h"
#include "../movable/movable.h"

class Rectangle : public Shape, public Movable {
public:
    Rectangle(Point *leftTop, float height, float width);
    void calculateArea() override;
    void calculatePerimeter() override;
    void calculatePoints() override;
    string toString() override;
    void move(Point *newLeftTop) override;
    void scale(float xMultiplier, float yMultiplier) override;

private:
    /// Vertical size of the rectangle.
    float _height;
    /// Horizontal size of the rectangle.
    float _width;
};


#endif //ASSESSMENT_2_RECTANGLE_H
