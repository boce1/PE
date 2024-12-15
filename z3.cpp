/* IMG_7141.PNG */

#include <iostream>
#include <string>

class Vehicle {
    protected:
        char brand;
        int year;
    public:
        Vehicle(char b, int y) : brand(b), year(y) {}

        virtual void showInfo() const {
            std::cout << brand << " " << year << "\n";
        }
};

class Car : public Vehicle {
    private:
        std::string plate;

    public:
        Car(char b, int y, const std::string& p) : Vehicle(b, y), plate(p) {}

        void showInfo() const override{
            std::cout << brand << " " << year << " " << plate << "\n";
        }
};

class RentCar : public Vehicle {
    private:
        double price;
    public:
        RentCar(char b, int y, double p) : Vehicle(b, y), price(p) {}

        void showInfo() const override{
            std::cout << brand << " " << year << " " << price << "\n";
        }
};

int main() {
    Vehicle v1 = Vehicle('A', 1999);
    Car c1 = Car('B', 2006, "VR-094SM");
    RentCar r1 = RentCar('C', 2020, 600.50);

    v1.showInfo();
    c1.showInfo();
    r1.showInfo();
    return 0;
}

/*
Yes, in C++, the parameters in a constructor’s initializer list can have the same names as the member variables. When this happens, 
the member variables are accessed using the this pointer to distinguish them from the parameters.
*/