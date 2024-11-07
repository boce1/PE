/* IMG_7136.PNG */

#include <iostream>

class Temperature {
    protected:
        double temp;
    public:
        virtual double transform() = 0;

        Temperature(double t) : temp(t) {}

        void setTemp(const double& t) {
            this->temp = t;
        }

        double getTemp() const {
            return temp;
        }
};

class Celsius : public Temperature {
    public:
        Celsius(double t) : Temperature(t) {}

        double transform() {
            return 5.0 / 9.0 * (this->temp - 32);
        }
};

int main()
{
    Temperature* t1;
    Celsius c(200);
    t1 = &c;
    
    std::cout << t1->getTemp() << std::endl;
    std::cout << t1->transform() << std::endl;

    return 0;
}