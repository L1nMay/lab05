#include "print.hpp"
#include <iostream> // Нужно для std::cout и std::endl
#include <fstream>  // Нужно для std::ofstream

int add(int a, int b) {
    return a + b;
}

void print(const std::string& text, std::ofstream& out) {
    out << text << std::endl;
}
