#include <iostream>

class Point {
    private:
        int x, y;
        char name;
    public:
        Point() {
            std::cout << "Initilazing point\n";
            std::cin >> x;
            std::cin >> y;
            std::cin >> name; 
        }

        int getX() const {
            return this->x;
        }
        int getY() const {
            return this->y;
        }
        char getName() const {
            return this->name;
        }

        void setX(int x) {
            this->x = x;
        }
        void setY(int y) {
            this->y = y;
        }
        void setName(char name) {
            this->name = name;
        }
};

class Circle {
    private: 
        int radius;
        Point center; // compiler will for x,y and name when Circle object is created
        // because default constructor want to read values from terminal
    public:
        Circle() {
            std::cout << "radius\n";
            std::cin >> radius;
        }

        int getRadius() const {
            return this->radius;
        }
        void setRadius(int radius) {
            this->radius = radius;
        }

        void dipslayInfo() {
            std::cout << "(" << center.getX() << " " << center.getY() << ") " << radius << " " << center.getName() << "\n";
        }
};

int main() {
    Circle circles[5];
    for(int i = 0; i < 5; i++) {
        if(circles[i].getRadius() > 10) {
            circles[i].dipslayInfo();
        }
    }
    return 0;
}