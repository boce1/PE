/*
Generics is the idea to allow type (Integer, String, … etc and user-defined types) to be a parameter to methods, 
classes and interfaces. For example, classes like an array, map, etc, which can be used using generics very efficiently. 
We can use them for any type.

The method of Generic Programming is implemented to increase the efficiency of the code. 
Generic Programming enables the programmer to write a general algorithm which will work with all data types. 
It eliminates the need to create different algorithms if the data type is an integer, string or a character.

The advantages of Generic Programming are:
- Code Reusability
- Avoid Function Overloading
- Once written it can be used for multiple times and cases.

Generics can be implemented in C++ using Templates. Template is a simple and yet very powerful tool in C++. 
The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. 
For example, a software company may need sort() for different data types. 
Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter.

source : Geeks for Geeks
*/

#include <iostream>
#include <memory>

template <typename T>
class array {
    private:
        int size;
        T* begin;

    public:
        array() : size(0), begin(nullptr) {}

        array(const int size) {
            begin = new T[size];
            
            if(begin == nullptr) {
                std::cerr << "Error: failed creating a array\n";
            } else {
                this->size = size;
                for(int i = 0; i < size; ++i) {
                    begin[i] = 0;
                }
            }
        }

        array(const array<T> &other) {
            T* new_begin = new T[other.size];
            if(new_begin != nullptr) {
                for(int i = 0; i < other.size; ++i) {
                    new_begin[i] = other.begin[i];
                }
                delete[] this->begin;
                this->begin = new_begin;
                this->size = other.size;
            } else {
                std::cerr << "Error: Failed copping array\n";
            }
        }

        array<T> operator=(const array<T> &other) {
            return array(other);
        }

        void insert_element(const int index, const T &element) {
            if(index >= 0 && index < size) {
                begin[index] = element;
            } else {
                std::cerr << "Error: invalid index\n";
            }
        }

        T get_element(const int index) const {
            if(index >= 0 && index < size) {
                return begin[index];
            }
            return T();
        }

        void push_back(const T &element) {
            T* new_begin = new T[size + 1];
            if(new_begin != nullptr) {
                for(int i = 0; i < size; ++i) {
                    new_begin[i] = begin[i];
                }
                delete[] begin;
                new_begin[size++] = element;
                begin = new_begin;
            } else {
                std::cerr << "Error: Failed pushing element";
                delete new_begin;
            }
        }

        int get_size() const {
            return this->size;
        }

        void change_size(const int new_size) {
            if(new_size >= 0) {
                T* new_begin = new T[new_size];
                if(new_begin != nullptr) {
                    for(int i = 0; i < size; ++i) {
                        new_begin[i] = begin[i];
                    }
                    for(int i = size; i < new_size; i++) {
                        new_begin[i] = 0;
                    }
                    delete[] begin;
                    begin = new_begin;
                    size = new_size;
                } else {
                    std::cerr << "Error: Failed changing size\n";
                }
            } else {
                std::cerr << "Error: invalid size\n";
            }
        }   

        ~array() {
            delete[] begin;
        }

};

template <typename T>
std::ostream& operator<<(std::ostream &os, const array<T> &arr) {
    os << "{ ";
    for(int i = 0; i < arr.get_size(); ++i) {
        os << arr.get_element(i) << " ";
    }
    os << "}\n";
    return os;
}

int main() {
    array<int> arr1;
    arr1.push_back(5);
    arr1.push_back(6);
    arr1.push_back(1);
    arr1.push_back(4);
    arr1.push_back(2);
    std::cout << arr1;

    array<int> arr2(arr1);
    std::cout << arr2;

    array<int> arr3 = arr1;
    arr3.insert_element(0, 100);
    std::cout << arr3;

    arr3.change_size(10);
    std::cout << arr3;

    arr3.change_size(3);
    std::cout << arr3;

    return 0;
}