/*
In order to initialize date variable, I need to use initializer list or default constructor
If i use default constructor for Date then in Apointement constructor i must change atributes to the new ones

Explanation:
When initializing Apointment and not using initizlizer list
all member variables need to be defined first before consructor Apointment executes.
I Date doesnt have default constructor then it gives an error.

If I want to avoid making default constructor for Date, then I need to use Initializer list.
Initializer list defines values for all members before constuctor executes.
In that case Date needs copy constructor
*/

#include <iostream>
#include <string>

class Date {
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

        std::string getInfo() const {
            return std::to_string(day) + "." +  std::to_string(month) + "." + std::to_string(year);
        }
};

class Apointment {
    private:
        std::string egn;
        std::string name;
        std::string injury;
        Date date;
        std::string medicine[5];

    public:
        Apointment(const std::string& egn, const std::string& name, const std::string& injury, const Date& date, std::string (&arr)[5]) 
        : egn(egn), name(name), injury(injury), date(date) { 
            // this->egn = egn;
            // this->name = name;
            // this->injury = injury;
            // this->date = date;
            /* neraboti bez inizalazer list zashtoto bez nego pri definirane na obekta prvo se sazdavat poletata
            sled tova im se davat stoynostite.
            Poneje nqma default contructor bez parametri dava greshka.
            S initializer list pri sazdavane na pole vednaga mu se dava stoynost */
            for(int i = 0; i < 5; ++i) {
                medicine[i] = arr[i];
            }
        }  

        friend std::ostream& operator<<(std::ostream& os, const Apointment& ap);
};

std::ostream& operator<<(std::ostream& os, const Apointment& ap) {
    os << ap.date.getInfo() << " " << ap.egn << " " << ap.name << " " << ap.injury << "\nMedicine: ";
    for(int i = 0; i < 5; ++i) {
        os << ap.medicine[i] << " ";
    }
    os << "\n";
    return os;
}

int main() {    
    std::string medicine[] = {"skopolamin", "lsd", "methamphetamin", "cocaine", "morphin"};
    Apointment a1("1232220", "Boyan", "ekzistencialna kriza", Date(1,1,2024), medicine);
    std::cout << a1;
    return 0;
}