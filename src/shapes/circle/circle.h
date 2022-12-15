#ifndef ASSESSMENT_2_CIRCLE_H
#define ASSESSMENT_2_CIRCLE_H


#include "../shape/shape.h"
#include "../movable/movable.h"

class Circle : public Shape, public Movable {
public:
    explicit Circle(Point *leftTop, float radius);
    void move(Point *newLeftTop) override;
    void scale(float xMultiplier, float yMultiplier) override;
    void calculateArea() override;
    void calculatePerimeter() override;
    void calculatePoints() override;
    string toString() override;

    virtual ~Circle();

private:
    /// The radius of the circle.
    float _radius;
};


#endif //ASSESSMENT_2_CIRCLE_H
