/*
In C++, a lambda expression (or lambda function) is an anonymous
function you can define inline, typically where you would use a function pointer, 
a simple callback, or a quick function that doesn't need a full function definition. 
Lambda expressions were introduced in C++11 and are especially useful for short, one-off functions, 
often in contexts such as algorithms, event handling, and multi-threading.

Basic Lambda Notation
The general syntax of a lambda function in C++ is:
[capture_list] (parameters) -> return_type { function_body };

[capture_list]: Specifies which variables (from the surrounding scope) 
the lambda can access and whether it should capture them by value or reference.
(parameters): A parameter list for the lambda, similar to a regular function.
-> return_type (optional): Specifies the return type of the lambda. 
This is usually inferred by the compiler, so it's rarely needed for simple cases.
{ function_body }: The function code that the lambda will execute.
*/

/*
Capture Modes
Instead of specifying each variable, you can use capture modes:

[=]: Capture all variables by value.
[&]: Capture all variables by reference.
[=, &var]: Capture all variables by value, but var by reference.
[&, var]: Capture all variables by reference, but var by value.

auto lambda = [=, &y]() {
    // x is captured by value, y by reference
    std::cout << "x: " << x << ", y: " << y << std::endl;
};
*/

#include <iostream>

int main() {
    auto add = [](int a, int b) -> int {return a + b;}; // -> int is not neccessary, complier will make the choice alone
    std::cout << add(5, 9) << std::endl;

    int x = 5;
    auto addToX = [&x](int y) -> int {return x + y;};
    std::cout << addToX(10) << std::endl;

    return 0;
}