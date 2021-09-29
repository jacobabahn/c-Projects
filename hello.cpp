#include <iostream>

int foo();

int main() {
    int x = 3;
    int b = 5;
    foo();
    std::cout << "HELLO";
}

int foo() {
    std::cout << "BOIO";
    return 6;
}