/* chitatel i biblioteka */

#include <iostream>
#include <string>

class Reader {
    protected:
        std::string name;
        int id;
    public:
        Reader(std::string name, int id) : name(name), id(id) {}
};

class Library : public Reader {
    private:
        std::string status;
        std::string bookName;  
    public:
        Library(std::string readerName, int readerId, std::string status, std::string bookname) : Reader(readerName, readerId), status(status), bookName(bookname) {}

        std::string getStatus() const {
            return this->status;
        }

        void takeBook() {
            if(status == "taken") {
                status = "no taken";
            } else if(status == "no taken") {
                status = "taken";
            } else {
                std::cout << "Invalid status userId " << id << "\n";
            }
        }

        bool isTaken() {
            return getStatus() == "taken";
        }

        void display() const {
            std::cout << id << " " << name << " " << bookName << std::endl;
        }
};

int main() {
    const int n = 4;
    Library books[] = {
        Library("Fyodor", 1, "taken", "Crime and punishment"),
        Library("Seneca", 2, "no taken", "Ltter of stoic"),
        Library("Franz", 3, "no taken", "Metamorfossys"),
        Library("Marcus", 4, "no taken", "Meditations"),
    };

    for(int i = 0; i < n; ++i) {
        if(!books[i].isTaken()) {
            books[i].display();
        }

    }
    
    return 0;
}