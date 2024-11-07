/* IMG_7144.PNG  */

#include <iostream>

#define PI 3.141596

class AreaCircle {
    protected:
        double radius;

    public:
        AreaCircle(double r) : radius(r) {}

        virtual double area() = 0;

        double getRadius() const {
            return radius;
        }

        void setRadius(const double& radius) {
            this->radius = radius;
        }
};

class Circle : public AreaCircle {
    public:
        Circle(double r) : AreaCircle(r) {}

        double area() override {
            return PI * radius * radius;
        }
};

Circle* compareTwoCircles(Circle* c1, Circle* c2) {
    if(c1->area() > c2->area()) {
        return c1;
    } else if(c1->area() < c2->area()) {
        return c2;
    } else {
        return nullptr;
    }
}

int main() {
    /*
    Circle c1 = Circle(2);
    Circle c2 = Circle(7);
    Circle c3 = Circle(5.5);

    std::cout << c1.area() << std::endl;
    std::cout << c2.area() << std::endl;
    std::cout << c3.area() << std::endl;
    */

    Circle c1 = Circle(2);
    Circle c2 = Circle(2);

    Circle* biggerCirclePtr = compareTwoCircles(&c1, &c2);

    if(biggerCirclePtr != nullptr) {
        std::cout << biggerCirclePtr->getRadius() << " " << biggerCirclePtr->area() << "\n";
    } else {
        std::cout << "The circles have the same area\n";
    }

    return 0;
}