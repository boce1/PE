/*
https://www.geeksforgeeks.org/function-pointer-in-cpp/

name of the function is variable that is assigned to the block of code of the function itself
when we make function pointer we are creating pointer variable that can give us access to the code
it is very useful when we want to call a function with a pointer
the most common use is when pointer to the function is passed as the paramether to another function
array with function pointers can be made

- The function pointer is used to point functions, similarly, the pointers are used to point variables. 
- It is utilized to save a function’s address. 
- The function pointer is either used to call the function or it can be sent as an argument to another function.

syntax:
return_type (*pointer_name) (parameter type, parameter type, ...) = & name_of_pointed_function
NOTE: & is not neccessary because compiler automaticcly give the address of the function when creating a pointer to the function
NOTE: (*funtion_pointer)(parameters) -> * is not neccessary -> funtion_pointer(parameters) 

for class method 
MyClass obj;
void (MyClass::*funcPtr)() = &MyClass::sayHello;
(obj.*funcPtr)(); // Output: Hello from MyClass!
*/

#include <iostream>

int add(const int a, const int b) {
    return a + b;
}

int multiply(const int a, const int b) {
    return a * b;
}

int operatiion(int (*funtion_pointer)(int, int), const int a, const int b) {
    return (*funtion_pointer)(a, b);
}

int main() {
    int (*add_ptr)(int, int) = &add;
    int (*multiply_ptr)(int, int) = &multiply;

    std::cout << (*add_ptr)(5, 4) << std::endl;
    std::cout << (*multiply_ptr)(7,9) << std::endl;

    std::cout << operatiion(add_ptr, 7, 8) << std::endl;
    std::cout << operatiion(multiply_ptr, 3, 7) << std::endl;

    return 0;
}