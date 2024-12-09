/*

public inheritance:
public remains public
protected remains protected
private from derived class is not accessable

protected inheritance:
public becomes protected
protected remains protected
private from derived class is not accessable

private inheritance:
public and protected become private
private from derived class is not accessable
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