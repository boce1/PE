/*
in C++, Operator overloading is a compile-time polymorphism. 
It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.

- Operator overloading allows user-defined types to behave like built-in types, making the code easier to understand and use. (readability)
- Simplified Syntax
- Supports Customization

cons:
- overloaded operators arent inherited
- Overloading too many operators for a class might confuse users and increase maintenance complexity
- Not Always Intuitive
- Debugging overloaded operators can be difficult because their implementation is not immediately visible.

Предефиниране на оператори в C++ позволява на програмистите да 
задават поведението на операторите за потребителски дефинирани типове 
данни. Това включва предефиниране на оператори като +, -, *, / и други за 
потребителски класове. 
*/

#include <iostream>

class complex {
    private:
        float real, imaginary;

    public:
        complex(float r, float i) : real(r), imaginary(i) {}
        complex() {}

        float getReal() const {
            return real;
        }
        float getImaginary() const {
            return imaginary;
        }

        void setReal(const float real) {
            this->real = real;
        }
        void setImaginary(const float imaginary) {
            this->imaginary = imaginary;
        }

        complex operator+(const complex& other) {
            return complex(this->real + other.real, this->imaginary + other.imaginary);            
        }

        complex operator-(const complex& other) {
            return complex(this->real - other.real, this->imaginary - other.imaginary);
        }

        complex operator*(const complex& other) {
            return complex(this->real * other.real - this->imaginary * other.imaginary, this->real * other.imaginary + other.real * this->imaginary);
        }

    friend std::ostream& operator<<(std::ostream& os, const complex& comp_num);
};

std::ostream& operator<<(std::ostream& os, const complex& comp_num) {
    os << "("<< comp_num.real << ", " << comp_num.imaginary << "i)\n";
    return os;
}

int main() {
    complex c1(2, -5);
    complex c2(0, 7);
    complex c3(1, 1);
    complex c4(-2, -2);
    std::cout << c1 + c2;    
    std::cout << c1 + c2 - c4;    
    std::cout << c3 - c4;    
    std::cout << c1 * c3;

    return 0;
}