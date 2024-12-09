#include <iostream>
#include <string>

class Date {
    private:
        int day, month, year;
    public:
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
    Apointment arr[] = {
        Apointment("1", "Kolyo", "bol u kurcu", Date(12,1,2004)),
        Apointment("2", "taskata", "i tase ne znae", Date(7,9,1999))
    };
    const int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; ++i) {
        arr[i].display();
    }

    return 0;
}