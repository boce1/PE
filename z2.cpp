/* IMG_7138.PNG */  

#include <iostream>

class Point {
    private:
        int x, y;
        char name;
    public:
        Point() {
            std::cout << "x = ";
            std::cin >> x;
            std::cout << "y = ";
            std::cin >> y;
            std::cout << "name = ";
            std::cin >> name;
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        char getName() const {
            return name;
        }
};

class Circle {
    private:
        int radius;
        Point center; // will be automatticly created
    public:
        Circle() {
            // Point center will be automatticly created
            std::cout << "radius = ";
            std::cin >> radius;
        }

        void getInfo() const {
            std::cout << "Circle " << center.getName() << "\n";
            std::cout << "x = " << center.getX() << "\n";
            std::cout << "y = " << center.getY() << "\n";
            std::cout << "r = " << radius << "\n";
        }

        int getRadius() const {
            return radius;
        }
};

int main() {
    const int n = 5; 
    Circle arr[n]; // will automatticly call constructors

    for(int i = 0; i < n; ++i) {
        if(arr[i].getRadius() > 10) {
            arr[i].getInfo();
        }
    }

    //Circle c1 = Circle();
    //c1.getInfo();
    return 0;
}