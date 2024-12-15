/* IMG_7143.PNG */

#include <iostream>
#include <string>

class Date {
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        Date() { // for testing purposses
            day = 1;
            month = 1;
            year = 2000;
        }

        Date(const Date& d) {
            day = d.day;
            month = d.month;
            year = d.year;
        }
};

class Patient {
    private:
        std::string name;
        std::string egn;
        std::string injury;
        Date apoitmentDate;
    public:
        Patient(std::string name, std::string egn, const std::string& injury, Date d) : name(name), egn(egn), injury(injury), apoitmentDate(d) {}

        Patient() { // for testing purposses
            name = "Fyodor";
            egn = "123222";
            injury = "bolka";
            apoitmentDate = Date(10, 12, 1828);
        }

        std::string getName() const {
            return name;
        }

        std::string getInjury() const {
            return injury;
        }
};

int main() {
    Patient patients[10];

    for(int i = 0; i < 10; i++) {
        std::cout << patients[i].getName() << " " << patients[i].getInjury() << std::endl;
    }
    return 0;
}