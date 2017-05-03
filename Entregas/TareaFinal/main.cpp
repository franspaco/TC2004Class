#include <iostream>

#include "MemManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int* p1 = new int;
    std::cout << "p1: " << p1 << std::endl;

    std::cout << "\nPRE DELETE:" << std::endl;
    delete p1;
    std::cout << "POS DELETE\n" << std::endl;
    delete p1;

    int* p2 = new int[10]; // guaranteed to call the replacement in C++11
    std::cout << "p2: " << p2 << std::endl;
    //delete[] p2;

    clearMem();
    return 0;
}