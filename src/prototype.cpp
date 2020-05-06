#include <vector>
#include <cassert>

class Shape {
public:
    int x;
    int y;

    Shape(Shape const &source) = default;

    Shape() : x(0), y(0) {}

    virtual Shape *clone() = 0;

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    int width;
    int height;

    Rectangle(Rectangle const &source) = default;

    Rectangle() : Shape(), width(0), height(0) {}

    Rectangle *clone() override {
        return new Rectangle(*this);
    }
};

class Circle : public Shape {
public:
    int radius;

    Circle(Circle const &source) = default;

    Circle() : Shape(), radius(0) {}

    Circle *clone() override {
        return new Circle(*this);
    }
};

int main() {
    auto shapes = std::vector<Shape *>();
    auto circle = new Circle();
    circle->x = 100;
    circle->y = 100;
    circle->radius = 20;
    shapes.push_back(circle);
    shapes.push_back(circle->clone());

    assert(dynamic_cast<Circle *>(shapes[0])->radius == dynamic_cast<Circle *>(shapes[1])->radius);
}