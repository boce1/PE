/*
Protected members become private in sub-classes and in sub-classes in threir sub-classes
*/

#include <iostream>
using namespace std;

class A {
protected:
    int x = 42; // Protected member
};

class B : public A {
};

class C : public B {
public:
    void accessX() {
        cout << x;
    }
};

int main() {
    C obj;
    obj.accessX();
    return 0;
}