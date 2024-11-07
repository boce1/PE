#include <iostream>
#include <vector>

class Temprature {
    protected:
        double value;
    public:
        Temprature(double v) : value(v) {};

        double getValue() const {
            return value;
        }

        void setValue(double v) {
            value = v;
        }

        virtual double convertToCelsius() = 0;
};

class Farainhait : public Temprature {
    public:
        Farainhait(double v) : Temprature(v) {};

        double convertToCelsius() override {
            return 5.0 / 9.0 * (getValue() - 32.0);
        }
};

int main() {
    std::vector<Farainhait*> temps;
    temps.push_back(new Farainhait(20)); // memory leak, but for testing purosses
    temps.push_back(new Farainhait(0));
    temps.push_back(new Farainhait(100));
    temps.push_back(new Farainhait(55.3));
    
    for(const auto& temp : temps) {
        std::cout << temp->getValue() << " F -> " << temp->convertToCelsius() << " C\n" ;
    }
    return 0;
}