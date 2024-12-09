/*
I am making an array with apointments and if i dont define members first it gives me an error
and thats why i made default constuctors
*/

#include <iostream>
#include <string>

class Date {
    private:
        int day, month, year;
    public:
        Date() {}
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        void display() {
            std::cout << day << "." << month << "." << year << ".\n";
        }
};

class Apointment {
    private:
        std::string egn;
        std::string name;
        std::string injury;
        Date date;
    public:
        Apointment() {}
        Apointment(const std::string& e, const std::string& n, 
                    const std::string& i, const Date& d) : 
                    egn(e), name(n), injury(i), date(d) {}
                    
        void display() {
            std::cout << egn << " " << name << " " << injury << ".\n";
            date.display();
        }
};

int main()
{
    std::string names[] = {"Kolyo", "Ivan", "Tase"};
    std::string egns[] = {"1", "2", "3"};
    std::string inj[] = {"bol u kurcu", "psihoza", "i tase ne znae"};
    
    Apointment arr[3];
    for(int i = 0; i < 3; ++i) {
        arr[i] = Apointment(egns[i], names[i], inj[i], Date(5 * i, i + 2, 2021 + i));
        arr[i].display();
    }

    return 0;
}