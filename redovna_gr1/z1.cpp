/* imash brate krug i si ebe majkata */

#include <iostream>

class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) : x(x), y(y) {}

        /* ne e po uslovieto*/
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        void setX(int x) {
            this->x = x;
        }
        void setY(int y) {
            this->y = y;
        }
        /* ---- */
};

class Circle {
    private:
        int radius, id;
        Point center;
    public:
        Circle(int r, int i, Point c) : radius(r), id(i), center(c) {}

        int getId() const {
            return id;
        }

        int getRadius() const {
            return radius;
        }

        /* ne e po uslovieto */
        Point getCenter() const {
            return center;
        }
        void setRadius(int r) {
            this->radius = r;
        }
        void setY(int id) {
            this->id = id;
        }
        void setCenter(Point c) {
            center = c; // default copy constructor
        }
        /* ---- */
}; 

int main() {
    const int n = 4;
    Circle circles[] = {
        Circle(5, 1, Point(1, 1)),
        Circle(11, 2, Point(2, 1)),
        Circle(2, 3, Point(1, 3)),
        Circle(20, 4, Point(4, 1)),
    };

    for(int i = 0; i < n; ++i) {
        if(circles[i].getRadius() > 10)
            std::cout << circles[i].getId() << "\n";
    }

    return 0;
}