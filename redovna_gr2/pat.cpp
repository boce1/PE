#include <iostream>
#include <string>

class Date {
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        std::string display() const {
            return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
        }
};

class Apoitment {
    private:
        std::string egn;
        std::string patientName;
        std::string diagnose;
        Date date;
    public:
        Apoitment(const std::string& egn, const std::string& name, const std::string& diagnose, const Date& d) : egn(egn), patientName(name), diagnose(diagnose), date(d) {}

        std::string getDiagnose() const {
            return diagnose;
        }
        std::string getEgn() const {
            return egn;
        }
        std::string getPatientName() const {
            return patientName;
        }
        Date getDate() const {
            return date;
        }
};

void dipslayApoitments(Apoitment* apoitments, const int size , const std::string& diagnose) {
    for(int i = 0; i < size; ++i) {
        if(apoitments[i].getDiagnose() == diagnose) {
            std::cout << apoitments[i].getEgn() << " " << apoitments[i].getPatientName() << " " << apoitments[i].getDate().display() << std::endl;
        }
    }
}


int main() {
    Apoitment arr[] = {
        Apoitment("123222", "Fyodor", "depression", Date(10, 12, 2004)),
        Apoitment("456555", "Seneca", "ptsd", Date(1, 1, 1999)),
        Apoitment("123", "Marcus", "depression", Date(2, 3, 2007))
    };
    const int n = sizeof(arr) / sizeof(arr[0]);

    dipslayApoitments(arr, n, "depression");

    return 0;
}